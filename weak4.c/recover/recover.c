#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define BLOCK_SIZE 512
typedef uint8_t BYTE;
int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    FILE *FP = fopen(argv[1],"r");
    if(FP == NULL)
    {
        printf("ERROR OPEN FILE\n");
        return 1;
    }
    int i = 0;
    BYTE buffer[BLOCK_SIZE];
    char nombre[8];
    FILE *img = NULL;
    while(!feof(FP))
    {
        while (fread(buffer, 1, BLOCK_SIZE, FP) == BLOCK_SIZE)
        {
            if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff
            && (buffer[3] & 0xf0) == 0xe0)
            {
                if(i == 0)
                {
                    sprintf(nombre,"%03i.jpg",i);
                    img = fopen(nombre,"w");
                    fwrite(buffer,1,sizeof(buffer),img);
                    i++;
                }
                else
                {
                    fclose(img);
                    sprintf(nombre,"%03i.jpg",i);
                    img = fopen(nombre,"w");
                    fwrite(buffer,1,sizeof(buffer),img);
                    i++;
                }

            }
            else if(i > 0)
            {
                fwrite(buffer,1,sizeof(buffer),img);
            }

        }
    }
    fclose(FP);
    fclose(img);
    return 0;
}