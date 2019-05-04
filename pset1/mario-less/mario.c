#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    for (int i = 1; i <= n; i++)
    {
        int z = n - i;
        while (z)
        {
            printf(" ");
            z--;
        }
        for (int j = i; j > 0; j--)
        {
            printf("#");
        }
        printf("\n");
    }
}