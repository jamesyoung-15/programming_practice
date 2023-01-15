#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void readFile()
{
    int fd;
    char buf[100];
    fd=open("file.txt", O_RDONLY);
    printf("file descriptor: %d \n", fd);
    read(fd,buf,sizeof(buf));
    printf("data: %s", buf);
}

void writeFile()
{
    char buf[] = "Hello World\n";
    // open file
    int fd=open("file.txt", O_CREAT|O_WRONLY|O_TRUNC);
    printf("file descriptor: %d\n", fd);
    write(fd,buf,sizeof(buf));
    close(fd);
}

int main()
{
    int option;
    printf("Enter option 1 (read) or 2 (write):");
    scanf("%d", &option);
    if(option == 1)
        readFile();
    else if (option==2)
        writeFile();
    else
        printf("error");
    return 0;
}