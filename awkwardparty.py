import collections
num = int(input())
dict = collections.defaultdict(int)
values = input().split()
s = list(map(int, values))
ret = len(s)
l = float('inf')
for i,val in enumerate(s):
    if val not in dict:
        dict[val] = i
    else:
        l = min(l,i-dict[val])
if l != float('inf'):
    print(l)
else:
    print(ret)