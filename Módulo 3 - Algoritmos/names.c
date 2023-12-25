#include <stdio.h>
#include <string.h>

int main(void)
{
    char *names[7] = {"Beatriz", "Carlos", "David", "Eduarda", "Gabriel", "Maria", "Thiago"};
    /*
    ponteiros - um array de ponteiros é frequentemente utilizado para representar um conjunto de strings
              - cada elemento do array é um ponteiro para uma string (um array de caracteres)
    */

    for (int i = 0; i < 7; i++)
    {
        /*
        strcmp - compara duas strings (se elas são iguais)
               - verifica caractere por caractere, se retornar um valor positivo a segunda string está depois da primeira string, se retorna um valor negativo a segunda string está antes da primeira string, e se retorna 0 a segunda string é giual a primeira string
        */
        if (strcmp(names[i], "Thiago") == 0)
        {
            printf("Encontrado");
            return 0;
        }
    }
    printf("Não encontrado");
    return 1;
}
