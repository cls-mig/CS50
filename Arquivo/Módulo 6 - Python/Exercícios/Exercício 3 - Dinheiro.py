'''
- pegar a quantidade de centavos, multiplicar por 100, e subritair o número de moedas necessárias para o troco
'''
def main():
    centavos = float(input("Change owed: ")) * 100
    while (centavos < 0):
        main()
    # print(centavos)
    quantMoedas = calcularMoedas(centavos)
    print(quantMoedas)

def calcularMoedas(valor):
    moedas = 0
    ''''
    while (valor != 0):
        if (valor >= 25):
            while (valor >= 25):
                valor = valor - 25
                moedas += 1
        elif (valor >= 10):
            while (valor >= 10):
                valor = valor - 10
                moedas += 1
        elif (valor >= 5):
            while (valor >= 5):
                valor = valor - 5
                moedas += 1
        # elif (valor >= 1):
        else:
            while (valor >= 1):
                valor = valor - 1
                moedas += 1
    '''
    while (valor != 0):
        while (valor >= 25):
            valor = valor - 25
            moedas += 1
        while (valor >= 10):
            valor = valor - 10
            moedas += 1
        while (valor >= 5):
            valor = valor - 5
            moedas += 1
        while (valor >= 1):
            valor = valor - 1
            moedas += 1

    return moedas

main()
