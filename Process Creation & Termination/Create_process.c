#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
    pid_t p;
    p=fork();
    if(p<0)
    {
      printf("failed to create process\n");
    }
    else if(p==0)
    {
        printf("I am child process & my PID: %d\n",getpid());
        printf("My parent process's PID: %d\n",getppid());
    }
    else
    {
        printf("I am Parent Process & my PID: %d\n",getpid());
        printf("My child process's PID: %d\n",p);

    }
    printf("Common\n");
}