#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);


int main(void)
{
    string message = get_string("Message: ");  // ask for user input
    int n = strlen(message);
    int bits_array [BITS_IN_BYTE];  //create an array to store bits


    for (int i = 0 ; i < n ; i++)  //set up the rows numbers
    {
        int num = message[i];

        for (int j = 0 ; j < BITS_IN_BYTE ; j++)
        {
            int bit = num % 2 ;
            bits_array[j] = bit;  //loop through num and store results in array
            num /= 2 ;
        }

        int k = BITS_IN_BYTE - 1 ; //start with the last index
        while (k >= 0)
        {
            print_bulb(bits_array[k]); 
            k--;
        }
        printf("\n");
    }

}
void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}


