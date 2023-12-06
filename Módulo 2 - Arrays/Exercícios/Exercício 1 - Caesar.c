#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int c = 1000;

int plaintext(int k)
{
    int chave = k;
    // printf("\nMinha chave: %i\n", chave);

    char text[c];
    // char cipher[c];
    int cipher[c];

    printf("\nplaintext: ");
    scanf("\n%1000[^\n]", text);

    printf("\nciphertext: ");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // printf("%c", text[i]);
        /*
        isalpha - se o caractere é alfabético
        isupper - se o caractere é maiúsculo
        islower - se o caractere é minúsculo
        */
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                text[i] -= 65;
                // printf("%i", text[i]);

                cipher[i] = ((text[i]) + chave) % 26;
                printf("%c", cipher[i] += 65);
                // printf("\n%c -> %i\n", cipher[i] + 65, cipher[i]);
            }
            else
            {
                text[i] -= 97;
                // printf("%i", text[i]);

                cipher[i] = ((text[i]) + chave) % 26;
                printf("%c", cipher[i] += 97);
                // printf("%c -> %i\n", cipher[i] + 97, cipher[i]);
            }
        }
        else
        {
            cipher[i] = text[i];
            printf("%c", cipher[i]);
        }
    }

    // c i = (p i + k) % 26
    // cipher[i] = text[i] + chave;
    /*
    c i - posição do caractere cifrado
    p i - posição do caractere alfabético
    k - é a chave de criptografia
    */
    
    return 0;
}

int main (int argc, char *argv[])
{
    char k[c];
    int chave = 0;

    // printf("\nChegou aqui: ");

    if (argc == 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isalpha(argv[1][0]))
            {
                k[i] = argv[1][i];
                // printf("%c", k[i]);
            } else
            {
                printf("O argumento de linha de comando deve ser um inteiro maior 0\n");
            }
        }
        /*
        // for (int i = strlen(argv[1]); i == 0; i--)
        for(int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            chave = atoi(&k[i]) + (10 * i);
            printf("\n%i - > %i", i, chave);
        }
        */

        chave = atoi(&k[0]);
        // printf("\n%i", chave);
        plaintext(chave);
    } else
    {
        printf("Insira somente um argumento de linha de comando, sendo ele um inteiro maior que 0\n");
    }

    return 0;
}
