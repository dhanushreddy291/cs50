#include <cs50.h>
#include <stdio.h>

int main(void)
{
   //Gets The Person's Name
   string Name = get_string("What is your Name : ") ;

   //Greets the Person by his name
   printf("hello, %s\n", Name);
}