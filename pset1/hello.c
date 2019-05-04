#include <cs50.h>
#include <stdio.h>

string name;

int main(void)
{
    name = get_string("What is your name?\n");
    printf("hello, %s\n", name);
    return 0;
}
