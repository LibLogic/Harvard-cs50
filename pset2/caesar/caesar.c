#include <cs50.h>
#include <stdio.h>

string pt;
int main(int argc, string argv[])
{
    // print message if one single command line argument is not provided
    if (argc != 2  || atoi(argv[1]) < 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // prompt user for some text to encode
    do
    {
        pt = get_string("plaintext: ");
    }
    while (!pt[0] || pt[0] == ' ');

    // build encoded string
    printf("ciphertext: ");
    int shift, key = atoi(argv[1]) % 26;
    // shift each letter of pt[] string by argv[1] places
    for (int i = 0; i < pt[i]; i++)
    {
        shift = 0;
        // only shift letters a-z and A-Z
        (pt[i] >= 'A' && pt[i] <= 'Z') ? shift = (pt[i] - 'A' + key) % 26 + 'A' :
                (pt[i] >= 'a' && pt[i] <= 'z') ? shift = (pt[i] - 'a' + key) % 26 + 'a' :
                        printf("%c", pt[i]);
        printf("%c", shift);
    }
    printf("\n");
    // return 0;
}