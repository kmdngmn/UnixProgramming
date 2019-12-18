#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int isDir(char fname[]); // check directory or not
mode_t st_modeTomode_t(char *filepath); // convert st_mode -> mode_t

// copy file -> paste file
int fileCopy(char* filename, char *newfilename){

    FILE *rfp; // old file
    FILE *wfp; // new file

    int cnt = 0;

    char buf[1];
    //printf(""); // ?
    if((rfp=fopen(filename,"rb")) == NULL){ // open old file
        printf("mycp: cannot stat : No such file or directory\n");
        exit(1);
    }

    if((wfp=fopen(newfilename,"wb")) == NULL){ // open new file
        printf("mycp: cannot stat : No such file or directory\n");
        exit(1);
    }

    // file copy
    while(!feof(rfp)){
        fread(&buf,1,1,rfp);
        if(!feof(rfp)){
            fwrite(&buf, 1, 1, wfp);
            cnt++;
        }
    }
    fclose(rfp);
    fclose(wfp);

    return 1;
}

// copy directory -> paste directory ; recursive
int dirCopy(char* dirpath, char*newdirpath){
    DIR *dir;
    struct dirent *dirent;
    
    char filepath[1000];
    char newfilepath[1000];

    dir=opendir(dirpath);

    if(dir == NULL){
//        printf("%s cannot open directory\n",dirpath);
        exit(1);
    }
    else{
        while((dirent=readdir(dir)) != NULL){
            mkdir(newdirpath,st_modeTomode_t(dirpath));

            if((strcmp(dirent->d_name, "..") == 0) || (strcmp(dirent->d_name,".") == 0)){
                continue;
            }

            sprintf(filepath, "%s/%s", dirpath, dirent->d_name);
            sprintf(newfilepath, "%s/%s", newdirpath, dirent->d_name);

            if(isDir(filepath)){
                mkdir(newdirpath, st_modeTomode_t(filepath));
                dirCopy(filepath, newfilepath);
            }
            else{
                fileCopy(filepath,newfilepath);
            }
        }
    }
    closedir(dir);

    return 0;
}

// copy file -> paste directory
int fileDirCopy(char *filename, char *dirname){

    FILE *ffp; // file pointer
    FILE *dfp; // file poiter for paste in directory
    FILE *wcfp; // word count file pointer 

    int cnt = 0;

    char buf[BUFSIZ];

    if((wcfp = fopen(filename,"rb")) == NULL){
        exit(1);
    }

    int len = 0; // file's word count
    char c;
    while((c = fgetc(wcfp)) != EOF){
        len++;
    }

    if((ffp = fopen(filename,"rb")) == NULL){ // open old file
        exit(1);
    }
    
    while(!feof(ffp)){
        fread(&buf,1,len,ffp);
    }
    
    // cd directory
    chdir(dirname);

    if((dfp = fopen(filename,"wb")) == NULL){ // open new file
        exit(1);
    }
    
    fwrite(&buf,1,len,dfp);

    fclose(ffp);
    fclose(dfp);
    fclose(wcfp);

    return 1;
}

// check directory or not
int isDir(char fname[]){ // fname is Directory?
    struct stat statbuf;
    lstat(fname,&statbuf);

    return S_ISDIR(statbuf.st_mode); // isDIR ? return 1 : 0
}

// check regular file or not
int isReg(char fname[]){ // fname is Regular file?
    struct stat statbuf;
    lstat(fname,&statbuf);

    return S_ISREG(statbuf.st_mode); // isREG ? return 1 : 0
}


// convert format st_mode -> mode_t
mode_t st_modeTomode_t(char *filepath){
    struct stat buf;
    lstat(filepath, &buf);
    return (mode_t)buf.st_mode;
}

int main(int argc, char *argv[]){ // arguments count, arguments vector
    
    // no option
    if(argc == 3){ 
        if(isDir(argv[1]) == 1){ // mycp [directory] [file or directory]
  //          printf("is Directory\n");
            exit(1);
            return 0;
        }
        else if((isReg(argv[1]) == 1) && (isDir(argv[2]) == 1)){ // mycp [file] [directory]

            fileDirCopy(argv[1], argv[2]); // copy file(argv[1]) -> paste in directory(argv[2])

        }
        else{
            if(fileCopy(argv[1], argv[2])){
    //            printf(" success copy\n");
            }
            else{ // invalid format
                printf("Usage : mycp [option] filename newfilename\n");
            }
            exit(1);
        }
    }
    else if(argc==4){ // option
        
        // -d option
        if(!strcmp(argv[1], "-d")){
            if(!dirCopy(argv[2],argv[3])){
     //           printf("success directory copy\n");
            }
            else{
       //         printf("fail directory copy\n");
                exit(1);
            }
        }
        else if(!strcmp(argv[1], "-i")){ // -i option : ask overwrite permit
            
            char choice; // y,Y or default
            if(isDir(argv[3]) == 1){ // argv[3] is directory
                
                chdir(argv[3]); // change directory; cd argv[3]
                if(access(argv[2],F_OK) == 0){ // argv[2] is already existed
                    
                    printf("cp: overwrite '%s/%s'? ",argv[3], argv[2]); // ask overwrite permit
                    scanf("%c",&choice);

                    if(choice == 'y' || choice == 'Y'){ // y or Y
                        chdir(".."); // change previous directory; cd ..
                        fileDirCopy(argv[2],argv[3]); // copy file(argv[2]) -> paste in directory(argb[3])
                    }
                    
                    else{
                        exit(1);
                    }
                }
                else{
                    chdir(".."); // cahnge previous directory; cd ..
                    fileDirCopy(argv[2],argv[3]); // if argv[2] is not existed then just copy
                }
            }
            else{
                if(access(argv[3],F_OK) == 0){ // argv[3] is already existed
                    printf("cp: overwrite '%s'? ",argv[3]); // ask overwrite permit
                    scanf("%c",&choice);
                    
                    if(choice == 'y' || choice == 'Y'){
                        fileCopy(argv[2], argv[3]); // copy file(argv[2]) -> paste file(argv[3])
                    }
                    else{
                        exit(1);
                    }
                }
                else{
                    fileCopy(argv[2],argv[3]); // if argv[3] is not existed then just copy
                }
            }
        }
    }
    else{ // invalid formant
        printf("Usage : mycp [option] filename newfilename\n");
        return 0;
    }
    return 0;

}
