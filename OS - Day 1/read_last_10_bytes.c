#include <stdio.h>

int main() {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    fseek(file, -10, SEEK_END);
    char buffer[11]; // 10 bytes + 1 for null terminator
    size_t bytesRead = fread(buffer, 1, 10, file);
    buffer[bytesRead] = '\0'; // Null-terminate the string

    printf("Last 10 bytes: %s\n", buffer);

    fclose(file);
    return 0;
}
