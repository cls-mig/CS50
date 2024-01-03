#include <stdio.h>

int main(void)
{
    /*
    & - informa e mque endereço está uma variavel
    * - operador de desreferência, significa, vá para o seguinte endereço
    */
    // um ponteiro é um tipo de dado que armazena endereços
    /*
    int n = 50;
    int *p = &n;
    printf("%i\n", p);
    printf("%i\n", *p);
    */
    char s[] = "HI!";
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);

    char *c = "HI!";
}
