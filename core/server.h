#ifndef SERVER_H
#include<sys/socket.h>
#define SERVER_H

struct Server {
    int domain;
    int type;
    int protocol;


    int port;
    int backlog;

    void (*client_handler)(void);  //function pointer (handle user)
};

struct Server create_server(int domain, int type, int protocol, int port,int backlog,void(*launch)(void));

int start_server(struct Server server);

#endif
