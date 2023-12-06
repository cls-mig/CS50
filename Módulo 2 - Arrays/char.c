#include <stdio.h>

int main(void)
{
    char char1 = 's'; // Uma string é um vetor de caracteres
    char char2 = 't';
    char string[3] = "Oi!";

    printf("%c\n%i\n%c\n%c\n%i", char1, char2, string[0], string[1], (int) string[2]);
    /*
    %c - vai exibir a letra 's'
    %i - vai exibir o valor ASCII do caractere 't'
    %c - vai exibir a letra 'O'
    %c - vai exibir a letra 'I'
    %i - vai exibir o valor ASCII do caractere '!'
    */
}
