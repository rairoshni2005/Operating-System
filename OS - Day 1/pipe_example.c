#include <stdio.h>
#include <unistd.h>

int main() {
    int pipefd[2];
    char buf[30];
    pipe(pipefd);

    if (fork() == 0) {
        close(pipefd[1]);
        read(pipefd[0], buf, sizeof(buf));
        printf("Child received: %s\n", buf);
        close(pipefd[0]);
    } else {
        close(pipefd[0]);
        write(pipefd[1], "Hello from parent", 17);
        close(pipefd[1]);
    }

    return 0;
}
