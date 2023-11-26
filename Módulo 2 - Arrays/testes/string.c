#include <stdio.h>
#include <string.h>

const int c = 30;

int main(void)
{
    char s[c];

    printf("Input: ");
    scanf("%s", s);
    printf("\nOutput: ");
    int n = strlen(s);

    // for (int i = 0; s[i] != '\0'; i++)
    for (int i = 0; i < n; i++)
    {
        printf("%c", s[i]);
    }
}
