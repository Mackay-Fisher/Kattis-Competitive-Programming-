number = int(input())
answersList = []
for i in range(number):
    answer = input()
    answersList.append(answer)
count = 0
firstVal = answersList[0]
for i in range(1,number):
    if(firstVal == answersList[i]):
        count = count + 1
    firstVal = answersList[i]
print(count)