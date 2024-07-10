#include <stdio.h>

// variáveis globais não definidas são inicializadas convencionalmente com 0 ou NUL

int main(void)
{
    int scores[3];

    for (int i = 0; i < 3; i++)
    {
        // variáveis não inicializadas lhe são atribuídas valores lixo na memória
        printf("%i\n", scores[i]);
    }
}
