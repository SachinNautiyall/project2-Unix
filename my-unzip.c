#include <stdio.h>
#include <stdlib.h>

void DecompressFile(const char *fileName, FILE *output)
{
    FILE *fileCurr = fopen(fileName, "r");
    if (!fileCurr)
    {
        printf("my-unzip: cannot open file\n");
        exit(1);
    }

    int repeatCount;
    char character;

    while (fread(&repeatCount, sizeof(int), 1, fileCurr) & fread(&character, sizeof(char), 1, fileCurr))     // Read binary pairs count + character and print character repeated
    {
        for (int k = 0; k < repeatCount; k++)
        {
            fputc(character, output);
        }
    }

    fclose(fileCurr);
}

int main(int totalArgs, char *fileList[])
{
    if (totalArgs < 2)
    {
        printf("my-unzip: file1, file2 ...\n");
        return 1;
    }
    for (int i = 1; i < totalArgs; i++)     // Decompress given files
    {
        DecompressFile(fileList[i], stdout);
    }

    return 0;
}
