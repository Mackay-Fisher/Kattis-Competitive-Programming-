import collections
dice = input()
dice = dice.split()
die1 = int(dice[0])
die2 = int(dice[1])
count = collections.defaultdict(int)
for i in range(1,die1+1):
    for j in range(1,die2+1):
        val = i + j
        count[val]+=1
localMax = 0
for val in count:
    localMax = max(localMax,count[val])
maxArray = []
for val in count:
    if(count[val]==localMax):
        maxArray.append(val)

for i in range(len(maxArray)):
    print(maxArray[i])