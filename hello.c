#include <cs50.h>
#include <stdio.h>

int main(void)
{
   string Name = get_string("What is your Name : ") ;
   printf("hello, %s\n", Name);
}