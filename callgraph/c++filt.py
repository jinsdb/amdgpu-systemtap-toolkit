#!/usr/bin/python 
import os
import sys
import re

if len(sys.argv) < 2:
    print(sys.argv[0] + " <dotfile>")
    exit()

fname = sys.argv[1]
cmd = "c++filt -pi < {} > /tmp/tmp2.dot".format(fname)
os.system(cmd)

f = open("/tmp/tmp2.dot", "r")   

lines = f.readlines()
for line in lines:
    line = line.strip("\n")
    pattern=re.sub(u"\\<.*\\>", "", line)
    print("%s" % pattern)
    
f.close()

