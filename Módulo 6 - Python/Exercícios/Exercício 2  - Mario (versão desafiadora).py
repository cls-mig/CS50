# ainda não gosto desse código (dessa minha resolução), tanto em C quanto em Python parece sujo
def main():
    height = int(input("Height: "))
    # Como verifcar se o input do usuário é válido? (um número inteiro entre 1 e 8)
    '''
    
    '''
    construtor(height)

def construtor(alt):
    n = 0
    for i in range(alt, 0, -1):
        for j in range(i, 1, -1):
            print(" ", end="")
        for k in range((alt + 1) - i):
            print("#", end="")
            n += 1
        n = espaco(n)

def espaco(valor):
    print(" ", end="")
    for i in range(valor):
        print("#", end="")
    print()

    return 0

main()
