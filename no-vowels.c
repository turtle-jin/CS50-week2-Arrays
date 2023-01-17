// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string replace(string text);

int main(int argc, string argv[])
{
    string text = argv[1];
    if (argc != 2)
    {
        printf("Make sure you enter a text!\n");
        return 1;
    }

    // call the replace function
    string new_text = replace(text); // do not directly use argv as an argument when you call the function
    printf("%s\n", new_text);
    return 0;

}

string replace(string text)
{
    int n = strlen(text);
    for (int i = 0 ; i < n ; i++)
    {
        switch (text[i])
        {
            case 'a':
                text[i] = '6' ;  //make sure the data type match when you do the switch
                break;

            case 'e':
                text[i] = '3' ;
                break;

            case 'i':
                text[i] = '1' ;
                break;

            case 'o':
                text[i] = '0' ;
                break;

            default:
                text[i] = text[i];
        }

    }
    return text;

}