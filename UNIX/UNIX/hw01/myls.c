#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

// check flag
int check_flag(char* str, char t){
    int i=1;
    while(str[i] != '\0'){
        if(str[i] == t){
            return 1;
        }
        i++;
    }
    return 0;
}

// print file or directory list 
void print_list(char* str, int l, int R, int is_recur){ // option: -l, -R
    
    DIR * dp;               // directory pointer
    struct dirent *entry;   // directory entry
    struct stat statbuf;    // stat

    int count = 0;

    struct passwd *pwd;
    struct group *grp;
    char path[4000]={0,};

    struct tm *tm; // for statbuf.st_mtime convert

    // if directory is null
    if((dp = opendir(str)) == NULL){ // open directory
        if(is_recur == 0){

            // invalid file or directory
            if(access(str, F_OK) < 0){
                fprintf(stderr,"%s: Invalid file or directory..\n",str);
            }
            else{

                if(lstat(str,&statbuf) == 0){ // lstat
                    fflush(stdin); // empty stdin buffer
                    if(l==0){
                        printf("%s\n",str);
                    }
                    else if(l==1){
                        pwd = getpwuid(statbuf.st_uid); // get user information by uid
                        grp = getgrgid(statbuf.st_gid); // get group information by gid
//                        printf("%o %s %s %d %d %s\n",statbuf.st_mode, pwd->pw_name, grp->gr_name,(int)statbuf.st_size, (int)statbuf.st_nlink, str);


                        printf((S_ISDIR(statbuf.st_mode)) ? "d" : "-");
                        printf((statbuf.st_mode & S_IRUSR) ? "r" : "-");
                        printf((statbuf.st_mode & S_IWUSR) ? "w" : "-");
                        printf((statbuf.st_mode & S_IXUSR) ? "x" : "-");
                        
                        printf((statbuf.st_mode & S_IRGRP) ? "r" : "-");
                        printf((statbuf.st_mode & S_IWGRP) ? "w" : "-");
                        printf((statbuf.st_mode & S_IXGRP) ? "x" : "-");
 
                        printf((statbuf.st_mode & S_IROTH) ? "r" : "-");
                        printf((statbuf.st_mode & S_IWOTH) ? "w" : "-");
                        printf((statbuf.st_mode & S_IXOTH) ? "x" : "-");

                 // &statbuf.st_mtime convert format
                        tm = localtime(&statbuf.st_mtime);

                 // print
                        printf(" %d %s %s %5d %02d월 %02d %02d:%02d %s\n", (int)statbuf.st_nlink ,pwd->pw_name, grp->gr_name, (int)statbuf.st_size, tm->tm_mon+1, tm->tm_mday, tm->tm_hour, tm->tm_min ,str);


                    }
                }
            }
        }
        closedir(dp);
    }
    else{
        printf("%s:\n", str);
        while((entry = readdir(dp)) != NULL){ // read directory
            
            // (lstat) file info 
            if(strcasecmp(str,"/") == 0) // string compare ignore lower case, upper case
                sprintf(path, "%s%s",str,entry->d_name);
            else
                sprintf(path, "%s/%s", str, entry->d_name);
            lstat(path, &statbuf);

            // if file's first name is '.' then do not print
            if(entry->d_name[0] == '.'){
                continue;
            }

            if(l==0){
                printf("%s  ", entry->d_name); // no option ; myls
                
            }
            else{
                pwd = getpwuid(statbuf.st_uid); // get user information by uid
                grp = getgrgid(statbuf.st_gid); // get group information by gid

                // print access mode
                printf((S_ISDIR(statbuf.st_mode)) ? "d" : "-");
                printf((statbuf.st_mode & S_IRUSR) ? "r" : "-");
                printf((statbuf.st_mode & S_IWUSR) ? "w" : "-");
                printf((statbuf.st_mode & S_IXUSR) ? "x" : "-");

                printf((statbuf.st_mode & S_IRGRP) ? "r" : "-");
                printf((statbuf.st_mode & S_IWGRP) ? "w" : "-");
                printf((statbuf.st_mode & S_IXGRP) ? "x" : "-");

                printf((statbuf.st_mode & S_IROTH) ? "r" : "-");
                printf((statbuf.st_mode & S_IWOTH) ? "w" : "-");
                printf((statbuf.st_mode & S_IXOTH) ? "x" : "-");

                // &statbuf.st_mtime convert format 
                tm = localtime(&statbuf.st_mtime);
                
                // print
                printf(" %d %s %s %5d %02d월 %02d %02d:%02d %s\n", (int)statbuf.st_nlink ,pwd->pw_name, grp->gr_name, (int)statbuf.st_size, tm->tm_mon+1, tm->tm_mday, tm->tm_hour, tm->tm_min ,entry->d_name);
              
            }
            count++;
        }
        printf("\n");

        // -R option : recursive print
        if(R == 1){
            rewinddir(dp); // rewind directory
            while((entry = readdir(dp)) != NULL){ // read directory
                if(strcasecmp(str,"/") == 0) // string compare ignore lower, upper case1
                    sprintf(path, "%s%s", str, entry->d_name);
                else
                    sprintf(path, "%s/%s", str, entry->d_name);
                lstat(path, &statbuf);

                // if directory
                if(S_ISDIR(statbuf.st_mode)){

                    // ignore '.' , '.."
                    if(strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) ==0) continue;
                    if(entry->d_name[0] == '.') continue;

                    // recursive print_list
                    print_list(path,l,R,1);
                }
            }
        }
        closedir(dp);
    }
}

int main(int argc, char *argv[]){ // arguments count, arguments vector

    // option flag
    int l_flag=0, R_flag=0;

    int d_flag=0;

    // initial directory name
    char *path = ".";

    // option count
    int opt_cnt=1;

    // ls; no option
    if(argc == 1){
        print_list(path, l_flag, R_flag, 0);
    }
    else if(argc >= 2){ // option
        for(int i=1; i < argc; i++){
            if(argv[i][0] == '-'){
                l_flag = check_flag(argv[i], 'l'); // -l
                R_flag = check_flag(argv[i], 'R'); // -R
                opt_cnt++; // increase option count
            }
        }
        
        // option exist
        if((argc-opt_cnt) > 0) d_flag  =1;

        if(d_flag == 0){
            print_list(path,l_flag,R_flag, 0);
        }
        else{
            for(int i = 0; i<argc-1; i++){
                if(argv[i+1][0] != '-'){
                    fflush(stdin); // empty stdin buffer
                    print_list(argv[i+1], l_flag, R_flag, 0);
                }
            }
        }
    }
    return 0;
}


