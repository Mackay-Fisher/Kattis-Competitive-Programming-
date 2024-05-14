stringToCheck = input()
whiteSpace = 0
lowercase = 0
upercase = 0
symbols = 0
chars = 0
for c in stringToCheck:
    if c>= 'A' and c<='Z':
        upercase+=1
    elif c>='a' and c<='z':
        lowercase+=1
    elif c == '_':
        whiteSpace+=1
    else:
        symbols+=1
    chars+=1

whiteSpace = whiteSpace/chars
lowercase = lowercase/chars
upercase = upercase/chars
symbols = symbols/chars
print(whiteSpace)
print(lowercase)
print(upercase)
print(symbols)