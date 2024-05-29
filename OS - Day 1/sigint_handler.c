#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int sig_num) {
    printf("Received SIGINT (Ctrl+C). Exiting...\n");
    fflush(stdout);
    _exit(0);
}

int main() {
    signal(SIGINT, sigint_handler);

    while (1) {
        printf("Running... Press Ctrl+C to stop.\n");
        sleep(1);
    }

    return 0;
}




// gcc dup_example.c -o dup_example //
// ./dup_example // 
