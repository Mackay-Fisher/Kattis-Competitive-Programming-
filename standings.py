testCases = int(input())
_= input()
outputArr = []
for i in range(testCases):
    numTeams = int(input())
    diff = 0
    numarray = []
    for j in range(numTeams):
        team = input()
        team = team.split()
        numarray.append(team[1])
    numarray = list(map(int, numarray))
    numarray.sort()
    for z in range(numTeams):
        diff+=abs((z+1)-int(numarray[z])) 
    outputArr.append(diff)
    if i == testCases-1:
        break
    _ = input()

for val in outputArr:
    print(val) 