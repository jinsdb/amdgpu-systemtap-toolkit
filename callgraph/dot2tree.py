#!/usr/bin/python 
import os
import sys
import re

sys.setrecursionlimit(10000)

'''
Input:

test2 = [
  ('t1', 't1_1'),
  ('t1', 't1_2'),
  ('t1_2','t1_2_1'),
  ('t2', 't2_1'),
  ('t2', 't2_2'),
]

Output:

t1
 t1_1
 t1_2
  t1_2_1
t2
 t2_1
 t2_2

'''
list_tree = []
i = 0
def list_formart_order(parentnode, tree, ltree, space_cnt = 0):
    global i
    for x in tree:
        if (space_cnt == 0):
            i = len(ltree)
        if x[0] == parentnode:
            if (len(ltree) == 0):
               ltree.append((space_cnt, x[1]))
               list_formart_order(x[1], tree, ltree, space_cnt + 1)
            else:
               # check a -> b -> c -> d -> a deadloop
               j = 0
               found = 0
               is_end_node = 1
               for j in range(i, len(ltree)):
                  if (ltree[j][1] == x[1] and ltree[j][0] < space_cnt):
                    found = 1
                    for k in tree:
                      if (k[0] == x[1]): # is not end node
                         is_end_node = 0
                         break
               if (found == 1):# touch some trouble? a -> d...z, b -> d...z, b will lost d branch
                  if (is_end_node):
                     ltree.append((space_cnt, x[1]))
               else:   
                  ltree.append((space_cnt, x[1])) #list_tree.append(x)
                  list_formart_order(x[1], tree, ltree, space_cnt + 1)
               #else:
               #   print(x[1])           
               #try:
               #   #list_formart_order(x[1], tree, list_tree, space_cnt + 1)
               #   list_formart_order(x[1], tree, ltree, space_cnt + 1)
               #except:
               #    print(ltree)
               #    #exit()	
               #finally:
               #    print(ltree)
               #    exit()

def print_formart_list(tree):
   l_depth = -1
   for x in tree:
      depth = x[0]
      func  = x[1]
      if (l_depth == depth):
         print(depth*'  ' + '}')
         print(depth*'  ' + func + '(){') 
      elif (depth < l_depth):
         for i in reversed(range(depth, l_depth + 1)):
            print(i*'  ' + '}')
         print(depth*'  ' + func + '(){') 
      else:
         print(depth*'  '+ func + '(){')
      l_depth = depth
   if (l_depth > 0):
      for i in reversed(range(l_depth + 1)):
        print(i*'  ' + '}')
'''        
def check_dead_loop(a_list, b_list):
    i = 0
    for item in a_list:
        if item in b_list[i:]:
            print(a_list[i], b_list[i])
        i += 1

'''
'''
1. remove a -> a, deep loop
2. remove duplicate lines from C++filt -pi
'''
def list_purify(list):
    move = []
    for x in list:
      if x[0] == x[1]:
        move.append(x)
    for x in move:
        list.remove(x)
    #remove duplicate lines
    del move[:]
    for i in list:
      if i not in move:
        move.append(i)
    #list = move[:]
    return move

'''
insert default root
'''
def list_add_default_root(list):
    alist = []
    blist = []
    for x in list:
        alist.append(x[0])
        blist.append(x[1])
    i = 0
    for x in list:
        a = x[0]
        b = x[1]
        if a not in blist and ('0', a) not in list:
            list.insert(i, ('0', a))
            i += 1

if len(sys.argv) < 2:
    print(sys.argv[0] + " <dotfile> ")
    exit()

fname = sys.argv[1]

flist = []

f = open(fname, "r")
lines = f.readlines()
for line in lines:
    if line.find('->') > 0:
        line = line.strip().rstrip(';')
        #if line.endswith(';'): line = line[:-2]
        str = line.split('->')
        text1 = str[0].strip().strip('"')
        text2 = str[1].strip().strip('"')
        flist.append((text1, text2))
f.close()


list = list_purify(flist)
#print(list)
#exit()
list_add_default_root(list)
try:
  list_formart_order('0', list, list_tree)
except KeyboardInterrupt:
  print_formart_list(list_tree)
print_formart_list(list_tree)
