minV = int(input())
vals = input().split()
vals = list(map(int, vals))
vals.sort()
n = len(vals)
for i in reversed(range(n)):
    minV = min(minV,n-(i+1)+vals[i])

print(minV)