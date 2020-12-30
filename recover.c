#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    //If there was no name of file while running the command at terminal.
    if (argc < 2)
    {
        printf("Usage: ./recover filename\n");
        return 1;
    }

    FILE *inptr = fopen(argv[1], "r");

    //If there is no sufficient memory, to avoid segmentation fault.
    if (inptr == NULL)
    {
        printf("Could not open the required file, %s.\n", argv[1]);
        return 1;
    }

    FILE *outptr = NULL;
    int count = 0, foundjpeg = 0, firstjpeg = 1;
    char filename[8];

    //For storing 512 bytes of data on each iteration.
    unsigned char buffer[512];

    //Reads 512 bytes of data at a single time from inptr and stores temporarily in the buffer array.
    //Loop ends during end of file.
    while (fread(buffer, 512, 1, inptr) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //Only runs for the first jpeg forming time.
            if (firstjpeg)
            {
                //sprint is used for changing the filename, i.e from 000.jpg to 001.jpg etc.
                sprintf(filename, "%03i.jpg", count++);
                outptr = fopen(filename, "a");

                //Writes 512 bytes of data at a single time from buffer to the file pointed by outptr.
                fwrite(buffer, 512, 1, outptr);
                firstjpeg = 0;
                foundjpeg = 1;

            }
            else
            {
                sprintf(filename, "%03i.jpg", count++);

                //Closes the Previous File.
                fclose(outptr);

                //Initializes outptr to a fresh jpg file pointer address.
                outptr = fopen(filename, "a");
                fwrite(buffer, 512, 1, outptr);

            }

        }
        else if (foundjpeg)
        {
            fwrite(buffer, 512, 1, outptr);
        }
    }

    //Closes all the Files before the program ends.
    fclose(outptr);
    fclose(inptr);

    return 0;
    
}
