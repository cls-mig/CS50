#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct
{
    char name[10];
    int votes;
}
Candidate;

// protótipo das funções
bool vote(Candidate candidato[], char name[], int l);
void print_winner(Candidate candidato[], int n);

int main (int argc, char *argv[])
{
    // printf("%i\n", argc);
    int num_votes;
    char candidate_name[10];
    
    if (argc > 2)
    {
        Candidate candidato[argc - 1];
        for (int i = 1; i < argc; i++)
        {
            int n = strlen(argv[i]);
            for (int j = 0; j < n; j++)
            {
                candidato[i].name[j] = argv[i][j]; // atribui o nome dos candidatos vindos do vetor de argumentos
                candidato[i].votes = 0; // inicializei a contagem dos votos
                // printf("%c", candidato[i].name[j]);
            }
            candidato[i].name[n] = '\0';
            // printf("\n");
        }

        printf("Quantidade de eleitores: ");
        scanf("%i", &num_votes);

        for (int k = 0; k < num_votes; k++)
        {
            printf("Vote: ");
            scanf("%s", candidate_name);
            // int n = strlen(candidate_name);
            vote(candidato, candidate_name, argc);
        }

        // variável que recebe os votos do primeiro candidato
        int more_votes = candidato[1].votes;
        
        for (int g = 1; g < argc; g++)
        {
            // se os votos dos candidatos subsequentes forem maiores, ele vai substituindo o more_votes pelos maiores que ele encontrar
            if (candidato[g].votes > more_votes)
            {
                more_votes = candidato[g].votes;
            }
        }

        for (int h = 1; h < argc; h++)
        {
            // verifica os candidatos novamente para saber exatamente o nome de quem tem mais votos
            if (more_votes == candidato[h].votes)
            {
                /*
                printf("%s\n", candidato[h].name);
                printf("%i", more_votes);
                */
                print_winner(candidato, h); // chama a função e envia o(s) nome(s) desse(s) candidato(s)
            }
        }
    } else
    {
        printf("Digite o nome de mais de um candidato\n");
    }
}

bool vote(Candidate candidato[], char name[], int l)
{
    for (int i = 1; i < l; i++)
    {
        if (strcmp(candidato[i].name, name) == 0)
        {
            candidato[i].votes++;
            // printf("%i", candidato[i].votes);
            return true;
        }
    }
    return false; // Retorna false se nenhum candidato é encontrado
}

void print_winner(Candidate candidato[], int n)
{
    printf("%s\n", candidato[n].name);
}
