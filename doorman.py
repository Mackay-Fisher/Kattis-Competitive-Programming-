diffAllowed = int(input())
string = input()
holding = []
diff = 0
m = 0
w = 0
total = 0
for char in string:
    if char == 'M':
        if m-w < diffAllowed:
            m+=1
            total+=1
        else:
            if holding and holding[0]=='W':
                w+=1
                total+=1
                m+=1
                total+=1
                holding.pop()
                break
            if not holding:
                holding.append('M')
            else:
                break
    if char == 'W':
        if w-m < diffAllowed:
            w+=1
            total+=1
        else:
            if holding and holding[0]=='M':
                m+=1
                total+=1
                w+=1
                total+=1
                holding.pop()
                break
            if not holding:
                holding.append('W')
            else:
                break
if holding:
    if holding[0]=='W' and w-m < diffAllowed:
        total+=1
    if holding[0]=='M' and m-w < diffAllowed:
        total+=1
print(total)