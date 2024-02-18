import csv
from sys import argv

# Exercício 6 - DNA
'''
- as pessoas tem um STR repetido uma certa quantia de vezes (varia de pessoas para pessoa)
- len() para pegar o comprimento de uma string

- s[i:j]
    - em Python, s[i:j] é uma notação utilizada para acessar uma parte de uma sequência s, como uma string, lista ou tupla, entre o índice i (inclusive) e o índice j (exclusive). Aqui está uma explicação mais detalhada:
    s: É a sequência da qual você está acessando uma parte. Pode ser uma string, lista, tupla ou qualquer outro tipo de sequência em Python.
    i: É o índice de início da parte que você deseja acessar. Este índice é inclusivo, o que significa que o elemento na posição i estará incluído na parte retornada.
    j: É o índice de fim da parte que você deseja acessar. Este índice é exclusivo, o que significa que o elemento na posição j não estará incluído na parte retornada.
        s = "Python"
        print(s[1:4])
        yth

- criar um dicionário, onde eu tenho uma chave sendo a sequeência str determinada e o seu valor (quantidade) relacioandas
    STR = {
        "AGATC": 4,
        "AATG": 2,
        ...
    }
'''
# um dicionário, onde eu tenho o str e a sua quantidade relacioandas
# empty - vazio(a)
STR = {

    }

def main():
    if (len(argv) != 3):
        print("Uso: python nome_do_script.py arquivo_csv arquivo_txt")

    with open(f"dna/databases/{argv[1]}", mode="r") as databases:
        # file = databases.read()
        table = csv.reader(databases) # cria um leitor CSV
        colunas = next(table) # next lê a primeira linha do arquivo que contém os nomes das colunas
        
        c = 0
        for coluna in colunas:
            if (c >= 1):
                valor = readerSequences(coluna)
                # print(f"{coluna} - {valor}")
                STR[coluna] = valor # as chaves desse dicionário são os nomes das colunas onde será associada um valor, sendo esse valor o número de vezes que essa coluan aparece na sequência do arquivo txt
            c += 1 # registra o número de colunas
        
        # print(STR)
        
        # next(table) # pula a primeira linha (cabeçalho)
        data = list()
        value = list()

        for valor in STR.values(): # iterar sobre os valores da estrutura (dicionário)
            value.append(valor)

        for linha in table: # percorre cada linha de table
            # s[i:j] - j não estará incluído na parte retornada
            # linha_seg = linha[1:] # significa que ele irá atribuir da segunda linha em diante e da segunda coluna em diante
            for i in range(1, c): # percorre cada coluna da linha de table
                data.append(int(linha[i:i + 1][0]))
            if (data == value):
                print(linha[0:1][0])
                return 0
            data = []
        print("Sem correspondência")

def readerSequences(seq):
    qtd_seq = 0
    vet_qtd = list()
    with open(f"dna/sequences/{argv[2]}", "r") as sequences: # variável que receve o conteúdo do aquivo.txt
    # with open(f"{test/argv[2]}", "r") as sequences:
        genoma = sequences.read()
        for i in range(0, len(genoma)): # pegar o comprimento de uma string
            if (genoma[i:i + len(seq)] == seq): # o for anda uma casa mais três casas à frente
                while (genoma[i:i + len(seq)] == seq):
                    qtd_seq += 1
                    i += len(seq)
                vet_qtd.append(qtd_seq) # valor que vai adicionar por último
            qtd_seq = 0
            '''
            else:
                qtd_vet = 0
            '''
        # print(sequencia) # sequência do genoma
    if vet_qtd: # verifica se vet_qtd não está vazio
        return max(vet_qtd)
    else:
        return 0
main()
