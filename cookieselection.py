import heapq
stackMin = []
stackMax = []
while True:
    try:
        vals = input()
        if vals == "-1":
            break
        if vals == "#":
            if(len(stackMin)>len(stackMax)):
                print(-1 * stackMin[0])
                heapq.heappop(stackMin)
            elif(len(stackMax)>len(stackMin)):
                print(stackMax[0])
                heapq.heappop(stackMax)
            else:
                print(stackMax[0])
                heapq.heappop(stackMax)
        else:
            vals = int(vals)
            heapq.heappush(stackMin,-vals)
            if(stackMax and stackMin and stackMin[0] * -1 >= stackMax[0]):
                num = heapq.heappop(stackMin)
                heapq.heappush(stackMax,-num)
            if(len(stackMax) > len(stackMin)+1):
                num = heapq.heappop(stackMax)
                heapq.heappush(stackMin,-num)
            if(len(stackMin) > len(stackMax)+1):
                num = heapq.heappop(stackMin)
                heapq.heappush(stackMax,-num)
    except:
        break
