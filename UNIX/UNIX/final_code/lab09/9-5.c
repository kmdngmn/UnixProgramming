#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <string.h>

int main(void){
    key_t key;
    int shmid;

    char *shmaddr;

    key = ftok("shmfile", 1);
    shmid = shmget(key, 1024, IPC_CREAT|0644);
    shmaddr = shmat(shmid, NULL,0);

    strcpy(shmaddr,"shared memory test");

    shmdt((char *)shmaddr);

    return 0;
}

