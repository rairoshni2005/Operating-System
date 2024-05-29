#include <stdio.h>

int main() {
    FILE *file = fopen("hello.txt", "w");
    if (file == NULL) {
        perror("Failed to create file");
        return 1;
    }

    fprintf(file, "Hello, World!\n");

    fclose(file);
    printf("Message written to file successfully.\n");
    return 0;
}
