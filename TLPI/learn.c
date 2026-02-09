#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main()
{
    char buf[16];
    pid_t pid;

    printf("Parent: try reading from stdin before vfork\n");
    ssize_t n=read(STDIN_FILENO,buf,sizeof(buf));
    if(n<0) {
        perror("parent read before vfork");
    } else {
        printf("Parent: read %zd bytes before vfork\n",n);
    }

    pid=vfork();
    if(pid<0) {
        perror("vfork");
        exit(EXIT_FAILURE);
    }

    if(pid==0) {
        printf("Child: closing stdin (fd 0)\n");
        close(STDIN_FILENO);

        _exit(0);
    }

    printf("Parent: try reading from stdin after child closed fd 0\n");
    n=read(STDIN_FILENO,buf,sizeof(buf));
    if(n<0) {
        perror("parent read after vfork");
    } else {
        printf("Parent: read %zd bytes after vfork\n",n);
    }

    return 0;
}
