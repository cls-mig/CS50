'''
- bancos de dados relacionais não são somente para armazenar dados e relacioná-los, envolve também a forma mais eficiente de inserir, atualizar, pesquisar e excluir esses dados
- o que diferencia de planilhas e tabelas comuns (CSV, Excel, Planilhas Google, etc.)
- SQL - Linguagem de Consulta Estruturada (Structure Query Language)
    SQLite - uma versão mais leve do SQL (usa um arquivo único em binário)
'''
import csv

title = input("Ttitle: ").strip().upper() # canonizar

with open("Fatorete TV Shows - Form Responses 1.csv", "r") as file:
    reader = csv.DictReader(file)
    counter = 0
    # Bio O de n, já que é usado somente um pesquisa linear
    for row in reader:
        if row["title"].strip().upper() == title:
            counter += 1

print(counter)
