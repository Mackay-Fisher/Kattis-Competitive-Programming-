import collections
i = input()
i = i.split()
numJudges = int(i[0])
numScores = int(i[1])
sum = 0
for i in range(numScores):
    sum = sum + int(input())
min = sum
max = sum
for i in range(numJudges-numScores):
    min = min -3
    max = max + 3

min = min/numJudges
max = max/numJudges
print(min,max)