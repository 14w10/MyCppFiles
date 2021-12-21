# Thanks to ALICE

import sys

lines = []
for line in sys.stdin:
    if line.strip() == '':
        break 
    lines.append(line)

cownum = int(lines[0])
cowtype = lines[1].strip()

g, h, gind, hind = -1, -1, -1, -1
photos = 0

for i in range(cownum):
    if cowtype[i] == 'G':
        gind = g
        g = i
    
    else:   
        hind = h
        h = i
    
    ind = min(gind, hind) + 1
    r = i - ind + 1
    if r < 3:
        continue
    photos += (r-2)

ex = cowtype[0]
num = 1

for j in range(1, cownum):
    if cowtype[j] == ex:
        num += 1
    
    else:
        if num >= 3:
            r = int((num - 1)*(num - 2)/2)
            photos = photos - r
        
        ex = cowtype[j]
        num = 1

if num >= 3:
    r = int((num - 1)*(num - 2)/2)
    photos = photos - r
        
sys.stdout.write(str(photos))
