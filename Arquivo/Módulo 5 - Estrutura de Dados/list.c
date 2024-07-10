#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    /* data */
    int number;
    struct node *next;
}
node;

/*
Estruturas de Dados (blocos de construção)
- listas vinculadas (estrutura de dados unidimensional)
- árvore de pesquisa binária (estrutura de dados bidimensional)
- estrutura de dados recursiva
- hash tables -> array de listas vinculadas
- trie -> é uma árvore composta de arrays
- estruturas de dados abstratas:
    - queues -> filas (PEPS/FIFO - o primiero a entrar é o primeiro a sair)
    - stacks -> pilhas  (UEPS/FIFO - o último a entrar é o primeiro a sair)
    - dictionaries
*/

int main(void)
{
    node *list = NULL;

    node *n = malloc(sizeof(node)); // um espaço de memória de um nó (node), onde cabe um inteiro e o ponteiro para um nó (outro inteiro)
    if (n == NULL) // quando não é encontrado espaço de memória disponível (o malloc "falha")
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

    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number);
    }

    while (list != NULL)
    {
        node *tmp = list->next; // utiliza tmp para sempre olhar um passo a frente
        free(list);
        list = tmp;
    }
}
