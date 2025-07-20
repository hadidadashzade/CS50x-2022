//cs50x * Problem Set * plurality//me: hadi dadashzadeh
#include <cs50.h>
#include <string.h>
#include <stdio.h>
#define max 9

typedef struct
{
    string name;
    int votes;
}

cate;
cate candidates[max];

int candidate_count;
bool vote(string name);
void print_winner(void);

int main(int ac, string av[])
{
    if (ac < 2)
    {
        printf("Usage: plurality [candidate ...]");
        return 1;
        printf("\n");
    }

    candidate_count = ac - 1;
    if (candidate_count > max)
    {
        printf("Maximum number of candidates is");
        printf(" %i", max);
        return 2;
        printf("\n");
    }
    for (int h = 0; h < candidate_count; h++)
    {
        candidates[h].name = av[h = h + 1];
        candidates[h].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    for (int m = 0; m < voter_count; m++)
    {
        string name = get_string("Vote: ");
        
        if (!vote(name))
        {
            printf("Invalid vote.");
            printf("\n");
        }
    }

    print_winner();
}

bool vote(string name)
{
    for (int p = 0; p < candidate_count; p++)
    {
        if (strcmp(candidates[p].name, name) == 0)
        {
            candidates[p].votes++;
            return true;
        }
    }
    return false;
}

void print_winner(void)
{
    int maximum_vote = 0;

    for (int l = 0; l < candidate_count; l++)
    {
        if (candidates[l].votes > maximum_vote)
        {
            maximum_vote = candidates[l].votes;
        }
    }

    for (int k = 0; k < candidate_count; k++)
    {
        if (candidates[k].votes == maximum_vote)
        {
            printf("%s", candidates[k].name);
            printf("\n");
        }
    }

    return;
}