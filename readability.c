#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main()
{
    //Gets text Input.
    string text = get_string("Text : ") ;
    int lettercount = 0, wordcount = 1, sentencescount = 0, index ;

    //A For Loop for counting the number of letters, words and sentences. 
    for (int i = 0 ; text[i] != '\0' ; i++)
    {
        //isalpha() a functon in ctype.h which checks if the character is alphabet or not.
        if (isalpha(text[i]))
        {
            lettercount++ ;
        }
        else if (text[i] == ' ')
        {
            wordcount++ ;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentencescount++ ;
        }
    }
    
    //Calculation of Index using Coleman-Liau Formula
    index = round(5.88 * (lettercount / (wordcount * 1.00)) - 29.6 * (sentencescount / (wordcount * 1.00)) - 15.8) ;

    //Prints the Grade Level of given text.
    if (index < 1)
    {
        printf("Before Grade 1\n") ;
        return 0 ;
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n") ;
        return 0 ;
    }

    printf("Grade %i\n", index) ;
    return 0 ;

}