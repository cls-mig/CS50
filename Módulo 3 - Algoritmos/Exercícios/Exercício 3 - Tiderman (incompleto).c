// #include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// esse por enquanto é o exercício mais difícil que eu fiz até agora... record_preferences, sort_pairs e lock_pairs são as funções mais difíceis

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
char candidates[MAX][MAX];
pair pairs[MAX * (MAX - 1) / 2]; // quantidade de estruturas

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, char *name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1; // quantidade de argumentos menos o primeiro argumento (./'Tiderman.exe')

    // printf("%i", candidate_count);
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    
    for (int i = 0; i < candidate_count; i++)
    {
        int n = strlen(argv[i + 1]);

        for (int j = 0; j < n; j++)
        {
            candidates[i][j] = argv[i + 1][j];
            // printf("%c", candidates[i][j]);
        }
        candidates[i][n] = '\0';
        // printf("\n");
    }
    /*
    - a aresta aponta para quem perde nesse duelo (o vencedor é a fonte do gráfico)
    - se houver ciclos, devê-se ordenar os pares baseado na diferença entre as vitórias, o menor valor dessa difereça não é considerado
    */
    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count;
    printf("Number of voters: ");
    scanf("%i", &voter_count);

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            char *name = malloc(10);
            printf("Rank %i: ", j);
            scanf("%s", name);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                free(name);
                return 3;
            }
        }
        /*
        for (int i = 0; i < candidate_count; i++)
        {
            printf("%i\n", ranks[i]);
        }
        */
        record_preferences(ranks);

        printf("\n");
    }
    
    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, char *name, int ranks[])
{
    // printf("vote\n");

    for (int i = 0; i < candidate_count; i++)
    {
        // printf("%s\n", candidates[i]);
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            rank++;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // nessa etapa o ChatGPT me ajudou porque eu estava com muita dificuldade, mas eu vou tentar explicar o que ele fez, como uma forma de compensar o fato de eu não ter conseguido fazer
    /*
    1° - as coordenadas de preferences já são os números dos candidatos no array ranks, ou seja, preferences[2][0] é o candidato de número 2 sobre o candidato de número 0
    2° - a variável 'preferido' armazena a primeira preferência do eleitor
    3° - a variável 'menos_preferido' armazena a próxima preferência do eleitor em relação ao ranks[i], sendo j = i + 1, ou seja:
       - preferido = ranks[0] (i = 0)
       - menos prefeiro = ranks[1] (j = i + 1)
       - ...
       - assim são formados os pares dos números de candidatos (preferido, menos_preferido)
    4° - cada par já é uma coordenada da matriz preferences, ou seja, se para um eleitor X o candidado 1 é melhor que o candidato 0, é formado um par (1, 0), nisso, na matriz preferences as coordenadas (1, 0) reprensentam essa relação (toda relaçào recebe +1).
    */
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            int preferido = ranks[i];
            int menos_preferido = ranks[j];
            // printf("(%i, %i)\n", ranks[i], ranks[j]);
            
            // a função aumenta a contagem de preferência para o candidato preferido sobre o candidato menos preferido na matriz 'preferences'
            preferences[preferido][menos_preferido]++;
        }
    }
    
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("- %i (%i, %i) ", preferences[i][j], i, j);
        }
        printf("-\n");
    }
    
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    /*
    - eu preciso montar um par entre cada um dos candidatos e verificar par por par quem é o vencedor, preenchendo o array pairs[]
    */
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                printf("pair: (%i, %i) -> ", i, j);
                printf("Candidato %i ganha o Candidato %i\n", i, j);
                
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            } else
                if (preferences[i][j] < preferences[j][i])
                {
                    printf("pair: (%i, %i) -> ", j, i);
                    printf("Candidato %i ganha o Candidato %i\n", j, i);
                    
                    pairs[pair_count].winner = j;
                    pairs[pair_count].loser = i;
                    pair_count++;
                }
                else
                {
                    /*
                    printf("Par: (%i, %i)\n", j, i);
                    printf("Candidato %i empatou com o Candidato %i\n", i, j);
                    */
                    // pair_count++;
                }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    /*
    outro trecho que o ChatGPT me ajudou e novamente vou ter que entendê-lo e narrar sua execução, como forma de "aprendizado"
    */
    /*
    tirar a diferença entre os pares de vitória e classificar em ordem, da maior diferença, para a menor diferença
    */
    int strong[pair_count], n = 0;
    // Calcular as diferenças de força e armazenar em strong[] (eu fiz isso também...)
    for (int i = 0; i < pair_count; i++)
    {
        strong[i] = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
        /*
        Bubble sort - funciona movendo o maior elemento para a posição correta em cada iteração, "borbulhando" lentamente os elementos maiores para o final do vetor
        */
    }
    /*
    - ...
    */
    // Bubble Sort para classificar os pares em ordem decrescente de força
    for (int i = 0; i < pair_count - 1; i++)
    {
        for (int j = 0; j < pair_count - i - 1; j++)
        {
            if (strong[j] < strong[j + 1])
            {
                int temp = strong[j];
                strong[j] = strong[j + 1];
                strong[j + 1] = temp;

                // Também trocar os pares correspondentes em pairs[]
                pair temp_pair = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = temp_pair;
            }
        }
    }
    
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    /*
    adicionar true na matriz lock, cujas coordenadas são o candidato que vencem o outro
    */
    for (int i = 0; i < pair_count; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] = true;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (!(locked[i][j] == true))
            {
                locked[i][j] = false;
            }
        }
    }

    return;
}

// Print the winner of the election
void print_winner(void)
{
    

    return;
}
