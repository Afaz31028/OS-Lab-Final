#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{ 
    char buf[30];
    int fd=open("os.txt", O_RDONLY);
    int n=read(fd,buf,30);
    if (remove("os.txt")==0)
        printf("File deleted successfully.\n");
    else
        perror("Error deleting the file.\n");
    return 0;
}
