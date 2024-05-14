import collections
validTeams = []
dictVals = collections.defaultdict(int)
while(True):
    inputLine = input()
    if inputLine == "-1":
        break
    valsArray = inputLine.split()
    seconds = valsArray[0]
    team = valsArray[1]
    result = valsArray[2]
    if result == "right":
        validTeams.append(team)
        if team in dictVals.keys():
            dictVals[team] = int(seconds) + dictVals[team]
        else:
            dictVals[team] = int(seconds)
    else:
        if team in dictVals.keys():
            dictVals[team] = dictVals[team] + 20
        else:
            dictVals[team] = 20
        

total = 0
for key in validTeams:
    total += dictVals[key]
print(f"{len(validTeams)} {total}")