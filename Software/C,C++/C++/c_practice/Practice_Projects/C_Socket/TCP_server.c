#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

int main()
{
    //variables
    int serverSocketFd, clientSocketFd;
    struct sockaddr_in serverAddress;
    struct sockaddr_in clientAddress;
    int clientAddressLength;

    // creating socket
    serverSocketFd = socket(AF_INET, SOCK_STREAM, 0);
    //check if tcp socket is created
    if(serverSocketFd == -1)
    {
        printf("Failed to create socket \n");
        exit(1);
    }
    else
    {
        printf("Socket: %d\n", serverSocketFd);
    }

    //bind socket
    bzero(&serverAddress, sizeof(serverAddress));
    //address family
    serverAddress.sin_family = AF_INET;
    //accept any address, host byte order should be converted to network byte order
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_port = htons(4545);
    if(bind(serverSocketFd,(struct sockaddr *)&serverAddress,sizeof(serverAddress))!=0)
    {
        printf("failed to bind.\n");
        exit(1);
    }
    else
    {
        printf("Bind success\n");
    }
    //listen
    if(listen(serverSocketFd,1)!=0)
    {
        printf("listen failure");
        exit(1);
    }
    else 
    {
        printf("listening... \n");
    }
    //accept
    bzero(&clientAddress, sizeof(clientAddress));
    clientSocketFd = accept(serverSocketFd,(struct sockaddr*) &clientAddress, &clientAddressLength);
    if(clientSocketFd==-1)
    {
        printf("Failed to accept");
        exit(1);
    }
    else 
    {
        printf("accepted");
    }

    //read/write
    char *msg = "Hello world";
    write(clientSocketFd, msg, strlen(msg));
    printf("message: %s sent\n", msg);

    //close
    close(clientSocketFd);
    close(serverSocketFd);
    printf("closed client and server socket\n");
    return 0;
}