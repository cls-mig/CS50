#include <stdio.h>

int main(void)
{
    /*
    & - informa em que endereço está uma variavel
    * - operador de desreferência, significa, vá para o seguinte endereço
    %p - especificador de formato usado para imprimir ou ler valores de ponteiros
    \0 - 00000000 (indica o fim de uma string)
    char *s = "HI!" é sinônimo de string s = "HI!"
    printf("%i\n", *(c+10000)); - resulta em falta de segmentação
    */
    /*
    Ponteiro:
    - um ponteiro é um tipo de dado que armazena os endereços das variáveis
    - um ponteiro tem 8 bytes
    */
    /*
    int n = 50; // n recebe 50
    int *p = &n; // *p (ponteiro) recebe o endereço da variável n
    printf("%i\n", p); // imprime o endereço da variável *p
    printf("%i\n", *p); // imprime o valor contido na variável *p
    */
    char s[] = "HI!";
    
    printf("%p\n", &s[0]); // imprima esse caracter como se fosse um ponteiro
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);

    char *c = "HI!";
    /*
    printf("%c\n", *c); // aponta para o primeiro caractere da string
    printf("%p\n", c); // c[0] é um ponteiro, para exibí-lo eu usei o formato de código %p (em qual endereço está o primeiro caractere da string *c)
    printf("%s\n", c); // imprime uma string
    */
    /*
    printf("%c\n", c[0]);
    printf("%c\n", c[1]);
    printf("%c\n", c[2]);
    */
    printf("%c\n", *c);
    printf("%c\n", *(c+1));
    printf("%c\n", *(c+2));
    printf("%i\n", *(c+3));
}
