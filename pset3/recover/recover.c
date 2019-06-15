#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover <filename>\n");
        return 1;
    }

    // open file to recover
    FILE *file_ptr = fopen(argv[1], "r");

    if (file_ptr == NULL)
    {
        printf("Could not open file \"%s\"\n", argv[1]);
        return 2;
    }

    uint8_t buffer[512];
    int imgCount = 0; // used to create working file name
    char workFile[20] = "empty.jpg";
    FILE *fileName_ptr = fopen(workFile, "w");

    while (fread(buffer, sizeof(buffer), 1, file_ptr))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // start a new file whenever we find a header block
            fclose(fileName_ptr);

            // generate working file name
            sprintf(workFile, "%03d.jpg", imgCount);
            imgCount++;
            fileName_ptr = fopen(workFile, "w");
            fwrite(&buffer, sizeof(buffer), 1, fileName_ptr);
        }
        else if (imgCount > 0) // makes sure we hae a header block first
        {
            fwrite(&buffer, sizeof(buffer), 1, fileName_ptr);
        }
    }

    fclose(file_ptr);
}