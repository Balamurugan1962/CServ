#ifndef SERVER_H
#include<sys/socket.h>
#include <netinet/in.h>
#define SERVER_H

struct Server {
    int domain;
    int type;
    int protocol;

    int interface;

    int port;
    int backlog;

    struct sockaddr_in addr;

    void (*client_handler)(int);  //function pointer (handle user)
};

struct Server create_server(int domain, int type, int protocol, int port,int interface,int backlog,void(*client_handler)(int));

int start_HTTP_server(struct Server server);


#endif
