def main():
    height = int(input("Height: "))
    # Como verifcar se o input do usuário é válido? (um número inteiro entre 1 e 8)
    '''
    
    '''
    construtor(height)

def construtor(alt):
    for i in range(alt, 0, -1): # de valores maiores para valores menores é necessário colocar o passo, ou seja, o decremento
        for j in range(i, 1, -1):
            print(" ", end="")
        for k in range((alt + 1) - i):
            print("#", end="") # end="" é responsável por alterar esse comportamento, possibilitando ao desenvolvedor trocar qual caracter será adicionado ao final do dado impresso no terminal
        print()

main()
