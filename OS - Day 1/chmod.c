#include <stdio.h>
#include <sys/stat.h>

int main() {
    const char *filename = "example.txt";
    mode_t mode = S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH;

    if (chmod(filename, mode) == -1) {
        perror("chmod");
        return 1;
    }
    printf("Permissions changed for %s\n", filename);
    return 0;
}
