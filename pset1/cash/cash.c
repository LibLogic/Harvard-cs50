#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_change(int);
float myInput;

int main(void)
{
    // continue prompting user until a float above 0 is entered
    do
    {
        myInput = get_float("Change owed: ");
    }
    while (myInput < 0);
    // convert float to integer for math operations
    int cents = round(myInput * 100);
    int coinCount = get_change(cents);
    printf("%i\n", coinCount);
}

int get_change(int cents)
{
    int coinCount = 0;
    while (cents > 0)
    {
        if (cents >= 25)
        {
            coinCount++;
            cents -= 25;
        }
        else if (cents >= 10)
        {
            coinCount++;
            cents -= 10;
        }
        else if (cents >= 5)
        {
            coinCount++;
            cents -= 5;
        }
        else if (cents >= 1)
        {
            coinCount++;
            cents -= 1;
        }
    }
    return coinCount;
}
