#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 30

void read_childproc(int sig);

char webpage[]= "HTTP/1.1 200 OK\r\n"
                "Content-Type:text/html; charset=UTF-8\r\n\r\n"               
                "<%String esntlId = \"123\";%>\r\n"
                "<!DOCTYPE html>\r\n"
                "<html><head><title>web title</title></head>\r\n"
                "<body>helloworld</body>\r\n"
                "</html>\r\n";

int main(int argc, char *argv[]){

    int serv_sock, clnt_sock;

    struct sockaddr_in serv_adr, clnt_adr;
    pid_t pid;

    struct sigaction act;
    socklen_t adr_sz;

    int str_len, state;
    char buf[BUF_SIZE];
    if(argc != 2){
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }

    act.sa_handler=read_childproc;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;

    state= sigaction(SIGCHLD,&act,0);
    serv_sock=socket(PF_INET,SOCK_STREAM,0);
    memset(&serv_adr, 0, sizeof(serv_adr));

    serv_adr.sin_family=AF_INET;
    serv_adr.sin_addr.s_addr=htonl(INADDR_ANY);
    serv_adr.sin_port=htons(atoi(argv[1]));

    if(bind(serv_sock,(struct sockaddr*) &serv_adr, sizeof(serv_adr)) == -1){
        perror("bind");
        exit(1);
    }
    if(listen(serv_sock,5) == -1){
        perror("listen");
        exit(1);
    }

    while(1){
        adr_sz=sizeof(clnt_adr);
        clnt_sock=accept(serv_sock,(struct sockaddr*)&clnt_adr, &adr_sz);
        if(clnt_sock==-1){
            continue;
        }
        if(pid==0){
            close(serv_sock);
            write(clnt_sock,webpage,sizeof(webpage));
            close(clnt_sock);
            puts("client disconnected");
            return 0;
        }
        else{
            close(clnt_sock);
        }
    }
    close(serv_sock);
    return 0;
}

void read_childproc(int sig){
    pid_t pid;
    int status;
    pid=waitpid(-1,&status, WNOHANG);
    printf("removed proc id : %d \n", pid);
}


