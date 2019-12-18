#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>

#define SOCKET_NAME "unixsocket"

int main(void){ // ./socket_client 127.0.0.1
    int sd, len;

    char buf[256];
    struct sockaddr_un server;

    if((sd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1){
        perror("socket");
        exit(1);
    }

    memset((char *)&server, '\0', sizeof(server));

    server.sun_family = AF_UNIX;
    strcpy(server.sun_path, SOCKET_NAME);
    len = sizeof(server.sun_family) + strlen(server.sun_path);

    if(connect(sd, (struct sockaddr *)&server, len) <0){
        perror("connect");
        exit(1);
    }

    strcpy(buf,"Unix Domain Socket Test Message");
    if(send(sd,buf,sizeof(buf), 0) == -1){
        perror("send");
        exit(1);
    }

    close(sd);

    return 0;
}


