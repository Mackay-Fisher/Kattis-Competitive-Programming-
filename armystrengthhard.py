listResponses = []
number = int(input())
for i in range(number):
    array = []
    _ = input()
    _ = input()
    GodzillaArmy = input()
    GodzillaArmy = GodzillaArmy.split()
    MechGodzillaArmy = input()
    MechGodzillaArmy = MechGodzillaArmy.split()
    GodzillaArmy = list(map(int, GodzillaArmy))
    MechGodzillaArmy = list(map(int, MechGodzillaArmy))
    GodzillaArmy.sort(reverse=True)
    MechGodzillaArmy.sort(reverse=True)
    while(GodzillaArmy!=[] and MechGodzillaArmy!=[]):
        if(GodzillaArmy[-1]<MechGodzillaArmy[-1]):
            GodzillaArmy.pop()
        elif(GodzillaArmy[0]>MechGodzillaArmy[-1]):
            MechGodzillaArmy.pop()
        elif(GodzillaArmy[0]==MechGodzillaArmy[-1]):
            MechGodzillaArmy.pop()
    if(GodzillaArmy==[]):
        listResponses.append("MechaGodzilla")
    if(MechGodzillaArmy==[]):
        listResponses.append("Godzilla")
    if(GodzillaArmy==[] and MechGodzillaArmy==[]):
        listResponses.append("uncertain")
        
for val in listResponses:
    print(val)
    