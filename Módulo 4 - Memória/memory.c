#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(4);
    s[0] = 'H';
    s[1] = 'I';
    s[2] = '!';

    free(s);

    int *x; // dê-me uma variável chamada x que eu possa armazenar o endereço de um int
    int *y;

    x = malloc(sizeof(int));

    *x = 42; // vá até o endereço em x e coloque o número 42

    // sizeof - operador que informa o tamanho de um tipo de dado
}
