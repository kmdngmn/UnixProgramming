#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <errno.h>

union semun{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int initsem(key_t semkey){
    union semun semunarg;
    int status = 0, semid;

    semid = semget(semkey, 1, IPC_CREAT|IPC_EXCL|0600); // create semaphore
    if(semid == -1){
        if(errno == EEXIST){
            semid = semget(semkey, 1, 0);
        }
    }else{
        semunarg.val = 1;   // initialization semaphore=1
        status = semctl(semid, 0, SETVAL, semunarg);
    }

    if(semid == -1 || status == -1){
        perror("initsem");
        return (-1);
    }

    return semid;
}

int semlock(int semid){
    struct sembuf buf;

    buf.sem_num = 0;
    buf.sem_op = -1;    // semaphore lock
    buf.sem_flg = SEM_UNDO;
    if(semop(semid, &buf,1) == -1){
        perror("semlock failed");
        exit(1);
    }
    return 0;
}

int semunlock(int semid){
    struct sembuf buf;

    buf.sem_num = 0;
    buf.sem_op = 1;     // semaphore unlock
    buf.sem_flg = SEM_UNDO;
    if(semop(semid, &buf,1) == -1){
        perror("semunlock failed");
        exit(1);
    }
    return 0;
}

void semhandle(){
    int semid;
    pid_t pid = getpid();

    if((semid = initsem(1)) < 0){
        exit(1);
    }

    semlock(semid); // synchronized
    printf("Lock : Process %d\n", (int)pid);
    printf("** Lock Mode : Critical Section\n");
    sleep(1);
    printf("Unlock : Process %d\n", (int)pid);
    semunlock(semid);   // synchronized

    exit(0);
}

int main(void){
    int a;
    for(a = 0; a<3; a++){
        if(fork() == 0){
            semhandle();
        }
    }
    return 0;

}


