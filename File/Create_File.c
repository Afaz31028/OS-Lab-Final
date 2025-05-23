#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("filename.txt", O_CREAT | O_WRONLY, 0644);
    write(fd, "Operating System", 16);
    close(fd);
    return 0;
}
