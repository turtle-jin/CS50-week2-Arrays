#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //prompt user for input
    string text = get_string("Text: ");
    //call all the functions
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    //printf("%i letters\n", letters);
    //printf("%i words\n", words);
    //printf("%i sentences\n", sentences);

    //put the formula together
    float L = letters * 100.00 / words;
    float S = sentences * 100.00 / words;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index); //round the float index

    //printf(" L is %f\n", L);
    //printf(" S is %f\n", S);
    //printf(" index is %f\n", index);
    //printf(" grade is %i\n", grade);

    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }

}

int count_letters(string text) //function to count letters
{
    int num_of_letters = 0;

    for (int i = 0, n = strlen(text); i < n ; i++)
    {
        int upper_text = toupper(text[i]);
        if (upper_text >= 65 && upper_text <= 90)  //make sure they are letters
        {
            num_of_letters++;
        }
        else //when they are not letters
        {
            num_of_letters += 0;
        }
    }
    return num_of_letters;
}

int count_words(string text) //function to count words
{
    int sum2 = 1; //note that when the first space is identified, we already have one word, hence sum2 starts with 1 instead of 0

    for (int i = 0, n = strlen(text); i < n ; i++)
    {
        if (text[i] == 32)  //32 is the space
        {
            sum2++;
        }
    }
    return sum2;
}

int count_sentences(string text) //function to count sentences
{
    int sum3 = 0;

    for (int i = 0, n = strlen(text); i < n ; i++)
    {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63) //46 is ".", 33 is "!", and 63 is "?"
        {
            sum3++;
        }
    }
    return sum3;

}