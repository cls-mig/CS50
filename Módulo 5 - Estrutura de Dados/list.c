#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    /* data */
    int number;
    struct node *next;
}
node;


int main(void)
{
    node *list = NULL;

    node *n = malloc(sizeof(node)); // um espaço de memória de um nó (node), onde cabe um inteiro e o ponteiro para um nó (outro inteiro)
    if (n == NULL) // quando não é encontrado espaço de memória suficiente
    {
        return 1;
    }

    /*
    - *n é um ponteiro que aponta para um espaço de memória do tamanho de um node (nó)
    - nesse node (*n que aponta para esse espaço), number recebe 1 e next recebe NULL
    */

    /*
    (*n).number = 1;
    (*n).next = NULL;
    */
    n->number = 1;
    n->next = NULL;
    list = n; // list recebe os endereços de n, ou seja, os endereços de n foram para list

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list); // eu libero o espaço ocupado por list
        return 1;
    }

    n->number = 2;
    n->next = NULL;
    // (*list).next = n;
    list->next = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list->next); // eu libero o espaço ocupado pelo next do nó 1
        free(list); // depois libero o espaço ocupado por list
        return 1;
    }

    n->number = 3;
    n->next = NULL;
    // (*list).next.next = n;
    list->next->next = n;

    // ...
}
