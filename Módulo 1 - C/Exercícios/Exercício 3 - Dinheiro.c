#include <stdio.h>

float calcularMoedas(float valor)
{
    int n = 0;
    float rest;

    while (valor > 0)
    {
        do
        {
            valor = valor - 0.25;
            n++;
        } while (0.25 <= valor);
        if (0.10 <= valor)
        {
            do
            {
                valor = valor - 0.10;
                n++;
            } while (0.10 <= valor);
        } else if (0.05 <= valor)
        {
            do
            {
                valor = valor - 0.05;
                n++;
            } while (0.05 <= valor);
        } else if (0.01 <= valor)
        {
            do
            {
                valor = valor - 0.01;
                n++;
            } while (0.01 <= valor);
        }
    }
    return n;
}

int main()
{
    float valor;
    int moedas;

    do
    {
        printf("Quanto dinheiro sobrou? ");
        scanf("%f", &valor);
        // printf("%.2f", valor);
    } while (valor <= 0);

    moedas = calcularMoedas(valor);
    printf("%i moedas.", moedas);
}
