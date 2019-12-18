#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <fcntl.h>
#include <time.h>
    
#define PORT 7017   // port number
#define MAXPENDING 5
#define BUFSIZE 1024

/* image */
void receiveImage(int socket){
    int c;

    FILE *rfp;
    FILE *stream;

    rfp = fdopen(socket,"r");
    stream = fopen("sheep.jpg","wb");

    while((c=fgetc(rfp)) != EOF){
        fputc(c,stream);
    }
    fclose(rfp);
    fclose(stream);
}

/* log stamp */
void stamp_log(char logbuf[]){
    
    FILE *lfp;  // log file pointer
    char buf[256];  

    int n;

    lfp = fopen("log.txt","a"); // append

    int wordlen = 0;    // length of word

    /* count length of word */
    for(int i = 0; i < sizeof(buf); i++){

        if(logbuf[i] >= 0 && logbuf[i] <= 127){ // in ASCII
            wordlen++;
        }
        else{
            break;
        }
    }

    strcpy(buf,logbuf);
    buf[wordlen] ='\0';

    fputs(buf,lfp); // put string in log.txt

    fclose(lfp);
}

                
int main(int argc, char *argv[])
{
    int sockfd, servsockfd;
    struct sockaddr_in serv_addr;
    int servlen,recvlen;    
    char recvbuff[1024];    // receive buffer
    time_t ticks;
    size_t fpsize=0, fsize=0;

    /* FILE function */
    char buff[1024];
    char path[]="/home/ubuntu/UNIX/hw02/server/";   // location of file for transfer
    FILE *fp = NULL;

    time_t t = time(NULL);         // log stamp time
    struct tm tm = *localtime(&t); // log stamp time

    char console[256];             // log stamp buffer

    int filelen = 0; // length of filename

    sprintf(console,"\n\n---------- %d-%d-%d %2d:%2d:%2d ----------\n\n",tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    stamp_log(console);

    /* create socket */
    if((sockfd=socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket failed\n");
        close(1);
    }
 
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);  // htonl
    serv_addr.sin_port = htons(PORT);               // htons

    /* bind */
    if(bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind failed\n");
        close(1);
    }

    /* listen */
    if(listen(sockfd,MAXPENDING) == -1 ){
        perror("listen failed\n");
        close(1);
    }

    sprintf(console,"Wait for the Client to connect...\n");
    stamp_log(console);
    puts(console);
    
    servlen = sizeof(serv_addr);
    
    /* accept */
    if((servsockfd=accept(sockfd, (struct sockaddr*)&serv_addr, &servlen)) == -1) {
        perror("accept failed\n");
        close(1);
    }

    /* Get a local Socket information */
    getpeername(servsockfd, (struct sockaddr *)&serv_addr, &servlen);
    
    sprintf(console,"[Client Connection] IP: %s , Port: %d\n",inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));
    stamp_log(console);
    puts(console);

    while(1)
    {   
        /* receive */
        if((recvlen=recv(servsockfd, recvbuff, BUFSIZE-1, 0)) == -1) {
            perror("recv failed\n");
            break;
        }

        /* If has receive data */
        if(recvlen > 0)
        {
            recvbuff[recvlen] = 0x00;     
            
            /* image */
            if(strlen(recvbuff)==2 && !strncmp(recvbuff,"i",1)){

                receiveImage(servsockfd);
                sprintf(console,"receive Image complete!\n");
                stamp_log(console);
                puts(console);

            }

            /* If data is 'd' */
            if(strlen(recvbuff)== 2  && !strncmp(recvbuff,"d",1))
            {
                /* receive filename */
                if((recvlen=recv(servsockfd, recvbuff, BUFSIZE-1, 0)) == -1){
                    perror("recv failed\n");
                    break;
                }
                
                /* compute length of file's words */
                for(int i = 0; i < recvlen; i++){
                    if(recvbuff[i] >= 0 && recvbuff[i] <= 127){
                        filelen++;
                    }
                }

                recvbuff[filelen] = '\0';   // null

                strcpy(path+30, recvbuff);
            //    path[strlen(path)-1]=0x00;
                printf("File Path : %s\n",  path);
                
                stamp_log("transfer file : ");
                stamp_log(path);
                stamp_log("\n");   

                fp=fopen(path, "r");    // file open ; read

                if(fp == NULL)
                {
                    perror("File does not exist...\n");
                    break;
                }

                while(( fpsize=fread(buff,1,BUFSIZE-1,fp))>0){  // fread
                    send(servsockfd,buff,BUFSIZE-1,1);          // send; file transfer
                }

                sprintf(console,"File transfer is complete!!!\n");
                stamp_log(console);
                puts(console);
                
                strcpy(buff, "f");
                sleep(5);
                fclose(fp);
                break;
            }
            if(strncmp(recvbuff, ":quit",5)==0) // receive ':quit' from client
            {
                // termination
                sprintf(console, "Termination due to client's request...\n");
                stamp_log(console);
                puts(console);

                break;
            }

            sprintf(console," [Client] : %s\n", recvbuff);
            stamp_log(console);
            puts(console);

            if(send(servsockfd, recvbuff, strlen(recvbuff),0) == -1){
                perror("send failed\n");
                break;
            }

        }

    }
    sprintf(console,"\n========================================\n"); 
    stamp_log(console);

    close(sockfd);
    close(servsockfd);
    sleep(1);

}                            

