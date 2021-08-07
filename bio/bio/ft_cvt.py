import re

output_file = 'read.txt.c'

input_file = 'read.txt'


input = open(input_file, 'rb')
output = open(output_file, 'wb')

for line in input:
    m = re.match('^ .(?P<cpu>[0-9]).{3}(?P<duration>.*) *\| (?P<message>.*)', line)
    if(not m):
        continue
    #print m.group('cpu'), m.group('duration'), m.group('message')
    output.write(m.group('message') + "//" + m.group('duration') + "\n")