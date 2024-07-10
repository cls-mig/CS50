#include <stdio.h>

// Exercício 1.1 - Mario (versão difícil)

int construtor()
{
    int n;

    do
    {
        printf("Altura: ");
        scanf("%i", &n);
    } while (n < 1 || n > 8);
    return n;
}

int espaco(int valor)
{
    printf("..");
    for (int m = 0; m <= valor; m++)
    {
        printf("#");
    }
    valor++;
    // printf("%i", valor);
    return valor;
}

int main()
{
    int altura = construtor();
    int i = 0, j = altura - 1, c = 0;
    
    while (i < altura && j >= 0)
    {
        for (int k = 0; k < j; k++)
        {
            printf(".");
        }
        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }
        c = espaco(c);
        printf("\n");
        i++;
        j--;
    }
}
