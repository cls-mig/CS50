# simulando um loop do while
# em python, um int não tem um tamanho limitado (como em C)

def main():
    i = positiveInt()
    print(i)

def positiveInt():
    while True:
        n = int(input("Digite um número inteiro positivo: "))
        if n > 0:
            break
    return n

main()
