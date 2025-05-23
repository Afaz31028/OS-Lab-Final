#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    char buffer[100];
    int src = open("source.txt", O_RDONLY);
    int dest = open("copy.txt", O_CREAT | O_WRONLY, 0644);

    if (src < 0 || dest < 0) {
        perror("Error opening files");
        return 1;
    }
    int n;
    while ((n = read(src, buffer, sizeof(buffer))) > 0) {
        write(dest, buffer, n);
    }

    printf("File copied successfully.\n");

    close(src);
    close(dest);
    return 0;
}