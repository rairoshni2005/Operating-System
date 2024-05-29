#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signum) {
    printf("Received signal %d\n", signum);
}

int main() {
    signal(SIGUSR1, signal_handler);

    printf("Waiting for signal...\n");
    while (1) {
        sleep(1);
    }

    return 0;
}
