#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./recover filename\n");
        return 1;
    }

     FILE *inptr = fopen(argv[1], "r");
     if (inptr == NULL)
    {
        printf("Could not open the required file, %s.\n", argv[1]);
        return 1;
    }

    FILE *outptr = NULL;
    int count = 0, foundjpeg = 0, firstjpeg = 1;
    char filename[8];
    unsigned char buffer[512];

    while (fread(buffer, 512, 1, inptr) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if(firstjpeg)
            {
                sprintf(filename, "%03i.jpg", count++);
                outptr = fopen(filename, "a");
                fwrite(buffer, 512, 1, outptr);
                firstjpeg = 0;
                foundjpeg = 1;

            }
            else
            {
                sprintf(filename, "%03i.jpg", count++);
                fclose(outptr);
                outptr = fopen(filename, "a");
                fwrite(buffer, 512, 1, outptr);

            }

        }
        else if(foundjpeg)
        {
            //outptr = fopen(filename, "a");
            fwrite(buffer, 512, 1, outptr);

        }
    }

fclose(outptr);
fclose(inptr);

        return 0;
}
