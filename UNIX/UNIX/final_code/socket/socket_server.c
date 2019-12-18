#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <sys/un.h>

#define SOCKET_NAME "unixsocket"

int main(void){
    char buf[256];

    struct sockaddr_un server,client;

    int sd, nsd, len, clen;

    if ((sd = socket(AF_UNIX,SOCK_STREAM, 0)) == -1){
        perror("socket");
        exit(1);
    }

    memset((char *)&server, 0, sizeof(struct sockaddr_un));
    server.sun_family = AF_UNIX;
    strcpy(server.sun_path, SOCKET_NAME);
    len = sizeof(server.sun_family) + strlen(server.sun_path);

    if(bind(sd, (struct sockaddr *)&server, len)){
        perror("bind");
        exit(1);
    }

    if(listen(sd,5) <0){
        perror("listen");
        exit(1);
    }

    printf("Waiting...\n");

    if((nsd = accept(sd, (struct sockaddr *)&client, &clen)) == -1){
        perror("accept");
        exit(1);
    }

    if(recv(nsd, buf,sizeof(buf),0) == -1){
        perror("recv");
        exit(1);
    }

    printf("Received Message: %s\n", buf);
    close(nsd);
    close(sd);

    return 0;
}



