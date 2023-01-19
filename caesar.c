#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string key = argv[1];
    // Make sure program was run with just one command-line argument
    if (argc !=2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    int n = strlen(key);
    for (int i = 0 ; i < n ; i++)
    {
        if (key[i] < 48 || key[i] > 57)
        {
            printf("Usage: ./caesar key\n");
        }
        return 1;
    }
}