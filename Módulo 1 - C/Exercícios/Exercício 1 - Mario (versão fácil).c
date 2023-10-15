#include <stdio.h>

// Exercício 1.1 - Mario (versão fácil)

int construtor();

int main(void)
{
    int altura = construtor();
    int i = 0, j = altura - 1;
    
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
        printf("\n");
        i++;
        j--;
    }
}

int construtor()
{
    int n;

    // printf("Bem vindo ao Exercício 1.1 - Mario (versão fácil)!\nPrimeiro, digite a altura da pirâmide (um número entre 1 e 8)\n");
    {
        printf("Altura: ");
        scanf("%i", &n);
    } while (n < 1 || n > 8);
    return n;
}

/*
    for (int j = 8; j > 0; j--)
    {
        printf(" ");
    }
*/
