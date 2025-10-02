#include"../CServ/includes/utils.h"
#include"../CServ/includes/server.h"

#include<stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

// sample client handler to send hello world
void client_handler(int client_socket){
    printf("=== Client connected ===\n");

    char* response = "HTTP/1.1 200 OK\r\nContent-Type: html\r\nContent-Length: 21\r\n\r\n<h1>Hello World!</h1>";

    send(client_socket, response, strlen(response), 0);
    printf("=== Client exited ===\n");
}

int main(){
    struct Server server = create_server(AF_INET,SOCK_STREAM,0,8080,INADDR_ANY,5,client_handler);

    start_HTTP_server(server);

    return 0;
}
