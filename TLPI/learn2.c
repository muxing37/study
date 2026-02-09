#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(void)
{
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        printf("Child: initial parent PID = %d\n", getppid());

        sleep(3);

        printf("Child: parent PID after parent exit = %d\n", getppid());
        printf("Child: my PID = %d\n", getpid());
    } else {

        printf("Parent: my PID = %d\n", getpid());
        printf("Parent: exiting now...\n");
        exit(0);
    }

    return 0;
}
