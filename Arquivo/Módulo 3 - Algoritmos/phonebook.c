#include <stdio.h>
#include <string.h>

// Quanto maior se tornam as aplicaçÕes, com novos recursos e funções, mais essa estrutura precisa estar visível para todas elas
typedef struct
    {
        char *name;
        char *number;
    }
    person;

    /*
    strcmp
    strcpy
    strlen
    */

int main()
{
    person people[2];

    people[0].name = "Carlos";
    people[1].name = "Gabriel";

    people[0].number = "(21) 9 7231-0436";
    people[1].number = "(21) 9 6707-2434";

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name, "Gabriel") == 0)
        {
            printf("Encontrado: %s\n", people[i].number);
            return 0;
        }
    }
    printf("Não encontrado\n");
    return 1;

    /*
    for (int i = 0; i < 2; i++)
    {
        printf("Pessoa %i:\nNome - %s\nTelefone - %s\n", i, people[i].nome, people[i]);
    }
    */
}
