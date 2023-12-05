#!/usr/bin/python 
import os
import sys
import re
from collections import Counter;

fhead = []
flist = []
ftail = []
texta = []
textb = []

if len(sys.argv) < 2:
    print(sys.argv[0] + " <dotfile>")
    exit()
    
fname = sys.argv[1]

f = open(fname, "r")
lines = f.readlines()
for line in lines:
    if line.find('->') > 0:
        line = line.strip().rstrip(';')
        #if line.endswith(';'): line = line[:-2]
        str = line.split('->')
	text1 = str[0].strip()
	text2 = str[1].strip() 
	texta.append(text1)
	textb.append(text2)
        flist.append((text1, text2))
    elif len(flist) == 0:
        fhead.append(line)
    else:
	ftail.append(line)      
f.close()

dictb = Counter(textb)
for key in dictb:
    if ((dictb[key] > 1) and (texta.count(key) <= 0)):
        i = 0
        j = 0
        for (a, b) in flist:
            if (b == key):
               dupnode = 0
               for k in range(i):
                   newstr = flist[k][1].replace(' ', '') #strip space
                   if (flist[k][0], newstr) == (a, b):  
                      newb = flist[k][1]
                      dupnode = 1 
		      break
               if dupnode == 0:
                  if b.endswith('"'): b = b[:-1]
                  newb = b + j*' ' + '"'
                  j = j + 1
               flist[i] = (a, newb)
            i = i + 1

for htext in fhead:
   print(htext.strip())

color = ["red", "orange", "greenyellow", "green", "blue", "indigo", "purple", "pink", "black","brown"]
s={}
for (a, b) in flist:
   if a in s.keys():
       s[a] += 1
   else:
       s[a] = 1
   cnt = s[a] - 1
   print("%s -> %s [label=%d,color=%s]" % (a, b, cnt + 1, color[cnt%len(color)]))

for ftext in ftail:
   print(ftext.strip())
 
