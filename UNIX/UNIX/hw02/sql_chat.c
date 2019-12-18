#include "/usr/include/mysql/mysql.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void){

    MYSQL *conn;
    MYSQL_RES *result;
    MYSQL_ROW row;

    char query_buffer[2048];

    conn = mysql_init(NULL);

    if(!mysql_real_connect(conn, "localhost", "root", "root", NULL, 0,NULL, 0)){
        perror("connect");
    }
    else{
        if(mysql_select_db(conn,"unix")){
            printf("use db");
  //          exit(1);
        }
    }

    sprintf(query_buffer, "%s", "show tables");
    if(mysql_query(conn, query_buffer)){
        perror("query");
//        exit(1);
    }

    result = mysql_use_result(conn);
    while((row = mysql_fetch_row(result)) != NULL){
        printf("%s \n", row[0]);
    }
    mysql_free_result(result);
    mysql_close(conn);

    return 0;


}

