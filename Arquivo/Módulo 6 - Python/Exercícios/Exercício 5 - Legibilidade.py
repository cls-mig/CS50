# Exercício 5 - Legibilidade
'''
0.0588 * L - 0.296 * S - 15.8 , onde L é o número médio de letras por 100 palavras no texto e S é o número médio de sentenças por 100 palavras no texto
'''
def main():
    text = input("Text: ")
    letras = 0
    palavras = 0
    sentencas = 0
    # acho que tem como fazer uma verificação melhor que essa...
    for caractere in text:
        if (caractere.isalpha()): # verifica se são caracteres alfabéticos (letras)
            letras += 1
        elif (caractere.isspace()): # se o caractere não é letra e nem espaço, pode ser qualquer outro caractere especial
            palavras += 1
        elif (caractere == '.' or caractere == '?' or caractere == '!'):
            sentencas += 1
    '''
    print(f"Quantidade de letras: {letras}")
    print(f"Quantidade de palavras: {palavras}")
    print(f"Quantidade de frases: {sentencas}")
    '''
    L = (letras / palavras) * 100
    S = (sentencas / palavras) * 100
    # Índice Coleman-Liau
    grade = (0.0588 * L) - (0.296 * S) - 15.8
    
    if (grade >= 16):
        print("Grade 16+")
    elif (grade < 1):
        print("Before Grade 1")
    else:
        # print(f"Grade {format(grade, ".0f")}")
        # print("Grade {:.0f}".format(grade))
        print(f"Grade {grade:.0f}") # como imprimir (ou não) casas decimais "personalizadas"
main()
