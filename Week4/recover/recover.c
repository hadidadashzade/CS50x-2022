#include <stdio.h>
#include <stdlib.h>

//stdint.h : typedef uint8_t
#include <stdint.h> //typedef uint8_t

int main(int argc, char *argv[])
{
    typedef uint8_t ty;
    
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover infile");
        return 1;
        printf("\n");
    }

    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open ", argv[1]);
        printf("%s.", argv[1]);
        return 2;
        printf("\n");
    }
    
    FILE *OP = NULL;
    
    ty buffer[512];
 
    int jpgf = 0;
    
    char filename[8] = {0};
    
    while (fread(buffer, sizeof(ty) * 512, 1, inptr) == 1)
    {
        if (buffer[0] == 0xFF && buffer[1] == 0xD8 && buffer[2] == 0xFF && (buffer[3] & 0xF0) == 0xE0)
        {
            if (OP != NULL)
            {
                fclose(OP); 
            }
            sprintf(filename, "%03d.jpg", jpgf++);
                
            OP = fopen(filename, "w");
        }
       
        if (OP != NULL)
        {
            fwrite(buffer, sizeof(ty) * 512, 1, OP);
        }
    }
    
    if (OP != NULL)
    {
        fclose(OP);
    }
    
    fclose(inptr);
    
    return 0;
}
