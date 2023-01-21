#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char substitute(char c, string k);

int main(int argc, string argv[])
{
    string key = argv[1];

    if (argc != 2) //make sure just one command-line argument allowed
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    int n = strlen(key);
    for (int i = 0 ; i < n ; i++)
    {
        if (isalpha(key[i]))  //make sure key only contains letters
        {
            if (n == 26) //make sure key contains 26 letters
            {
                //make sure each letter only appears once
                for (int j = 0 ; j < i ; j++)
                {
                    if (key[j] == key[i])
                    {
                        printf("Key must not contain repeated characters!\n");
                        return 1;
                    }
                }
            }
            else
            {
                printf("Key must contain 26 characters.\n");
                return 1;
            }
        }
        else
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }

    string p_text = get_string("Plaintext:  "); //prompt for input
    printf("ciphertext: ");

    int len = strlen(p_text);

    for (int i = 0 ; i < len ; i++)
    {
        char c = p_text[i];
        char cipher_text = substitute(c, key);
        printf("%c", cipher_text);
    }
    printf("\n");

}

char substitute(char c, string k) // function to substitute chars
{
    int cipher_letter = 0 ;
    if (isalpha(c) && isupper(c))  //when c is a uppercase letter
    {
        int index = (int)c - 65;
        cipher_letter = toupper(k[index]);  //change back to uppercase
    }
    else if (isalpha(c) && islower(c))  //when c is a lowercase letter
    {
        int index = (int)c - 97;
        cipher_letter = tolower(k[index]);  //change back to lowercase
    }
    else
    {
        cipher_letter += (int)c;  //when c is not an alphabetical char, it stays the same.
    }

    return (char) cipher_letter;

}
