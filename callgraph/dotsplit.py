#!/usr/bin/python 
import os
import sys
import re

sys.setrecursionlimit(10000)

fhead = []
flist = []
ftail = []

if len(sys.argv) < 3:
    print(sys.argv[0] + " <dotfile> <rootnode> [-d]")
    exit()
    
fname = sys.argv[1]
rootfunc = sys.argv[2]

splitparent = 0
if ((len(sys.argv) == 4) and (sys.argv[3] == '-d')):
   splitparent = 1

f = open(fname, "r")
lines = f.readlines()
for line in lines:
    if line.find('->') > 0:
        line = line.strip().rstrip(';')
        #if line.endswith(';'): line = line[:-2]
        str = line.split('->')
	text1 = str[0].strip()
	text2 = str[1].strip()
        flist.append((text1, text2))
    elif len(flist) == 0:
        fhead.append(line)
    else:
	ftail.append(line)      
f.close()

newdot = []
def lookuptree(root):
  #print("lookup root: %s" % (root))
  i = 0
  for (x, y) in flist:
    if (x == root):
        newdot.append((x, y))
        # Break the dead loop: a -> b,...., b -> a
        #if (newdot.count((y,x)) < 1):
        flist[i] = ("", "")
        lookuptree(y)
    i += 1

#for (x, y) in flist:
#    print(x, y)

lookuptree(rootfunc)


for htext in fhead:
   print(htext.strip())

for (a, b) in newdot:
   print("%s -> %s" % (a, b))

for ftext in ftail:
   print(ftext.strip())

#print("orig dot len:%d"%len(flist))

if splitparent:
   for (x, y) in flist[:]:
      if (x, y) == ("", ""):
        flist.remove((x, y))

   f = open(fname, "w")

   for htext in fhead:
       f.writelines(htext.strip() + "\n")

   for (a, b) in flist:
       f.writelines("{} -> {}\n".format(a, b))
   
   for ftext in ftail:
       f.writelines(ftext.strip() + "\n")
  
   f.close()

#print("parent dot len:%d, new dot len: %d"%(len(flist), len(newdot)))
