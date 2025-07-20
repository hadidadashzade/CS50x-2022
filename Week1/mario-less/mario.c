#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("positive number: ");
    }
    while (h < 1 || h > 8);
    h--;
    int n = 0;
    int j;
    int i;
    int x = h;
    int a = 1;
    while (n <= h)
    {
        for (i = 0; i < x; i++)
        {
            printf(" ");
        }
        for (j = 0; j < a; j++)
        {
            printf("#");
        }
        printf("\n");
        n++;
        a++;
        x--;
    }
}