import math
vals = input()
vals = vals.split()
lineNums = int(vals[0])
minMoney = int(vals[1])
arr = []
for i in range(lineNums):
    v = input()
    v = v.split()
    rate = int(v[0])/int(v[1])
    cost = int(v[1])
    profit = int(v[0])
    arr.append((rate,cost,profit))
arr.sort(reverse=True)
# print(arr)
totalpay = 0
totalProf = 0
totaldays = float('inf')
usedCost = []
for a in arr:
    r, c, p = a
    totalProf += p
    totalpay += c
    totaldays=min(totaldays,(minMoney + totalpay)/totalProf)
print(math.ceil(totaldays))