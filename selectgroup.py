import collections
groups = collections.defaultdict(list)
inputLines = []
output = []
while True:
    try:
        vals = input()
        if vals == "-1":
            break
        inputLines.append(vals)
    except:
        break
       
for i in range(len(inputLines)):
    currentLine = inputLines[i].split()
    if currentLine[0]=="group":
        newset = set()
        for j in range(3,int(currentLine[2])+3):
           newset.add(currentLine[j])
        groups[currentLine[1]].append(newset)
    else:
        setStack = []
        for element in reversed(currentLine):
            if element in ["union", "difference", "intersection"]:
                set1,set2 = setStack.pop(),setStack.pop()
                if element == "union":
                    setStack.append(set1.union(set2))
                elif element == "difference":
                    setStack.append(set1.difference(set2))
                elif element == "intersection":
                    setStack.append(set1.intersection(set2))
            else:
                setStack.append(groups[element][0])
        if setStack:
            output.append(setStack[0])
        else:
            output.append['empty']
for v in output:
    if v == 'empty':
        print()
        continue
    newOuput = []
    for c in v:
        newOuput.append(c)
    newOuput.sort()
    for a in newOuput:
        print(f"{a} ",end='')
    print()