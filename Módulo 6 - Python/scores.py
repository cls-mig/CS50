'''
scores = [72, 73, 33]

print("Average: " + str(sum(scores) / len(scores)))
'''

scores = []
for i in range(3):
        scores.append(int(input("Score: "))) # define o tamanho da lista dependendo do número de elementos contido nele

average = sum(scores) / len(scores)
print(f"Avegare: {average}")
