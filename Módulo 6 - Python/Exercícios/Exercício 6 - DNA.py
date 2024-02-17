import csv
from sys import argv

# Exercício 6 - DNA
'''
- as pessoas tem um STR repetido uma certa quantia de vezes (varia de pessoas para pessoa)
- len() para pegar o comprimento de uma string
- s[i:j]
- criar um dicionário, onde eu tenho uma chave sendo a sequeência str determinada e o seu valor (quantidade) relacioandas
    STR = {
        "AGATC": 4,
        "AATG": 2
        ...
    }
'''
# um dicionário, onde eu tenho o str e a sua quantidade relacioandas
STR = {

    }
def main():
    if (len(argv) != 3):
        print("Uso: python nome_do_script.py arquivo_csv arquivo_txt")

    with open(f"dna/databases/{argv[1]}", mode="r") as databases:
        # file = databases.read()
        file = csv.reader(databases) # cria um leitor CSV
        colunas = next(file) # next lê a primeira linha do arquivo que contém os nomes das colunas
        index = 0

        for coluna in colunas:
            if (index >= 1):
                # print(coluna)
                valor = readerSequences(coluna)
                STR[coluna] = valor # as chaves desse dicionário são os nomes das colunas onde será associada um valor, sendo esse valor o número de vezes que essa coluan aparece na sequência do arquivo txt
            index += 1

    # print(file)

def readerSequences(str):
    with open(f"dna/sequences/{argv[2]}", "r") as sequences:
        sequencia = sequences.read()
    

# print(sequencia) # sequência do genoma
main()
