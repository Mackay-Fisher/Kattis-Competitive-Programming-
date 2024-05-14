rail = input()
rail = rail.split()
x = int(rail[0])
y = int(rail[1])
xsides = 0
ysides = 0
for i in range(x):
    xsides +=4
for i in range(y):
    ysides+=3
total = xsides + ysides
if total %2 ==0:
    print("possible")
else:
    print("impossible")