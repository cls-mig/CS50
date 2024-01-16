#include <stdio.h>

// "Stack Overflow" refere-se a um erro que ocorre quando a pilha de chamadas de funções atinge um limite máximo de tamanho. Isso geralmente acontece quando há muitas chamadas de função aninhadas sem retorno, levando a um estouro da pilha.

void swap(int *a, int *b) // o tipo de função se refere ao valor que ela vai retornar
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);

    swap(&x, &y);

    printf("x is %i, y is %i\n", x, y);
}
