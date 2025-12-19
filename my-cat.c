#include <stdio.h>
#include <stdlib.h>

void printFile(const char *fileName)
{
    FILE *fileCurr = fopen(fileName, "r"); // open file
    if (fileCurr == NULL)
    {
        printf("my-cat: File can not be opened\n");
        exit(1); // Exit if file cannot be opened
    }

    char buffer[1024]; // Buffer to store each line

    while (fgets(buffer, sizeof(buffer), fileCurr) != NULL)
    {
        printf("%s", buffer); // prints the line
    }

    fclose(fileCurr);
}

int main(int ArgsTotal, char *filenames[])
{
    if (ArgsTotal < 2)
    {
        return 0; // exits if no files are given
    }

    for (int i = 1; i < ArgsTotal; i++) // looping through files
    {
        printFile(filenames[i]);
    }

    return 0;
}
