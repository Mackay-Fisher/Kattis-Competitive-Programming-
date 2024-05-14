inputLine = input()
inputLine = inputLine.split()
p = int(inputLine[0])
b = int(inputLine[1])
h = int(inputLine[2])
w = int(inputLine[3])
costsArray = []
for i in range(h):
    price = int(input())
    aval = input()
    aval = aval.split()
    for i in range(len(aval)):
        if(int(aval[i])>=p):
            val = b - price*p
            if(val>=0):
                costsArray.append(b-val)
if(len(costsArray)>0):
    costsArray.sort()
    print(costsArray[0])
else:
    print("stay home")