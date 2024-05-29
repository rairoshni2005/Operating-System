#include <stdio.h>

int main() {
    FILE *file;

    // Mode 1: "r" - Read
    file = fopen("example.txt", "r");
    if (file != NULL) {
        printf("File opened in read mode.\n");
        fclose(file);
    } else {
        printf("Failed to open file in read mode.\n");
    }

    // Mode 2: "w" - Write
    file = fopen("example.txt", "w");
    if (file != NULL) {
        printf("File opened in write mode.\n");
        fclose(file);
    } else {
        printf("Failed to open file in write mode.\n");
    }

    // Mode 3: "a" - Append
    file = fopen("example.txt", "a");
    if (file != NULL) {
        printf("File opened in append mode.\n");
        fclose(file);
    } else {
        printf("Failed to open file in append mode.\n");
    }

    // Mode 4: "r+" - Read and Write
    file = fopen("example.txt", "r+");
    if (file != NULL) {
        printf("File opened in read and write mode.\n");
        fclose(file);
    } else {
        printf("Failed to open file in read and write mode.\n");
    }

    // Mode 5: "w+" - Write and Read
    file = fopen("example.txt", "w+");
    if (file != NULL) {
        printf("File opened in write and read mode.\n");
        fclose(file);
    } else {
        printf("Failed to open file in write and read mode.\n");
    }

    return 0;
}
