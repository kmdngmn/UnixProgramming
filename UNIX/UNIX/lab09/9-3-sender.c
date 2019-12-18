#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/msg.h>
#include <string.h>

struct mymsbuf {
    long mtype;
    char mtext[80];
};

int main(void){
    
    key_t key;
    int msgid;
    struct mymsbuf mesg;
    int i;

    key = ftok("msgfile", 1);
    msgid = msgget(key, IPC_CREAT|0644);
    if(msgid == -1){
        perror("msgget");
        exit(1);
    }
    
    mesg.mtype = 1;
    strcpy(mesg.mtext, "my message\n");
    
    for(i = 0; i < 10; i++){
        if(msgsnd(msgid, (void *)&mesg, 80, IPC_NOWAIT) == -1){
            perror("msgsnd");
        }
    }

    return 0;
}

