#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
é necessário fornecer somente um argumento, sendo ele a chave
a chave pode ser tanto escrito em letras maiúsculas quanto em minúsculas
não pode ser forncida uma chave menor que 26 caracteres
não pode ser usado caracteres numéricos
não pode ser usado caracteres alfabéticos repetidos
*/

const int l = 1000;

int plaintext(int t, char chave[])
{
    char text[l];
    int cipher[l];
    int posicao = 0;
    
    printf("plaintext: ");
    scanf("\n%1000[^\n]", text);
    
    // printf("\nciphertext: \n");

    for (int i = 0; i < t; i++)
    {
        if (isupper(chave[i]))
        {
            chave[i] -= 65;
        }
        else
        {
            chave[i] -= 97;
        }
        // printf("chave: %i", chave[i]);
    }
    
    printf("\n");

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                posicao = text[i] -= 65;
                cipher[i] = chave[posicao];
                // printf("%c", cipher[i]);
                printf("%c", cipher[i] += 65);
            }
            else
            {
                posicao = text[i] -= 97;
                cipher[i] = chave[posicao];
                printf("%c", cipher[i] += 97);
            }
        }
        else
        {
            cipher[i] = text[i];
            printf("%c", cipher[i]);
        }
    }

    return 0;
}

int main(int argc, char *argv[])
{
    char k[26];

    // int chave = 0;

    // printf("\nChegou aqui: ");

    if (argc == 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isalpha(argv[1][i]))
            {
                k[i] = argv[1][i];
                // printf("%i\n", i);
                for (int v = 0; v < i; v++)
                {
                    if (k[v] == k[i])
                    {
                        printf("A chave deve conter letras diferentes\n");
                    }
                }
                // printf("%c", k[i]);
            } else
            {
                printf("O argumento fornecido deve conter somente letras\n");
            }
            if (i > 26)
            {
                printf("O argumento deve ser uma chave de 26 caracteres\n");
            }
        }
        plaintext(26, k);
    } else
    {
        printf("Insira somente um argumento de linha de comando, sendo ele formado somente por letras\n");
    }
}
