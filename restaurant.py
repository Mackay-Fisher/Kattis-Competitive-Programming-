Output = []
OptionNumber = 0
PlatesStored1 = 0
PlatesStored2 = 0
while(True):
    InpString = input()
    if(InpString == "0"):
        break
    Vals = InpString.split()
    if Vals[0]!="DROP" and  Vals[0]!="TAKE":
        OptionNumber = int(Vals[0])
    else:
        OptionNumber = OptionNumber - 1
        if(Vals[0]=="DROP"):
            PlatesStored2 = PlatesStored2 + int(Vals[1])
            Output.append(f"DROP 2 {int(Vals[1])}")
            # print("DROP 2",Vals[1])
        if(Vals[0]=="TAKE"):
            if(PlatesStored1 >= int(Vals[1])):
                PlatesStored1 = PlatesStored1 - int(Vals[1])
                Output.append(f"TAKE 1 {int(Vals[1])}")
                # print("TAKE 1 ",Vals[1])
            else:
                # PlatesStored2 = 0
                initial = PlatesStored1
                rem = int(Vals[1]) - PlatesStored1
                if initial > 0:
                    Output.append(f"TAKE 1 {initial}")
                # print("TAKE 1 ",)
                PlatesStored1 = PlatesStored2
                # print("MOVE 2->1 ",PlatesStored2)
                Output.append(f"MOVE 2->1 {PlatesStored2}")
                PlatesStored2 = 0
                # print("TAKE 1 ",rem)
                if rem > 0:
                    Output.append(f"TAKE 1 {rem}")
                PlatesStored1 = PlatesStored1 - rem
        if(OptionNumber==0):
            PlatesStored2 = 0
            PlatesStored1 = 0
            Output.append("jump")

for i in range(len(Output)):
    if(i==len(Output)-1):
        break
    if Output[i] == "jump":
        print()
    else:
        print(Output[i])