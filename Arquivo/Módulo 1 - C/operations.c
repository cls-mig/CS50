#include <stdio.h>

int main()
{
    int x;
    int y;
    
    printf("Digite o valor de x: ");
    scanf("%i", &x);
    printf("Digite o valor de y: ");
    scanf("%i", &y);

    printf("Sua razão é igual a:\nResultado: %f", (float) x / (float) y);
    // %.10f permite exibir um número determinado de casas após a vírgula

    return 0;
}

/*
    int soma(int x, int y)
    {
        int adicao;
        adicao = x + y;
        printf("Resultado: %i", adicao);
    }

    int main(void)
    {
        // Declaração das variáveis
        int x;
        int y;
        // Atribuição dos valores
        scanf("Digite o valor de x: %i", x);
        scanf("Digite o valor de y: %i", y);
        // Chamada da função
        soma(x, y);
    }
*/
