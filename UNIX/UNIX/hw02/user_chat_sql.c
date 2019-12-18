#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "/usr/include/mysql/mysql.h"

#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASS "root"
#define DB_NAME "unix"

#define CHOP(x) x[strlen(x) - 1] = ' '

typedef struct{
    char id[50];
    char pw[50];
}userInfo;

void input_data(userInfo *userInfo);

int insert(MYSQL *, userInfo userInfo);
int search(MYSQL *);


int main(void){

    int i, n;

    MYSQL       *connection = NULL, conn;
    MYSQL_RES   *sql_result;
    MYSQL_ROW   row;

    int field;

    int query_stat;

    mysql_init(&conn);

    connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char *)NULL, 0);
    if(connection == NULL){
        printf("log\n");
        perror("connection");
        exit(1);
    }

    printf("mysql connection successed...\n");

    userInfo userInfo[5];
    printf("Enter the mode:\n");
    printf("1 : input mode\n");
    printf("2 : seaching mode\n");
   
    scanf("%d",&n);
    switch(n)
    {
            case 1:
                    for(i=0;i < 2;i++)
                            input_data(&userInfo[i]);
        
                    for(i=0;i < 2;i++){
                            printf("%p\n", connection);
                            insert(connection,userInfo[i]);
                    }
                    break;
            case 2:
                    search(connection);
                    break;
            default :
                    exit(1);
    }
    mysql_close(connection);
    
    return 0;
}


void input_data(userInfo *userInfo)
{
            printf("input id\n");
            scanf("%s",userInfo->id);
            getchar();
            printf("input pw\n");
            scanf("%s",userInfo->pw);
}


int insert(MYSQL *con, userInfo userInfo)
{       
            char buff[255];
            sprintf(buff,"insert into user values " "('%s', '%s')",userInfo.id,userInfo.pw);
 
            printf("%s : %p: %d\n",buff, con,mysql_query(con,buff));
}


int search(MYSQL *con)
{
        int j;
        char buff2[255];
        char id[50];

        MYSQL_RES   *sql_result;
        MYSQL_ROW   row;
        int field;
        printf("insert id : ");
        scanf("%s", id);
        sprintf(buff2,"select * from user where id = '%s'",id);
        mysql_query(con,buff2);
        sql_result=mysql_store_result(con);
        field=mysql_num_fields(sql_result);
        printf("id: %s    pw: %s","id","pw");
        while((row=mysql_fetch_row(sql_result))){
                for(j=0;j<field;j++)
                        printf("%12s",row[j]);
                        printf("\n");
        }
}

/*
int print(MYSQL *con)
{
        int k;
        MYSQL_RES *sql_result;
        MYSQL_ROW row;
        int field;
        mysql_query(con,"select * from test");
        sql_result=mysql_store_result(con);
        field=mysql_num_fields(sql_result);
        printf("%12s%12s%12s%12s%12s%12s","name","KREAN","ENGLISH","MATH","SUM","AVER");
        while((row=mysql_fetch_row(sql_result))){
                for(k=0;k<field;k++)
                        printf("%12s",row[k]);
                        printf("\n");
        }
}
*/
