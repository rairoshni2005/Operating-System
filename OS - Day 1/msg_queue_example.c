#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;

    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);

    if (fork() == 0) {
        message.msg_type = 1;
        printf("Write Data: ");
        fgets(message.msg_text, sizeof(message.msg_text), stdin);
        msgsnd(msgid, &message, sizeof(message), 0);
    } else {
        msgrcv(msgid, &message, sizeof(message), 1, 0);
        printf("Received Data: %s", message.msg_text);
        msgctl(msgid, IPC_RMID, NULL);
    }

    return 0;
}
