import collections
number = int(input())
busses = input()
bussesArray = busses.split()
bussesArray = list(map(int, bussesArray))
bussesArray.sort()
bussesDict = collections.defaultdict(list)
bus1 = bussesArray[0]
valueHold = bus1
for i in range(1,number):
    if(bus1==(bussesArray[i]-1)):
        bussesDict[valueHold].append(bussesArray[i])
        bus1 = bus1 + 1
    else:
        bus1 = bussesArray[i]
        valueHold = bus1
for val in bussesDict:
    if(len(bussesDict[val])>=2):
        newvals = f"{val}-{bussesDict[val][-1]}"
        insertIndex = bussesArray.index(val)
        bussesArray[insertIndex] = newvals
        for nums in bussesDict[val]:
            bussesArray.remove(nums)
for i in range(len(bussesArray)):
    if i == len(bussesArray)-1:
        print(f"{bussesArray[i]}", end="")
    else:
        print(f"{bussesArray[i]} ", end="")