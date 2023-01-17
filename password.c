// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>


bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool lower = false ;
    bool upper = false ;
    bool number = false ;
    bool symbol = false ;

    for (int i = 0 ; i < strlen(password) ; i++)
    {
        int letter = password[i];

        if (letter >= 97 && letter <= 122)
        {
            lower = true ;
        }
        else if (letter >= 65 && letter <= 90)
        {
            upper = true ;
        }
        else if (letter >= 48 && letter <= 57)
        {
            number = true ;
        }
        else
        {
            symbol = true ;
        }
    }

    if ((lower == true) && (upper == true) && (number == true) && (symbol == true)) //make sure this if statement is outside of the for loop
    {
        return true ;
    }

    return false;
}
