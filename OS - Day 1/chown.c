#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    const char *filename = "example.txt";
    uid_t owner = 1000; // Example user ID
    gid_t group = 1000; // Example group ID

    if (chown(filename, owner, group) == -1) {
        perror("chown");
        return 1;
    }
    printf("Owner and group changed for %s\n", filename);
    return 0;
}
