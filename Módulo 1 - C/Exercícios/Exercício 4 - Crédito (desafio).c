#include <stdio.h>
#include <math.h>

// Exercício 4 - Créditos (desafio)

int main(void)
{
    // Algoritmo de Luhn
    /*
    AMEX - 15 dígitos que começam com 34 ou 37
    MASTERCARD - 16 dígitos que começam com 51, 52, 53, 54 ou 55
    VISA - 13 e 16 dígitos que começam com 4
    */
    long long int numCartao;

    printf("Number: ");
    scanf("%lli", &numCartao);
    // printf("numero: %lld\n", cartao);

    long long int d = 10; // variável que multiplicada por 10 percorre os dígitos do cartão
    long long int digitoCartao = 0; // variável que receberá durante o loop cada dígito do cartão
    int m = 0, somaDigitos = 0;
    int quantDigitos = 0;

    int priDigito, segDigito;
    int inicioCartao;

    for (int i = 0; i < numCartao; i++)
    {
        digitoCartao = numCartao % d;
        numCartao -= digitoCartao;
        // d é multiplico por 10 para andar nos dígitos do cartão
        d *= 10;

        if (digitoCartao >= 10)
        {
            for (int i = 0; digitoCartao >= 10; i++)
            {
                digitoCartao /= 10;
            }
        }

        if (numCartao == 0)
        {
            priDigito = digitoCartao;
        } else
        {
            segDigito = digitoCartao;
        }
        
        // m verifica quais dígitos serão multiplicados por 2
        m++;

        if (m % 2 == 0)
        {
            digitoCartao *= 2;
            // condição que verifica quais desses dígitos dobrados são maiores que 10 e que terão seus algarismos somados
            if (digitoCartao >= 10)
            {
                int somaAlgarismo;
                somaAlgarismo = digitoCartao % 10;
                digitoCartao -= somaAlgarismo;
                /*
                for (int i = 0; digitoCartao >= 10; i++)
                {
                    digitoCartao /= 10;
                }
                */
                digitoCartao /= 10;
                somaAlgarismo += digitoCartao;
                somaDigitos += somaAlgarismo;
            } else
            {
                somaDigitos += digitoCartao;
            }
        } else
        {
            somaDigitos += digitoCartao;
        }
        quantDigitos++;
    }

    inicioCartao = (priDigito * 10) + segDigito;

    if (somaDigitos % 10 == 0)
    {
        if (priDigito == 4 && (quantDigitos == 13 || quantDigitos == 16))
        {
            printf("\nVISA");
        } else
        {
            if ((inicioCartao == 34 || inicioCartao == 37) && quantDigitos == 15)
            {
                printf("\nAMERICAN EXPRESS");
            } else
            {
                if (priDigito == 5 && (segDigito >=1 && segDigito <=5))
                {
                    printf("\nMASTERCARD");
                }
                else
                {
                    printf("\nINVALID");
                }
            }
        }
    } else
    {
        printf("\nINVALID");
    }
}
