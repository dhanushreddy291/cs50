#include <cs50.h>
#include <stdio.h>

int main()
{

    int height;

    do
    {
        //Loop doesnot exit until the user inputs a number between 1 to 8 inclusive
        height = get_int("Height : ") ;

    }
    while (height < 1 || height > 8);

    int spacescount = height - 1 ;

    //A loop to print require Pyramid
    for (int i = 0 ; i < height ; i++)
    {

        for (int j = 0 ; j < spacescount ; j++)
        {
            //Prints Empty Spaces
            printf(" ");

        }

        for (int j = 0 ; j < i + 1 ; j++)
        {
            //Prints #
            printf("#");
        }

        printf("\n");
        spacescount--;

    }
}