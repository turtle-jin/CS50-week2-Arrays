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
            return 1;
        }
        
    }
// Convert argv[1] from a `string` to an `int`
    int k = atoi(key);

    // Prompt user for plaintext

    string p_text = get_string("plaintext:  ");
    printf("ciphertext: ");

    int len = strlen(p_text);

    for (int j = 0 ; j < len ; j++)
    {
        char c = p_text[j];
        //printf("%c\n", c );
        char c_text = rotate(c, k);
        printf("%c", c_text);
    }
    printf("\n");

}

char rotate(char character, int k) //function to rotate each char
{
    int cipher_letter = 0;
    if (isalpha(character) && isupper(character))  // if alphabetic , shift plaintext by key, preserving case
    {

        cipher_letter = (((int)character - 65 + k) % 26) + 65;
    }
    else if (isalpha(character) && islower(character))
    {
        cipher_letter = (((int)character - 97 + k) % 26) + 97;
    }
    else
    {
        cipher_letter += (int)character;
    }

    return (char)cipher_letter;
}
