#include <cs50.h>
#include <stdio.h>
#include <math.h>

string getCardType(long ccNumber);
bool isValid(long ccNumber);
long ccNumber;

int main(void)
{
    // prompt user for ccNumber
    ccNumber = get_long("Number: ");
    printf("%s\n", isValid(ccNumber) ?  getCardType(ccNumber) : "INVALID");
}

string getCardType(long number)
{
    int n = 0;
    long tempNum = number;
    // count number of digits in ccNumber
    while (tempNum)
    {
        tempNum /= 10;
        n++;
    }
    string cardType = "";
    // get first 2 digit of ccNumber
    number /= pow(10, n - 2);
    // get card type based on first 2 digits
    if (n == 16 && (number > 39 && number < 50))
    {
        cardType = "VISA";
    }
    else if ((n == 13 || n == 16) && (number > 50 && number < 56))
    {
        cardType = "MASTERCARD";
    }
    else if (n == 15 && (number == 34 || number == 37))
    {
        cardType = "AMEX";
    } else
    {
        cardType = "INVALID";
    }
    return cardType;
}

// check if valid ccNumber
bool isValid(long ccNum)
{
    int A = 0, B = 0, index = 0;
    // my implementaion of Luhn's algorithm for ccNumber check
    while (ccNum)
    {
        A += ccNum % 10;
        ccNum /= 10;
        B += (ccNum % 10) * 2 >= 10 ? ((ccNum * 2) % 10) + 1 : (ccNum % 10) * 2;
        ccNum /= 10;
        index++;
    }
    bool x = (A + B) % 10 != 0 ? false : true;
    return x;
}