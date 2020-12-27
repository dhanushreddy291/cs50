#include <cs50.h>
#include <stdio.h>
#include <string.h>

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
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Checks for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs and initializes all elements in preferences.
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
            preferences[i][j] = 0;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Updates ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    //Finds the index of the candidate in the candidates[] list
    for (int p = 0 ; p < candidate_count ; p++)
    {
        if (strcmp(candidates[p], name) == 0)
        {
            ranks[rank] = p;
            //Returns true if the candidates name is found in the candidates[] list.
            return true;

        }
    }

    //Returns false if the candidate entered a name which isn't in candidates[] list.
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    int temp = 0 ;

    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            //Increments only those values of elements in preferences where one candidate is preferred over the other.
            preferences[ranks[i]][ranks[j]]++;
        }
    }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1 ; j < candidate_count ; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                //Increments pair_count after running below code.
                pairs[pair_count++].loser = j;

            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                //Increments pair_count after running below code.
                pairs[pair_count++].loser = i;

            }
        }
    }

    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    //For storing a pair temporarily.
    pair tmp;

    for (int i = 0; i < pair_count - 1; i++)
    {
        for (int j = 0; j < pair_count - i - 1; j++)
        {
            if (preferences[pairs[j].winner][pairs[j].loser] < preferences[pairs[j + 1].winner][pairs[j + 1].loser])
            {
                tmp.winner = pairs[j].winner;
                tmp.loser = pairs[j].loser;

                pairs[j].winner = pairs[j + 1].winner;
                pairs[j].loser = pairs[j + 1].loser;

                pairs[j + 1].winner = tmp.winner;
                pairs[j + 1].loser = tmp.loser;

            }
        }
    }

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    int count = 0;
    bool stopper = 0;

    for (int i = 0; i < pair_count; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] = true;


        for (int j = 0; j < candidate_count; j++)
        {
            for (int k = 0; k < candidate_count; k++)
            {
                if (locked[k][j] == true)
                {
                    count++;
                    break;

                }
            }

            if (count == candidate_count - 1)
            {
                stopper = 1;
                break;
            }
        }

        if (stopper)
        {
            return;
        }
    }

    return;
}

// Print the winner of the election
void print_winner(void)
{

    bool k = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        k = 1;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == true)
            {
                k = 0;
                break;
            }

        }

        if (k == 1)
        {
            printf("%s\n", candidates[i]);
            return;
        }

    }

}