#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    /*
    FILE - tipo de dado que representa um arquivo
    *file - ponteiro para um arquivo (endereço de um arquivo)
    fopne - funçÃo que abre o arquivo

    - Os arquivos Comma-separated values, também conhecido como CSV, são arquivos de texto de formato regulamentado pelo RFC 4180, que faz uma ordenação de bytes ou um formato de terminador de linha, separando valores com vírgulas.
    */
    FILE *file = fopen("phonebook.csv", "a"); // nome do arquivo que eu quero abrir e o modo de abrir ele, seja para lê-lo, escrevê-lo ou anexá-lo ("a" de anexar, adicionar linha por linha a ele)

    if (file == NULL) // or if (!FILE)
    {
        return 1;
    }

    char *name = malloc(10);
    char *number = malloc(10);

    printf("Name: ");
    scanf("%s", name);
    printf("Number: ");
    scanf("%s", number);

    fprintf(file, "%s,%s\n", name, number); // imprime no arquivo

    fclose(file); // fecha o arquivo

    free(name);
    free(number);
}
