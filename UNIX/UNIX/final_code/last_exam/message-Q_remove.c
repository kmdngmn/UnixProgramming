#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/msg.h>

int main(void){
    key_t key;
    int msgid;

    key = ftok("keyfile", 1);   // create key
    msgid = msgget(key,IPC_CREAT|0644);
    if(msgid == -1){
        perror("msgget");
        exit(1);
    }

    printf("Before IPC_RMID\n");
    system("ipcs -q");
    
    msgctl(msgid, IPC_RMID, (struct msqid_ds *)NULL); // message control -> remove message Q
  
    printf("After IPC_RMID\n");
    system("ipcs -q");

    return 0;
}
