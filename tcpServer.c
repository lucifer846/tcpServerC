#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int s, c; // socket and client

    socklen_t addrlen; // socklen_t is typedef for unsigned int .... ipAddr is 32bit
    struct sockaddr_in srv; // structures for bind
    addrlen = 0;
    char buff[512] = {0};
    char *data;

    memset(&srv, 0, sizeof(srv));

    s = socket(AF_INET, SOCK_STREAM, 0); // returns file descriptor
    if (s<0){
        printf("socket()\n");
        return -1;
    }

    srv.sin_family = AF_INET;
    srv.sin_addr.s_addr = 0; // 0.0.0.0
    srv.sin_port = htons(8181);

    if(bind(s, (struct sockaddr*)&srv, sizeof(srv)) != 0){
        printf("bind()\n");
        close(s);
        return -1;
    }

    if(listen(s, 10)<0){
        printf("listen()\n");
        close(s);
        return -1;
    }
    printf("listening on port 8181\n");

    c = accept(s, (struct sockaddr*)&srv, &addrlen); // returns file descriptor used in read , write and close func
    if(c<0){
        printf("accept()\n");
        close(s);
        return -1;
    }

    printf("client connected \n");

    read(c, buff, 511);
    
    data = "httpd v1.3\n";
    write(c, data, strlen(data));

    close(c);
    close(s);

    return 0;
}
