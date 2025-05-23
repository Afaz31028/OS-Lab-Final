#include <stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
    if (rename("copy.txt", "new_location.txt") == 0)
    {
        printf("File moved/renamed successfully.\n");
    }
    else
    {
        perror("File move failed.\n");
    }
    return 0;
}
