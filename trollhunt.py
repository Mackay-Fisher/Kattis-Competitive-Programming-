vals = input().split()
vals = list(map(int, vals))
nB = vals[0] -1
nK = vals[1]
nP = vals[2]
numPerDay = nK//nP
days=0
while nB >0:
    nB-=numPerDay
    days+=1
print(days)