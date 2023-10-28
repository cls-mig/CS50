#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Esse programa consiste em deixar as letras de uma palavra informada pelo usuário maiúsculas */

const int c = 30;

int main(void)
{
    char s[c];
    printf("Antes: ");
    scanf("%s", s);
    printf("Depois: ");

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (islower(s[i])) // Verifica se a letra é minúscula
        {
            printf("%c", toupper(s[i])); // Se for, ela será exibida maúscula
        }
        else
        {
            printf("%c", s[i]); // Se não, será exibida normalmente
        }
        
        /*
        if (s[i] >= 'a' && s[i] <= 'z') // 'a' e 'z' representam números
        {
            printf("%c", s[i] - 32);
        }
        else
        {
            printf("%c", s[i]);
        }
        */
    }
}
