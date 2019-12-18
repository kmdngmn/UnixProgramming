#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/shm.h>

int main(void){
    key_t key;
    int shmid;
    char *shmaddr;

    key = ftok("shmfie", 1);
    shmid = shmget(key, 1024, IPC_CREAT|0644);
    if(shmid == -1){
        perror("shmget");
        exit(1);
    }

    shmaddr = shmat(shmid, NULL, 0);
    strcpy(shmaddr, "shared memory test");
    shmdt((char *)shmaddr);

    return 0;
}


