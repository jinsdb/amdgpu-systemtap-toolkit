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
    #pattern=re.sub(u"\\<.*\\>", "", line)
    #print("%s" % pattern)
    str = line.split('->')
    if (len(str) < 2):
       print(line)
       continue
    text1 = re.sub(u"\\<.*\\>", "", str[0])
    text2 = re.sub(u"\\<.*\\>", "", str[1])
    print("%s -> %s"%(text1, text2))    

f.close()

