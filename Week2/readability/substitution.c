#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <ctype.h>

int main(int ac, string av[])
{
    void ste();
    void ara(char ps, string ky);
    
    if (ac == 2)
    {
        if (strlen(av[1]) == 26)
        {
            for (int n = 0; n < strlen(av[1]); n++)
            {
                if (!isalpha(av[1][n]))
                {
                    printf("Key must contain 26 characters.");
                    printf("\n");
                    return 1;
                }
                for (int b = n + 1 ; b < strlen(av[1]) ; b++)
                {
    
                    if (toupper(av[1][n]) == toupper(av[1][b]))
                    {
                        printf("Key must not contain repeated alphabets.");
                        printf("\n");
                        return 1;
                    }
                }
            }
            ste(av[1]);
            
        }
        else
        {
            printf("Key must contain 26 characters.");
            printf("\n");
            return 1;
        }
        
    }
    else
    {
        printf("Usage: ./substitution key");
        printf("\n");
        return 1;
    }
    return 0;
}

void ste(string ky)
{
    string k = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int n = 0; n < strlen(k); n++)
    {
        if (isalpha(k[n]))
        {
            char y = k[n];
            if (islower(k[n]))
            {
                ara(tolower(y), ky);
            }
            else
            {
                ara(toupper(y), ky);
            }


        }
        else
        {
            printf("%c", k[n]);
        }
    }

    printf("\n");

}
void ara(char ps, string ky)
{
    string aa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int n = 0; n < strlen(aa); n++)
    {
        if (islower(ps))
        {
            if (ps == tolower(aa[n]))
            {
                printf("%c", tolower(ky[n]));
            }
        }
        else
        {
            if (ps == toupper(aa[n]))
            {
                printf("%c", toupper(ky[n]));
            }
        }
    }
}