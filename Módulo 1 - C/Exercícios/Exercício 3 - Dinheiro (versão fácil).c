#include <stdio.h>
#include <math.h>

// Exercício 3 - Dinheiro (versão fácil)

int calcularMoedas(int valor)
{
    int n = 0;
    
    while (valor > 0)
    {
        if (valor >= 25)
        {
            do
            {
                valor -= 25;
                n++;
            } while (25 <= valor);
        } else if (10 <= valor)
        {
            do
            {
                valor -= 10;
                n++;
            } while (10 <= valor);
        } else if (5 <= valor)
        {
            do
            {
                valor -= 5;
                n++;
            } while (5 <= valor);
        } else if (1 <= valor)
        {
            do
            {
                valor -= 1;
                n++;
            } while (1 <= valor);
        }
    }
    
    return n;
}

int main()
{
    float centavos;
    int reais;
    int moedas;

    do
    {
        printf("Quanto dinheiro sobrou? ");
        scanf("%f", &centavos);
        // printf("%.2f", valor);
    } while (centavos <= 0);
    
    reais = round(centavos * 100);
    printf("%i\n", reais);

    moedas = calcularMoedas(reais);
    printf("\n%i moeda(s).", moedas);
}
