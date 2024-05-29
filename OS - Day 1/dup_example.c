#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    int fd_dup = dup(fd);
    if (fd_dup < 0) {
        perror("dup");
        close(fd);
        return 1;
    }

    write(fd, "Hello from fd\n", 14);
    write(fd_dup, "Hello from fd_dup\n", 19);

    close(fd);
    close(fd_dup);
    return 0;
}
