import math
number = int(input())
stringArray = []
#L is the length  of the text 
for i in range(number):
    message = input()
    messL = len(message)
    rowsNumber = math.ceil(math.sqrt(messL))
    encode = [['*']* rowsNumber for i in range(rowsNumber)]
    decode = [['*']* rowsNumber for i in range(rowsNumber)]
    valIndex = 0
    for i in range(rowsNumber):
        for j in range(rowsNumber):
            if(valIndex == len(message)):
                break
            encode[i][j] = message[valIndex]
            valIndex = valIndex + 1 
    for i in range(rowsNumber):
        for j in range(rowsNumber):
            decode[j][rowsNumber -1 - i] = encode[i][j]
    decodestring = ""
    for val in decode:
        for c in val:
            if(c!='*'):
                decodestring+=c
    stringArray.append(decodestring)
for s in stringArray:
    print(s)