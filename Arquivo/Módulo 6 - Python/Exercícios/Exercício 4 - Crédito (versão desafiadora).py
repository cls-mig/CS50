# Algoritmo de Luhn
'''
AMEX - 15 dígitos que começam com 34 ou 37
MASTERCARD - 16 dígitos que começam com 51, 52, 53, 54 ou 55
VISA - 13 e 16 dígitos que começam com 4
'''

# Sim, praticamente copiei e colei o código em C, só fiz pequenas alterações

def main ():
    numCartao = int(input("Número: "))
    # print(numCartao)

    d = 10 # variável que multiplicada por 10 percorre os dígitos do cartão
    digitoCartao = 0 # variável que receberá durante o loop cada dígito do cartão
    m = 0 # m verifica quais dígitos serão multiplicados por 2
    somaDigitos = 0
    quantDigitos = 0

    priDigito = 0
    segDigito = 0
    inicioCartao = 0
    
    # for i in range(numCartao):
    while (numCartao != 0):
        digitoCartao = numCartao % d
        numCartao -= digitoCartao
        d *= 10

        while (digitoCartao >= 10): # enquanto esse digito for maior ou igual a 10, reduza esse digito até o número ficar menor (sucessivas divisões por 10)
            digitoCartao /= 10 # achar o algarismo

        if (numCartao == 0):
            priDigito = digitoCartao
        else:
            segDigito = digitoCartao
        
        m += 1 # m verifica quais dígitos serão multiplicados por 2

        if (m % 2 == 0): # se for par ter seu digito multiplicado por dois
            digitoCartao *= 2
            # condição que verifica quais desses dígitos dobrados são maiores que 10 e que terão seus algarismos somados
            if (digitoCartao >= 10):
                somaAlgarismo = 0
                somaAlgarismo = digitoCartao % 10
                digitoCartao -= somaAlgarismo
                
                digitoCartao /= 10
                somaAlgarismo += digitoCartao
                somaDigitos += somaAlgarismo
            else:
                somaDigitos += digitoCartao
        else:
            somaDigitos += digitoCartao
        
        quantDigitos += 1
    
    inicioCartao = (priDigito * 10) + segDigito

    if (somaDigitos % 10 == 0):
        if (priDigito == 4 and (quantDigitos == 13 or quantDigitos == 16)):
            print("VISA")
        else:
            if ((inicioCartao == 34 or inicioCartao == 37) and quantDigitos == 15):
                print("AMERICAN EXPRESS")
            else:
                if (priDigito == 5 and (segDigito >= 1 and segDigito <= 5) and quantDigitos == 16):
                    print("MASTERCARD")
                else:
                    print("INVALID")
    else:
        print("INVALID")

main()
