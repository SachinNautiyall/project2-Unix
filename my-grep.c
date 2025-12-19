#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void searchInFile(const char *fileName, const char *searchTerm) {
    FILE *currFile = fopen(fileName, "r");

    if (currFile == NULL) {
        printf("my-grep: cannot open file\n");
        exit(1);
    }

    char lineBuffer[4096];  // buffer for each line

    while (fgets(lineBuffer, sizeof(lineBuffer), currFile) != NULL) {
        if (strstr(lineBuffer, searchTerm) != NULL) { // Print line if it contains search term
            printf("%s", lineBuffer);
        }
    }

    fclose(currFile);     // Free buffer and Close the file
}

int main(int totalArgs, char *fileList[]) {
    if (totalArgs < 2) {
        printf("my-grep: searchterm, file ...]\n");
        return 1;
    }

    const char *searchTerm = fileList[1];

    if (totalArgs == 2) {
        char lineBuffer[4096];
        while (fgets(lineBuffer, sizeof(lineBuffer), stdin) != NULL) {
            if (strstr(lineBuffer, searchTerm) != NULL) {
                printf("%s", lineBuffer);
            }
        }
        return 0;
    }

    for (int i = 2; i < totalArgs; i++) { // looping through files from second argument
        searchInFile(fileList[i], searchTerm);
    }

    return 0;
}
