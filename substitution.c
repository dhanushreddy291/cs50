#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Takes cipher key directly using command line arguement.
int main(int argc, string argv[])
{
    if (argc == 1)
    {
        //If the user doesn't type the key while running the program
        printf("You should also type the key , e.g ./substitution.c key\n") ;
        return 1 ;
    }

    if (strlen(argv[1]) == 26)
    {
        int alphabetcount[26] = {0}, t ;

        for (int i = 0 ; i < 26 ; i++)
        {
            char temp = argv[1][i] ;

            if ((temp >= 'A' && temp <= 'Z'))
            {
                t = ((int)temp) - 65 ;
            }
            else if (temp >= 'a' && temp <= 'z')
            {
                t = ((int)temp) - 97 ;
                argv[1][i] = toupper(argv[1][i]) ;
            }

            if (t >= 0 && t < 26)
            {
                alphabetcount[t]++ ;
            }
            else
            {
                //If the user doesn't enter a Valid Key
                printf("Please, Enter a Valid Key of 26 letters.\n") ;
                return 1 ;

            }
        }

        for (int i = 0 ; i < 26 ; i++)
        {
            if (alphabetcount[i] != 1)
            {
                //If the user doesn't enter a Valid Key
                printf("Please, Enter a Valid Key of 26 letters.\n") ;
                return 1 ;

            }
        }
    }
    else
    {
        //If the user doesn't enter a Valid Key
        printf("Please, Enter a Valid Key of 26 letters.\n") ;
        return 1 ;

    }

    string plaintext = get_string("plaintext: ") ;
    printf("ciphertext: ") ;

    for (int i = 0 ; i < strlen(plaintext) ; i++)
    {
        char temp2 = plaintext[i] ;
        
        //For Printing the corresponding cipher letter of the word when the orginal letter is in Upper Case
        if (isupper(plaintext[i]))
        {
            printf("%c", argv[1][((int)temp2) - 65]) ;
        }
        
        //For Printing the corresponding cipher letter of the word when the orginal letter is in Lower Case
        else if (islower(temp2))
        {
            printf("%c", tolower(argv[1][((int)(toupper(temp2)) - 65)])) ;
        }
        else
        {
            //Doesn't modify the orginal letter when it is not an alphabet.
            printf("%c", temp2) ;
        }

    }

    printf("\n") ;
    return 0 ;

}