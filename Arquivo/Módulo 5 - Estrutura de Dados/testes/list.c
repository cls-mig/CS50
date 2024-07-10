#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Lista vinculada

int main(void)
{
    // Maneira "tradicional"
    /*
    int list[3];

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", list[i]);
    }
    */

    // Maniera dinâmica (copiando de espaço de memória para o outro)
    int *list = malloc(3 * sizeof(int)); // maneira malloc de criar um array
    // um array não pode ser redimensionado

    if (list == NULL)
    {
        return 1;
    }
    // * - vá para o endereço dessa variável
    // operação matemática de ponteiros
    *list = 1;
    *(list + 1) = 2;
    *(list + 2) = 3;

    int *tmp = realloc(list, 4 * sizeof(int)); // realloc copia o conteúdo do espaço de memória da variável list e redimensiona para ter mais um espaço de memória , liberando o espaço original e copiando o conteúdo para um espaço maior

    if (tmp == NULL)
    {
        free(list);
        return 1;
    }
    /*
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }
    */
    *(tmp + 3) = 4;
    
    // free(list); // eu liberei os espeço de memória de list

    list = tmp; // atribui a ele o valor de tmp, ou seja, os endereços de tmp foram para list (reutilizei o nome)
    
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    free(list);
}
