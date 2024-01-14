#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    // a função malloc é usada para alocar uma quantidade específica de bytes de memória dinamicamente
    char *s = malloc(10);
    char *t = malloc(10);

    printf("s: ");
    scanf("%s", s);
    printf("t: ");
    scanf("%s", t);
    
    if (s == NULL || t == NULL) { // N-U-L-L representa um ponteiro nul (ausência de um endereço)
        return 1;
    }

    printf("%s\n", s);
    printf("%s\n", t);

    if (strcmp(s, t) == 0)
    {
        printf("Igual");
    } else
    {
        printf("Diferente");
    }

    free(s); // Liberar memória alocada para s
    free(t); // Liberar memória alocada para t

    return 0;
}
