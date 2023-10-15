#include <stdio.h>

int main()
{
    int x;
    int y;
    char resposta;

    printf("Digite o valor de x: ");
    scanf("%i", &x);
    printf("Digite o valor de y: ");
    scanf("%i", &y);

    if (x < y)
    {
        printf("x é menor que y");
    } else {
        if (y < x)
        {
            printf("y é menor que x");
        } else
        {
            printf("x é igual a y");
        }
    }

    printf("\nSua razão é igual a %f", (float) /*casting*/ x / (float) y);
    printf("\nVocê concorda com esse resultado? (Y/N)");
    scanf("%s", &resposta);

    if (resposta == 'y' || resposta == 'Y')
    {
        printf("\nCerto!");
    } else {
        printf("Lamento-lhe informar, mas a matemática nunca erra.");
    }

    return 0;
}
