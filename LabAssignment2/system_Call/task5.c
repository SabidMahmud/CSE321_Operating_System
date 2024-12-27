#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Parent process ID: %d\n", getpid());

    pid_t child = fork();

    if (child == 0) { 
        printf("Child process ID: %d\n", getpid());

        for (int i = 0; i < 3; i++) {
            pid_t grandchild = fork();
            if (grandchild == 0) { 
                printf("Grandchild process ID: %d\n", getpid());
                return 0; 
            } else {
                wait(NULL); 
            }
        }

        return 0;
    } else {
        wait(NULL); 
    }

    return 0;
}