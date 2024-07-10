#include <stdio.h>
#include <string.h>
#include <stdlib.h> // função malloc e NULL
#include <ctype.h>

int main(void)
{
    // N-U-L-L representa um ponteiro nul (ausência de um endereço)
    // \0 é para caracteres e NULL é para ponteiros

    char *s = malloc(10);
    printf("s: ");
    scanf("%s", s);
    char *t = malloc(strlen(s) + 1);

    if (s == NULL)
    {
        return 1;
    }

    strcpy(t, s); // copia o conteúdo da variável s para a variável t
    /*
    for (int i = 0,  n = strlen(t); i <= n; i++)
    {
        t[i] = s[i];
        // *(t+i) = *(s+i)
    }
    */
    if (strlen(t) > 0)
    {
        t[0] = toupper(s[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(s); // Liberar memória alocada para s
    free(t); // Liberar memória alocada para t

    return 0;
}
