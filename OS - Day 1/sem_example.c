#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <unistd.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
};

int main() {
    key_t key = ftok("semfile", 65);
    int semid = semget(key, 1, 0666 | IPC_CREAT);
    union semun sem_union;
    struct sembuf sem_op;

    sem_union.val = 1;
    semctl(semid, 0, SETVAL, sem_union);

    if (fork() == 0) {
        sem_op.sem_num = 0;
        sem_op.sem_op = -1;
        sem_op.sem_flg = 0;
        semop(semid, &sem_op, 1);
        
        printf("Child Process in Critical Section\n");
        sleep(2);
        printf("Child Process Exiting Critical Section\n");
        
        sem_op.sem_op = 1;
        semop(semid, &sem_op, 1);
    } else {
        sem_op.sem_num = 0;
        sem_op.sem_op = -1;
        sem_op.sem_flg = 0;
        semop(semid, &sem_op, 1);
        
        printf("Parent Process in Critical Section\n");
        sleep(2);
        printf("Parent Process Exiting Critical Section\n");
        
        sem_op.sem_op = 1;
        semop(semid, &sem_op, 1);
        wait(NULL);
        semctl(semid, 0, IPC_RMID);
    }

    return 0;
}
