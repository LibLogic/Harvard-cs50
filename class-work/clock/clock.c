#include <cs50.h>
#include <stdio.h>

int currentTime;
int newTime;
int cycles;

void clock(int curT, int newT);

int main(void)
{
    do
    {
        currentTime = get_int("Enter current time: ");
    }
    while(currentTime < 0 || currentTime > 12);

    newTime = get_int("Hours to add to current time: ");
    clock(currentTime, newTime);
    printf("New Time is: %i, and the clock \ncycled %i time(s).\n", newTime, cycles);
}

void clock(int curT, int newT)
{
    cycles = abs(newT / 12);
    newTime = abs((curT + newT) % 12);
}