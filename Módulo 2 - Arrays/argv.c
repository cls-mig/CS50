#include <stdio.h>
#include <string.h>

int main(int argc, char argv[])
{
    if (argc == 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            printf("%c\n", argv[1][i]);
        }
        // printf("hello, %c\n", argv[1]);
    }
    /*
    else
    {
        printf("\nhello, world");
    }
    */
}
