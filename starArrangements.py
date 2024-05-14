numStarts = int(input())
outputs = set()
for i in range(2,numStarts):
    num1 = i + (i-1)
    # num2 = i + (i+1)
    num3 = i+i
    # print(num1,num2,numStarts%num1,numStarts%num2,numStarts)
    if numStarts%num1 == i or numStarts%num1 == 0:
        outputs.add((i,i-1))
    # if numStarts%num2 == i or numStarts%num2 == 0:
    #     outputs.add((i,i+1))
    if numStarts%num3 == i or numStarts%num3 == 0:
        outputs.add((i,i))
arr = []
for val in outputs:
    arr.append(val)
arr.sort()
print(f"{numStarts}:")
for val in arr:
    x,y = val
    print(f"{x},{y}")