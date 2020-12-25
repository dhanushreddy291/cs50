#include <cs50.h>
#include <stdio.h>

int main()
{
    //Gets the Card Number from the user..
    long cardnumber = get_long("Number : ");

    long temp = cardnumber;
    int size = 0, sum = 0, x = 1, hundredsplace;

    while (temp != 0)
    {
        //To find the length of the Card Number and the First Two Digits.
        temp /= 10;
        size++;

        if (temp < 100 && temp > 9)
        {
            hundredsplace = temp;

        }
    }

    temp = cardnumber;

    if (size == 13 || size == 15 || size == 16)
    {

        //To check in which category the given card falls into.
        while (temp != 0)
        {
            if (x == 1)
            {
                sum += temp % 10;
                x = 0;

            }
            else
            {
                sum += (2 * (temp % 10) % 10) + (2 * (temp % 10) / 10);
                x = 1;
                
            }
            
            temp /= 10;

        }

        if (sum % 10 == 0)
        {
            //Checks if Card is a valid American Express Card
            if (size == 15 && (hundredsplace == 34 || hundredsplace == 37))
            {
                printf("AMERICAN EXPRESS\n");
                return 0;

            }
            //Checks if  Card is a valid Mastercard
            else if (size == 16 && (hundredsplace > 50 && hundredsplace < 56))
            {
                printf("MASTERCARD\n");
                return 0;

            }
            //Checks if  Card is a valid VISA Card
            else if ((size == 13 || size == 16) && hundredsplace / 10 == 4)
            {
                printf("VISA\n");
                return 0;

            }
        }
    }

    //Prints Invalid if card is not a Valid Credit Card.
    printf("INVALID\n");
    return 0;

}