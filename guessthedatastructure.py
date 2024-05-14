import queue
import collections
inputLines = []
testCases = []
testcase = 0
while True:
    try:
        vals = input()
        if vals == "-1":
            break
        val = vals.split()
        if(len(val)==1):
            if(testcase > 0):
                testCases.append(inputLines)
                inputLines = []
            testcase+=1
        elif len(val)==2:
            inputLines.append(vals)
    except:
        break
if(inputLines):
    testCases.append(inputLines)

for i in range(len(testCases)):
    ts = collections.deque()
    tpq =queue.PriorityQueue()
    tq = queue.Queue()
    iss,ispq,isq,impossible = True,True,True,False
    for j in range(len(testCases[i])):
        opperation,value = testCases[i][j].split()
        value = int(value)
        opperation = int(opperation)
        if opperation == 1:
            ts.append(value)
            tq.put(value)
            tpq.put(-value)
        if opperation == 2:
            if ts and tq and tpq:
                tsv,tsqv,tspqs = ts.pop(),tq.get(),-tpq.get()
            else:
                impossible = True
                break
            if tsv != value:
                iss=False
            if tsqv != value:
                isq = False
            if tspqs !=value:
                ispq = False
    if(not iss and not ispq and not isq):
        print('impossible')
    elif(iss and not ispq and not isq):
        print('stack')
    elif(not iss and ispq and not isq):
        print('priority queue')
    elif(not iss and not ispq and isq):
        print('queue')
    elif(not iss and not ispq and not isq):
        print('impossible')
    elif(impossible):
        print('impossible')
    else:
        print('not sure')