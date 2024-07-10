#include <stdio.h>
#include <string.h>

const int c = 50;

int main(void)
{
    char text[c];

    printf("Input: ");
    scanf("%s", text);
    // printf("\nOutput: ");
    int n = strlen(text);

    // for (int i = 0; s[i] != '\0'; i++)
    for (int i = 0; i < n; i++)
    {
        printf("\n%c", text[i]);
    }

    return 0;
}
