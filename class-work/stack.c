#include <stdio.h>
#include <cs50.h>

int add(int* x, int y)
{
    *x += 5;
    return *x + y;
}
int main(void)
{
    string name = "Cliff";
    printf("Hello, %s\n", name);
    int a = 4;
    int b = 9;
    printf("The total is %i\n", add(&a, b));

    printf("The total the second time %i\n", add(&a, b));
    // int* intPointer = &b;
    // printf("The value of b is %i\n", b);
    // *intPointer = 29;
    // printf("The value of b is %i\n", b);
    // return 0;
}