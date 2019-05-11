#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int i = 0;
string pt;
int main(int argc, string argv[])
{
    //reject input if number of args is
    // not exactly one
    if (argc != 2)
    {
        printf("Usage: ./vigenere key\n");
        return 1;
    }
    // check that input is only a-z or A-Z
    else
    {
        while (argv[1][i])
        {
            if (isalpha(argv[1][i]) == 0)
            {
                printf("Usage: ./vigenere key\n");
                return 1;
            }
            i++;
        }
    }
    // prompt user for some text to encode
    do
    {
        pt = get_string("plaintext: ");
    }
    while (!pt[0] || pt[0] == ' ');
    printf("ciphertext: ");
    // make key repeat to the length of plaintext
    int shift, base, j = -1;
    for (i = 0; i < strlen(pt); i++)
    {
        // only move index of key if current letter
        // of plaintext is a-z or A-Z
        if (isalpha(pt[i]))
        {
            j++;
            j = j % strlen(argv[1]);
            shift = argv[1][j] < 'a' ? argv[1][j] - 'A' : argv[1][j] - 'a';
        }
        (pt[i] >= 'a' && pt[i] <= 'z') ?
        printf("%c", (pt[i] - 'a' + shift) % 26 + 'a') :
        (pt[i] >= 'A' && pt[i] <= 'Z') ?
        printf("%c", (pt[i] - 'A' + shift) % 26 + 'A') :
        printf("%c", pt[i]);
    }
    printf("\n");
}
