#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        printf("Child process (PID: %d)\n", getpid());
        sleep(2);
    } else {
        wait(NULL);
        printf("Parent process (PID: %d) - Child has finished\n", getpid());
    }

    return 0;
}
