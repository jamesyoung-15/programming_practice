#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>

int main()
{
    int socketFd;
    struct sockaddr_in serverAddress;

    //socket creation
    socketFd = socket(AF_INET,SOCK_STREAM,0);
    if (socketFd == -1) {
        printf("failed to create socket");
        exit(1);
    }
    else 
    {
        printf("Socket created \n");
    }

    //connect
    bzero(&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddress.sin_port = htons(4545);
    if (connect(socketFd,(struct sockaddr *)&serverAddress,sizeof(serverAddress))!=0)
    {
        printf("failed to connect");
        exit(1);
    }
    else 
    {
        printf("connected\n");    
    }
    
    //read
    char buf[128];
    read(socketFd,buf,128);
    printf("received message: %s \n", buf);

    //close
    close(socketFd);
    printf("socket closed\n");
    return 0;
}