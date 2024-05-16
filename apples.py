grid = input().split()
h = int(grid[0])
r = int(grid[1])
apples = []
for i in range(h):
    row = input()
    apples.append(list(row))

lowest = []
for i in range(r):
    lowest.append(h-1)

for j in range(h-1,-1,-1):
    for i in range(r):
        if apples[j][i] == 'a':
            apples[lowest[i]][i]='a'
            if lowest[i]!=j:
                apples[j][i]='.'
            lowest[i]-=1
        elif apples[j][i]=='#':
            lowest[i]=j-1
                
# print(apples)
for row in apples:
    print(''.join(row))