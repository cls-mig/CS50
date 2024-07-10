#include <stdio.h>

int main()
{
    /*
    - um ponteiro me permite criar um array de string, onde cada elemento é uma string (conjunto de caracteres)
    - uma matriz é uma forma semelhante de fazer a mesma coisa, a diferença está no espaço ocupado na memória
    - um array de caracteres é somente uma sequência de caracteres, onde um array seria uma palavra
    */

    /*
    char *ponteiro[] = {"Alice", "Carlos", "Brian"};

    int vetor[] = {1, 2, 3, 4, 5, 6, 7};
    */

    int matriz[2][2]; // matriz de inteiros

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            matriz[i][j] = j;
            printf("%i", matriz[i][j]);
        }
        printf("\n");
    }
}
