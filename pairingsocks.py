aux = []
numsocks = int(input())
socks = input().split()
s = list(map(int, socks))
moves = 0
while s:
    if len(aux)==0:
        aux.append(s[len(s)-1])
        s.pop()
        moves+=1
    if aux[len(aux)-1] == s[len(s)-1]:
        aux.pop()
        s.pop()
        moves+=1
    else:
        if len(s)!=0:
            aux.append(s[len(s)-1])
            s.pop()
            moves+=1
        else:
            print('impossible')
            exit()

if len(aux)!=0:
    print('impossible')
    exit()


print(moves)