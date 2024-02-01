# dicionários em Python são semelhantes a estruturas (structs) em C
# um dicionário é uma coleção de pares de valores-chave
'''
peaple = {
    "Carlos": "(21) 9 7231-0436",
    "Gabriel": "(21) 9 6707-2434"
}

name = input("Nome: ")
if name in peaple:
    print(f"Número: {peaple[name]}")
'''
import csv

# file = open("phonebook.csv", "a")
with open("phonebook.csv", "a") as file: # fecha o arquivo para mim automaticamente

    name = input("Nome: ")
    number = input("Number: ")

    writer = csv.writer(file)
    writer.writerow([name, number])

# file.close()
