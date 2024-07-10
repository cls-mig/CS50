#include <stdio.h>

/*
    protótipo:
    me permite indicar que a função ainda existirá posteriormente no arquivo
*/

int contador(void);

int main(void)
{
    int valor = contador();
    for (int i = 0; i < valor; i++)
    {
        printf("Olá, mundo!\n");
    }
}

int contador(void)
{
    // variável declarada
    int n;

    // atribui um valor à variável
    do
    {
        printf("Digite um valor: ");
        scanf("%i", &n);
    }
    /*
        aqui entra a condição:
        enquanto o valor atribuído a n for menor que 1, ele retornará à função 'do', pedindo novamente para que o usuário digite um valor para n
    */
    while (n < 1);
    return n;
}

/*
    void function(int v)
    {
        for (int i = 0; i < v; i++)
        {
            printf("Olá, mundo!\n");
        }
    }

    int main()
    {
        function(3);
    }
*/
