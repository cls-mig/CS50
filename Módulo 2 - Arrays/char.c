#include <stdio.h>

int main(void)
{
    char char1 = 's'; // Uma string é um vetor de caracteres
    char char2 = 't';
    char string[3] = "Oi!";

    printf("%c %i %c %c %i", char1, char2, string[0], string[1], (int) string[2]);
}
