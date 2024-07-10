#include <stdio.h>
// são arquivos de cabeçalho que dão acesso a mais funções

int main()
{
    char nome[50];
    // printf("Olá, mundo!");
    printf("Qual é o seu nome? ");
    scanf("%s", nome);
    printf("Olá, %s!\n", nome);

    return 0;

    /*
        int num;
        printf("Digite uma número ");
        scanf("%d", &num);
        printf("Número: %d\n", num);
    */
}
