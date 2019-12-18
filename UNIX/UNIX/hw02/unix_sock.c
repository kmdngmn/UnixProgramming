#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 1024
#define BUF_SIZE 128
#define SIZE sizeof(struct sockaddr_in)

char buf[BUF_SIZE];

int main(int argc, char *argv[]){
    int client_fd, read_size;
    fd_set fd_ori_set, fd_temp_set;
    struct sockaddr_in client_in;

    if(argc<2){
        printf("Using Program...\n");
        printf("./client IPADDRESS\n");
        exit(1);
    }

    if((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
    {
        perror("socket");
        exit(1);
    }else{
        printf("=========\n");
        printf("Create Socket\n");
        printf("=========\n");
    }

    bzero((char *)&client_in, sizeof(client_in));

    client_in.sin_family = AF_INET;
    client_in.sin_addr.s_addr = inet_addr(argv[1]);
    client_in.sin_port = htons(PORT);

    if(connect(client_fd, (struct sockaddr*)&client_in,SIZE) < 0){
        perror("connect");
        exit(1);
    }
    else{
        printf("Find Server Server IP ADDRESS -> %s \n", argv[1]);
    }

    do{
        FD_ZERO(&fd_ori_set);
        FD_SET(0,&fd_ori_set);
        FD_SET(client_fd,&fd_ori_set);

        fd_temp_set = fd_ori_set;

        select(client_fd+1, &fd_temp_set, NULL, NULL, NULL);

        if(FD_ISSET(0,&fd_temp_set)){
            read_size = read(0, buf,BUF_SIZE);
            write(client_fd, buf, read_size);
        }

        if(FD_ISSET(client_fd, &fd_temp_set)){
            read_size = read(client_fd, buf, BUF_SIZE);
            write(1,buf,read_size);
        }
    }
    while(strncmp(buf,"quit",4)!=0);

    close(client_fd);

    return 0;
}

