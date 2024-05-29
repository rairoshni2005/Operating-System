#include <stdio.h>

int main() {
    FILE *sourceFile = fopen("source.txt", "r");
    if (sourceFile == NULL) {
        perror("Failed to open source file");
        return 1;
    }

    FILE *destFile = fopen("destination.txt", "w");
    if (destFile == NULL) {
        perror("Failed to open destination file");
        fclose(sourceFile);
        return 1;
    }

    char ch;
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    fclose(sourceFile);
    fclose(destFile);
    printf("File copied successfully.\n");
    return 0;
}
