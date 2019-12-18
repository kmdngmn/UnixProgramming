#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

// count line
int get_line(FILE *lfp){

    int line = 0;
    char buffer[BUFSIZ];

    while(fgets(buffer,sizeof(buffer),lfp) != NULL){
        line++;
    }

    return line;

}

int main(int argc, char *argv[]){ // arguments count, arguments vector
    char ch;
    int fd;
    struct stat buf;

    FILE *lfp; // line count file pointer
    FILE *fp; // file pointer
    char c;

    if(argc == 1){ // invalid format
        printf("argument error\n");
        printf("Usage : [option] filename\n");
        exit(1);
    }

    // no option
    else if(argc == 2){ // arguments count = 2

        if((access(argv[1], F_OK)) == -1){ // invalid file or directory
            printf("mycat: %s: No such file or directory\n",argv[1]);
            exit(1);
        }


        stat(argv[1],&buf);
        if(S_ISDIR(buf.st_mode)){ // argv[1] is directory
            printf("mycat: %s: Is a directory\n", argv[1]);
            exit(1);
        }
    }
    else if(argc == 3){ // option
        if((access(argv[2], F_OK)) == -1){ // invalid file or directory
            printf("mycat: %s: No such file or directory\n",argv[2]);
            exit(1);
        }

        stat(argv[2], &buf);
        if(S_ISDIR(buf.st_mode)){ // argv[2] is directory
            printf("mycat: %s: Is a directory\n", argv[2]);
            exit(1);
        }
    }
    else{
        printf("Usage : [option] filename\n");
        exit(1);
    }

    fp = fopen(argv[argc-1], "r"); // file pointer when option exist
    lfp = fopen(argv[argc-1], "r"); // file pointer for count line of file
    fd = open(argv[argc-1], O_RDONLY); // file descriptor when no option

    if(argc == 2){ // no option

        while(read(fd, &ch, 1)){
      
            write(1,&ch,1);
    
        }
    }else if(argc == 3){ // option
       
        // option : -n
        if(strcmp(argv[1], "-n") == 0){ // -n option -> print line number
           
            int i = 1; // line number
            int line = get_line(lfp); // get line

            printf("     %d  ",i); // print line number
            while((c=getc(fp)) != EOF){
         
                if(i < line){
                    if(c == '\n'){
                        c='\0'; // remove '\n'
                        printf("\n     %d  ",++i); // prin line number
                    }    
                }
                
                putchar(c);

                if(i >line){
                    break;
                }


            }

        }

    }

    // close , fclose
    fclose(lfp);
    fclose(fp);
    close(fd);
    return 0;
}

