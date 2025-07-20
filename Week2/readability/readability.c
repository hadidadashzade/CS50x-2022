//readability : hadi dadashzadeh
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int ws = 0;
    int ls = 0;
    int ss = 0;
    
    string text = get_string("Text: ");

    int b = strlen(text);

    for (int n = 0; n < b; n++)
    {
        char c = text[n];
        
        if (isupper(c))
        {
            if (isalpha(c) != 0)
            {
                ls = ls + 1;
            }
        }
        else if (islower(c))
        {
            if (isalpha(c) != 0)
            {
                ls = ls + 1;
            }
        }
        else if (isspace(c))
        {
            ws = ws + 1;
        }
        else if (c == '.')
        {
            ss = ss + 1;
        }
        else if (c == '?')
        {
            ss = ss + 1;
        }
        else if (c == '!')
        {
            ss = ss + 1;
        }
    }

    ws++;

    float L = ((float)ls / (float)ws) * 100;
    float s = ((float)ss / (float)ws) * 100;
    float subindex = 0.0588 * L - 0.296 * s - 15.8;
    
    int index = round(subindex);
    
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}
