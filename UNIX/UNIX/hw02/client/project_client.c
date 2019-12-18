#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <time.h>

#define PORT 7017   // port number
#define BUFFER 1024

/* image */
void sendImage(int socket){
    int c;

    FILE* wfp;
    FILE* stream;

    wfp = fdopen(socket,"w");
    stream = fopen("sheep.jpg","rb");

    while((c=fgetc(stream)) != EOF){
        fputc(c,wfp);
    }
    fclose(wfp);
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
    buf[wordlen] = '\0';

    fputs(buf,lfp); // put string in log.txt

    fclose(lfp);
}

/* argv[1] IP address 127.0.0.1 */
int main(int argc, char *argv[])
{
    int sockfd = 0, n = 0;
    int recvlen;            // receive data length
    char sendbuff[BUFFER];  // send buffer
    char recvbuff[BUFSIZ];  // receive buffer
    char buffer[BUFFER];
    char path[]="/home/ubuntu/UNIX/hw02/client/";   // save location of file
    struct sockaddr_in serv_addr;
    char filename[100];     // file name
    FILE *fp=NULL;
    char tmp[128];

    int wordlen = 0; // length of file's word

    time_t t = time(NULL);         // log stamp time
    struct tm tm = *localtime(&t); // log stamp time
    char console[256];             // log stamp buffer

    pid_t pid;  // for process function

    sprintf(console,"\n\n----------%d-%d-%d %2d:%2d:%2d----------\n\n",tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday,tm.tm_hour, tm.tm_min, tm.tm_sec);
    stamp_log(console);

    // argc != 2 -> error
    if(argc != 2)
    {
        sprintf(console,"Usage: %s <ip of server> \n",argv[0]);
        stamp_log(console);
        puts(console);
        close(1);
    }

    /* create socket */
    if((sockfd=socket(AF_INET, SOCK_STREAM, 0)) == -1) {

        perror("socket failed\n");
        close(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);   // htons

    if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) == -1)
    {
        sprintf(console,"inet_pton error\n");
        puts(console);
        stamp_log(console);

        close(1);
    }

    /* connect */
    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    {
        perror("connect failed\n");
        close(1);
    }
    while(1)
    {
        sprintf(console,"Send Message : ");
        stamp_log(console);
        puts(console);

        fgets(buffer, BUFFER,stdin);

        /* send */
        send(sockfd, buffer, strlen(buffer),0);
        sleep(1);
        
        /* termination on input ":quit" */
        if(strncmp(buffer, ":quit",5)==0)
        {
            break;

        }

        /* image */
        else if(!strncmp(buffer,"i",1) && strlen(buffer) ==2){
            

            sprintf(console,"Image file name to download: ");
            stamp_log(console);
            puts(console);
            
            sendImage(sockfd);

            sprintf(console,"Download complete!!\n");
            stamp_log(console);
            puts(console);
            break;
        }

        /* Download file on input "d" */
        else if(!strncmp(buffer,"d",1) && strlen(buffer)==2)
        {

            system("ls");

            sprintf(console,"File name to download: ");
            stamp_log(console);
            puts(console);

            scanf("%s", filename);
            send(sockfd, filename, strlen(filename),0);

            strcpy(path+30, filename);
            sprintf(console, "%s\n", path);
            puts(console);
            stamp_log(console);

            fp=fopen(path, "w");

            /* receive */
            while((recvlen=recv(sockfd, recvbuff, BUFFER-1, 0)) > 0){
                recvbuff[recvlen]=0x00;
           
                /* compute length of file's words */
                for(int i = 0; i < recvlen; i++){
                
                    if(recvbuff[i] >= 0 && recvbuff[i] <= 127){ // in ASCII
                        wordlen++;
                    }
                    else{
                        break;
                    }
                }

                fwrite(recvbuff, 1,wordlen,fp); // fwrite
            }
            sprintf(console,"Download Completed!!!\n");
            stamp_log(console);
            puts(console);
            
            /* ls ; execlp */
            switch (pid = fork()){
                case -1: /* fork failed */
                    perror("fork");
                    break;
                case 0: /* child process */
                    printf("-->child process\n");
                    if(execlp("ls", "ls", (char *)NULL) == -1){ // execlp
                        perror("execlp");
                        exit(1);
                    }
                    break;
                default :   /* parent process */
                    printf("--> Parent process - My PID:%d\n",(int)getpid());
                    break;
            }

            fclose(fp);
            break;
        }
        
        else if((recvlen=recv(sockfd, recvbuff, BUFFER-1, 0)) == -1)  {
            perror("recv failed\n");
            break;
        }
        recvbuff[recvlen] = '\0';
        sprintf(console,"[Info] : %s\n", recvbuff);
        stamp_log(console);
        puts(console);
    
    }

    sprintf(console,"\n=========================================\n");
    stamp_log(console);

    close(sockfd);
    return 0;
}

