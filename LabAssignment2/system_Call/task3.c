#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h> 

int main() {
    int *process_count = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (process_count == MAP_FAILED) {
        perror("mmap failed");
        exit(1);
    }

    *process_count = 1;

    pid_t a, b, c;

    a = fork(); // f1
    if (a == -1) {
        perror("Fork 1 failed");
        exit(1);
    }
    if (a == 0) {
        (*process_count)++;
    }

    if (a != 0) {
        b = fork();  // f2
        if (b == -1) {
            perror("Fork 2 failed");
            exit(1);
        }
        if (b == 0) {
            (*process_count)++;
        }
    }

    if (a != 0 && b != 0) {
        c = fork();  // f3 
        if (c == -1) {
            perror("Fork 3 failed");
            exit(1);
        }
        if (c == 0) {
            (*process_count)++;
        }
    }

    if (a == 0 || b == 0 || c == 0) {
        if (getpid() % 2 != 0) {
            
            pid_t extra_child = fork();
            if (extra_child == -1) {
                perror("Fork failed");
                exit(1);
            }
            if (extra_child == 0) {
                (*process_count)++;
            }
        }
    }

    while (wait(NULL) > 0);

    if (a > 0 && b > 0 && c > 0) {
        printf("Total processes created: %d\n", *process_count);
    }

    munmap(process_count, sizeof(int));

    return 0;
}