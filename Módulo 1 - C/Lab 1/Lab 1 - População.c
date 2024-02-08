#include <stdio.h>
#include <math.h> // Fornece um conjunto de funções para operações matemáticas, tais como funções trigonométricas, hiperbólicas, logaritmos, potência e arredondamentos

// Laboratório 1: crescimento populacional
/*
- porque quando i é um float, o quantidade inicial sendo 9 e o quantidade final sendo 18, se passam 9 anos e não 8?
*/
int main(void)
{
    int years = 0; // quantidade anos que passam até o número inicial passar ou ser igual ao número final
    
    // TODO: Solicite o valor inicial ao usuário
    int i = 0;
    do
    {
        printf("Quantidade inicial de lhamas: ");
        scanf("%i", &i);
        // scanf("%.0f", &i); // %.10f permite exibir um número determinado de casas após a vírgula
    } while (i < 9);

    // TODO: Solicite o valor final ao usuário
    int f = 0;
    do
    {
        printf("Quantidade final de lhamas: ");
        scanf("%i", &f);
    } while (f < i);

    // TODO: Calcule o número de anos até o limite
    while (!(i >= f))
    {
        i = round(i + (i / 3) - (i / 4)); // é amplamente utilizado para arredondar números em C. Ele recebe dois parâmetros: o número a ser arredondado e o número de casas decimais para arredondar (ex.: 2.56 * 100 = 256)
        years++;
    }

    // TODO: Imprima o número de anos
    printf("Years: %i", years);
}
