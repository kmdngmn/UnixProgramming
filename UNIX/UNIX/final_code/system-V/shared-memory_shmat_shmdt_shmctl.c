#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/wait.h>

int main(void){
    int shmid, i;
    char *shmaddr, *shmaddr2;

    shmid = shmget(IPC_PRIVATE, 20, IPC_CREAT|0644); // shared memory create
    if(shmid == -1){
        perror("shmget");
        exit(1);
    }

    switch(fork()){
        case -1:
            perror("fork");
            exit(1);
            break;

        case 0:
            shmaddr = (char *)shmat(shmid, (char *)NULL, 0);    // shared memory attach
            
            printf("Child Process =====\n");
            for(i = 0; i < 10; i++){
                shmaddr[i] = 'a' + i;
            }

            shmdt((char *)shmaddr);     // shared memory detach
            exit(0);
            break;

        default:
            wait(0);
            shmaddr2 = (char *)shmat(shmid, (char *)NULL, 0);   // attach
            printf("Parent Process =====\n");
            for(i=0; i<10; i++){
                printf("%c ", shmaddr2[i]);
            }
            printf("\n");
            sleep(5);
            shmdt((char *)shmaddr2);

            printf("Before shmctl----\n");
            system("ipcs -m");
            
            shmctl(shmid, IPC_RMID, (struct shmid_ds *)NULL);
            
            printf("After shmctl----\n");
            system("ipcs -m");
            
            break;
    }

    return 0;
}

