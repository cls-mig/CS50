#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Legibilidade
/*
    - Sentença - número de frases, separadas por '.', '?' ou '!'
    - Palavras - caracteres em sequência
    - Letras - se possui forma maiúscula, é uma letra

    index = 0.0588 * L - 0.296 * S - 15.8
*/

// const int c = 1000;

int main (void)
{
    /*
    char texto[c];
    printf("Texto: ");
    scanf("\n%1000[^\n]", texto);
    */

    // atualização do código após o conteúdo do módulos 4 e 5
    printf("Texto: ");
    char *texto = malloc(1000);
    scanf("%[^\n]", texto); // %[^\n] - lê os espaços de uma string (ainda não entendo exatamente essa sintaxe)
    /*
    * - vá para aquele endereço (no caso, da variável)
    & - me retorne o endereço dessa variável (... = &variavel)
    */

    int letras = 0;
    int palavras = 1;
    int sentencas = 0;

    float indice = 0;
    float L, S;

    // printf("%i", n);

    for (int i = 0, n = strlen(texto); i < n; i++)
    {
        // printf("\nQuantidade de caracteres: %i", n);
        /*
        i: 0, n: 5, Caractere: 
        i: 1, n: 5, Caractere: 
        i: 2, n: 5, Caractere: 
        i: 3, n: 5, Caractere: 
        i: 4, n: 5, Caractere: 
        i: 5, n: 5, Caractere: 
        ...
        */
        if (islower(texto[i]) || isupper(texto[i]))
        {
            letras++;
        } else
        if (texto[i] == ' ') // isspace(texto[i]) - verifica se essa posição no texo[i] é um espaço
        {
            palavras++;
        }
        if (texto[i] == '.' || texto[i] == '?' || texto[i] == '!')
        {
            sentencas++;
        }
        printf("%c", texto[i]);
    }

    printf("\nQuantidade de letras: %i", letras);
    printf("\nQuantidade de palavras: %i", palavras);
    printf("\nQuantidade de frases: %i\n", sentencas);
    
    L = ((float) letras / (float) palavras) * 100;
    S = ((float) sentencas / (float) palavras) * 100;

    // Índice Coleman-Liau
    indice = (0.0588 * L) - (0.296 * S) - 15.8;
    // printf("\n%.1f", indice);

    if (indice < 1)
    {
        printf("\nBefore Grade 1");
    } else {
        if (indice >= 16)
        {
            printf("\nGrade: 16+");
        } else
        {
            printf("\nGrade: %.0f", indice);
        }
    }

    free(texto);
}
