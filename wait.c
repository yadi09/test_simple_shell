#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {  // Child process
        printf("Child process is running...\n");
        // Do some work
        exit(0);  // Child exits with status 0
    } else {  // Parent process
        int status;
        pid_t child_pid = wait(&status);  // Parent waits for child

        printf("Child process with PID %d exited with status %d\n", child_pid, status);
    }

    return 0;
}
