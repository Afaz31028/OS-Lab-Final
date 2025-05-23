#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>

int main()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        printf("I am child process & my PID: %d\n",getpid());
        printf("My parent process's PID: %d\n",getppid());
        exit(0);
    } 
    else
    { 
        wait(NULL);
        printf("I am Parent Process & my PID: %d\n",getpid());
        printf("My child process's PID: %d\n",pid);
    }
    return 0;
}
