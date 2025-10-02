#include"../includes/server.h"
#include"../includes/utils.h"

#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>


int start_HTTP_server(struct Server server){

    int server_fd = socket(server.domain, server.type, server.protocol);

    if(server_fd < 0){
        raise_error("[SERVER] Socket Error");
    }

    struct sockaddr_in addr;

    server.addr.sin_port = htons(server.port);
    server.addr.sin_family = server.domain;
    server.addr.sin_addr.s_addr = htonl(server.interface);

    if(bind(server_fd,(struct sockaddr*)&server.addr,sizeof(server.addr))<0){
        raise_error("[SERVER] Bind Error");
    }

    if(listen(server_fd, server.backlog) < 0){
        raise_error("[SERVER] Listen Error");
    }

    raise_success("[SERVER] Server Started");

    while(1){
        int client_fd = accept(server_fd,0,0);

        server.client_handler(client_fd);

        close(client_fd);
    }
}

struct Server create_server(int domain, int type, int protocol, int port,int interface, int backlog, void(*client_handler)(int)){
    struct Server server;

    server.domain = domain;
    server.type = type;
    server.protocol = protocol;

    server.backlog = backlog;

    server.port = port;
    server.interface = interface;

    server.client_handler = client_handler;

    return server;
}
