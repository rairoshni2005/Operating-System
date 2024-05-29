#include <stdio.h>

int main() {
    FILE *file = fopen("example.txt", "a");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    fprintf(file, "End of File\n");

    fclose(file);
    printf("Message appended to file successfully.\n");
    return 0;
}
