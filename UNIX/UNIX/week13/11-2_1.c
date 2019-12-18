#include <stdio.h>
#include <netdb.h>

int main(void){

    struct servent *port;

    int n;

    setservent(0);

    for(n = 0; n < 5; n++){
        port = getservent();
        printf("Name=%s, Port=%d\n", port->s_name, ntohs(port->s_port));
    }

    endservent();

    return 0;
}

