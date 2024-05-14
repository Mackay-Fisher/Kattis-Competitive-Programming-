v = input()
v = v.split()
s = input()
s = s.split()
s = list(map(int, s))
s.sort()
numships = int(v[1])
count = 0
index = 0
for val in s:
    numships -= (val+1)
    if numships < 0:
        break
    else:
        count+=1
print(count)