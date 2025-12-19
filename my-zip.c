#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compressFile(const char *fileName, FILE *output) {
    FILE *fileCurr = fopen(fileName, "r");
    if (!fileCurr) {
        printf("my-zip: cannot open file\n");
        exit(1);
    }

    int count = 1;
    char current, previous;
    previous = fgetc(fileCurr);

    while ((current = fgetc(fileCurr)) != EOF) {     // Count repeated characters
        if (current == previous) {
            count++;
        } else {
            fwrite(&count, sizeof(int), 1, output);
            fwrite(&previous, sizeof(char), 1, output);
            count = 1;
            previous = current;
        }
    }

    fwrite(&count, sizeof(int), 1, output);     // Writing last characters
    fwrite(&previous, sizeof(char), 1, output);

    fclose(fileCurr);
}

int main(int totalArgs, char *fileList[]) {
    if (totalArgs < 2) {
        printf("my-zip: file1, file2 ...]\n");
        return 1;
    }

    for (int i = 1; i < totalArgs; i++) {     // Compress each file into a single output
        compressFile(fileList[i], stdout);
    }

    return 0;
}
