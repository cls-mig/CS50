// #include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    char name[10];
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count; // quantidade de eleitores
int candidate_count; // quantiddde de candidatos

// Function prototypes
bool vote(int voter, int rank, char name[]);
void tabulate(void);
bool print_winner(void);
/*
int find_min(void);
bool is_tie(int min);
void eliminate(int min);
*/
int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1; // quantidade de argumentos menos o primeiro argumento (./'runoff.exe')
    // candidate_count = argc;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    // for (int i = 0; i < candidate_count; i++)
    for (int i = 0; i < candidate_count; i++)
    {
        /*
        candidates[i].name[] = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
        */
        int n = strlen(argv[i + 1]);
        for (int j = 0; j < n; j++)
        {
            candidates[i].name[j] = argv[i + 1][j];
        }
        candidates[i].name[n] = '\0';
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    printf("Number of voters: ");
    scanf("%i", &voter_count);
    // voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {
        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            char name[10];
            printf("Rank %i: ", j + 1);
            scanf("%s", name);
            // string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    candidates[1].eliminated = true;

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        for (int i = 0; i < voter_count; i++)
        {
            for (int j = 0; j < candidate_count; j++)
            {
                printf("-  %i  ", preferences[i][j]);
            }
            printf("-\n");
        }

        printf("\n");

        for (int i = 0; i < candidate_count; i++)
        {
            printf("%s: %i\n", candidates[i].name, candidates[i].votes);
        }

        break;
        /*
        // Eliminate last-place candidates
        int min = find_min(); // Recebe o menor número de votos que um candidato recebeu e o atribui à variável min
        // printf("%i", min);
        bool tie = is_tie(min); // o valor mínimo tem que ser igual ao número de candidatos que não foram eliminados
        
        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
        */
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, char name[])
{
    // TODO
    /*
    printf("Voto: %i\n", voter);
    printf("Rank: %i\n", rank);
    printf("Nome: %s\n", name);
    */
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;
            // printf("%i\n", preferences[voter][rank]);
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO
    /*
    verifica se o voto do eleitor é igual ao número designado ao candidato
    preferences[][] == candidates[]...
    */
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            for (int n = 0; n < candidate_count; n++)
            {
                if (preferences[i][j] == n && candidates[n].eliminated == false)
                {
                    candidates[n].votes++;
                } /* else
                {
                    
                }
                */
            }
        }
    }
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO
    int n = 0, more_votes = candidates[0].votes;

    for (int g = 0; g < candidate_count; g++)
    {
        // se os votos dos candidatos subsequentes forem maiores, ele vai substituindo o more_votes pelos maiores que ele encontrar
        if (candidates[g].votes > more_votes)
        {
            more_votes = candidates[g].votes;
            n = g;
        }
    }

    if (more_votes > (voter_count / 2))
    {
        printf("%s is the winner.", candidates[n].name);
        return true;
    }
    return false;
}
/*
// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
    int fewer_votes = candidates[0].votes;

    for (int i = 0; i < candidate_count; i++)
    {
        // se os votos dos candidatos subsequentes forem menores, ele vai substituindo o fewer_votes pelos menores que ele encontrar
        if (candidates[i].votes < fewer_votes && candidates[i].eliminated == false)
        {
            fewer_votes = candidates[i].votes;
            return fewer_votes;
        }
    }
    return 0;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    int tie_count = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min && candidates[i].eliminated == false)
        {
            tie_count++;
        }
    }
    
    if (tie_count == candidate_count)
    {
        return true;
    }
    
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min && candidates[i].eliminated == false)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
*/
