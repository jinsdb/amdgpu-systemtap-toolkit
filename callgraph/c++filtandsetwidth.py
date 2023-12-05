#!/usr/bin/python 
import os
import sys
import re

fhead = []
flist = []
ftail = []

def wrap_text(text, slen):
    str = ""
    i = 0
    for letter in text:
        if i >= slen and letter != ' ' and\
          letter != '"' and letter != ';':
            str = str + letter + "\\n"
            i = 0
        else:
            str = str + letter
        i = i + 1
    return str 


if len(sys.argv) < 2:
    print(sys.argv[0] + " <dotfile>")
    exit()
    
fname = sys.argv[1]
cmd = "c++filt -pi < {} > /tmp/tmp2.dot".format(fname)
os.system(cmd)

f = open("/tmp/tmp2.dot", "r")   

lines = f.readlines()
for line in lines:
    #line = line.strip()
    line = line.strip().rstrip(';')
    if line.find('->') > 0: 
        str=line.split('->')
        #TODO: special handle c++ 'std::_Function_handler'
        if 'std::_Function_handler' not in str[0]:
            # delete all "<...<...> ..>" from c++ demangled name
            pattern=re.sub(u"\\<.*\\>", "", str[0])
            text1 = pattern #wrap_text(pattern, 35)
        else:
            text1 = str[0]

        if 'std::_Function_handler' not in str[1]:
            # delete ...
            pattern=re.sub(u"\\<.*\\>", "", str[1])
            text2 = pattern #wrap_text(pattern, 35)
        else:
            text2 = str[1]

        #print("%s -> %s" % (text1, text2))
        flist.append((text1, text2)) 
    elif len(flist) == 0:
        fhead.append(line)
    else:
	ftail.append(line) 
    #else:print(line)
        
f.close()

collect_data = []
# special handle c++ 'std::_Function_handler'
i = 0
for (t1, t2) in flist:
    if 'std::_Function_handler' in t2:
       j = 0
       for (a, b) in flist:
          if a == t2: 
             #print("%s->%s replace by %s -> %s"%(t1, t2, t1, b))
             flist[i] = (t1, b)
             #flist[j] = ("", "") # delay remove (a, b)
             if (a, b) not in collect_data: # avoid repeating element 
                collect_data.append((a, b))
             break  #only one record
          j += 1
       if j == len(flist): #not found
          pattern=re.sub(u"\\<.*\\>", "", t2)
          flist[i] = (t1, pattern)
    i += 1

#for (a, b) in flist[:]:
#   if (a, b) == ("", ""):
#       flist.remove(("", ""))
for (a , b) in collect_data:
   flist.remove((a, b))

for htext in fhead:
   print(htext.strip())

for (a, b) in flist:
   print("%s -> %s" % (a, b))

for ftext in ftail:
   print(ftext.strip())
