numToCount = int(input())
numbers = input()
numarray = numbers.split()
sumval = 0
for i in range(numToCount):
    sumval = sumval + int(numarray[i])

print(sumval)