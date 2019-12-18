#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>

struct mymsgbuf{
    long mtype;
    char mtext[80];
};

int main(void){
    key_t key;  // create key

    int msgid;
    struct mymsgbuf mesg;

    key = ftok("keyfile",1); // create key
    msgid = msgget(key, IPC_CREAT|0644);
    if(msgid == -1){
        perror("msgget");
        exit(1);
    }
    
    mesg.mtype = 1;
    strcpy(mesg.mtext, "Message Q Test");

    if(msgsnd(msgid, (void*)&mesg, 80, IPC_NOWAIT) == -1){
        perror("msgsnd");
        exit(1);
    }
    return 0;
}
