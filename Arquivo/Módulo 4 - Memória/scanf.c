#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // inteiros
    /*
    int x;
    printf("%i", &x); // atribua o que o usuário digitar no endereço dessa variável
    printf("x: %i\n", &x);
    */

    // strings
    // char *s; or char s[4]; 
    char *s = malloc(4); // s é fundamentalmente um endereço
    printf("s: ");
    scanf("%s", s); // por isso eu não passo o endereço (&) em que a variável se encontra
    printf("s: %s\n", s);

    free(s);
}
