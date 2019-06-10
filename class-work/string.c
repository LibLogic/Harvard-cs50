#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char* name;
    // name = malloc(sizeof(char) * 6);
    name = "Tom Hodgkinson";
    for (int i = strlen(name); i >= 0; i--)
    {
        printf("%c", name[i]);
    }

}



