#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(void)
{
    pid_t pid;
    int status;

    printf("Parent process start\n");
    printf("Parent PID = %d\n",getpid());

    pid=fork();

    if(pid<0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if(pid==0) {
        printf("\n[Child] fork succeeded\n");
        printf("[Child] PID  = %d\n",getpid());
        printf("[Child] PPID = %d\n",getppid());
        printf("[Child] About to exec /bin/ls\n");

        char *argv[] = {"ls","-l","/",NULL};

        execvp("ls",argv);
        perror("[Child] execvp failed");
        exit(EXIT_FAILURE);
    } else {
        printf("\n[Parent] fork succeeded\n");
        printf("[Parent] Child PID = %d\n",pid);
        printf("[Parent] Waiting for child...\n");
        if (waitpid(pid,&status,0)<0) {
            perror("waitpid failed");
            exit(EXIT_FAILURE);
        }
        if (WIFEXITED(status)) {
            printf("[Parent] Child exited normally, status=%d\n",WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("[Parent] Child killed by signal %d\n",WTERMSIG(status));
        }
        printf("[Parent] Parent process end\n");
    }

    return 0;
}
