import collections
input()
d = collections.defaultdict(int)
v = input().split()
s = list(map(int, v))
if(len(s)==1):
    print(1)
    exit()
for a in s:
    d[a]+=1
value = d[s[1]]
size = 0
for a in d:
    if d[a]!=value:
        break
    size+=1
if(size==len(d) and value != 1):
    print('none')
    exit()
minVal = float('inf')
for a in d:
    minVal = min(d[a],minVal)
if minVal!=1:
    print('none')
    exit()
maxVal = float('-inf')
for a in d:
    if d[a]==minVal:
        maxVal = max(maxVal,a)
index=1
for a in s:
    if a == maxVal:
        print(index)
        break
    index+=1