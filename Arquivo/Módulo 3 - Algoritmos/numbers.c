#include <stdio.h>

int main(void)
{
    int numbers[] = {2, 5, 7, 3, 1, 0};

    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == 0)
        {
            printf("Certo");
            return 0;
        }
    }
    printf("Errado");
    return 1;
}
