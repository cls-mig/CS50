#include <stdio.h>

const int TOTAL = 3; // A letra maiúscula indica que é uma variável constante

float averageArray(float length, int array[])
{
    int soma = 0;
    for (int i = 0; i < length; i++)
    {
        soma += array[i];
    }

    return soma / length;
}

int main(void)
{
    int scores[TOTAL];
    /*
    scores[0] = 72;
    scores[1] = 73;
    scores[2] = 74;
    */
   /*
   printf("Digite o total de pontos: ");
   scanf("%i", &TOTAL);
   */

    printf("Informe cada ponto:\n");
    for (int i = 0; i < TOTAL; i++)
    {
        printf("Nota: ");
        scanf("%i", &scores[i]);
    }

    printf("Resultado: %.1f", averageArray(TOTAL, scores));
}
