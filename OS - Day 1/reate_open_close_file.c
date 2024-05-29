#include <stdio.h>

int main() {
    FILE *file = fopen("newfile.txt", "w");
    if (file == NULL) {
        perror("Failed to create file");
        return 1;
    }

    fclose(file);
    printf("File created and closed successfully.\n");
    return 0;
}
