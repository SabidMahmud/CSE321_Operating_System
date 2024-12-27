#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 200

int main(int argc, char *argv[]) {
    
    FILE *fp = fopen(argv[1], "w");
    char str[MAX_STRING_LENGTH];

    while (true) {
        printf("Input: ");
        if (fgets(str, MAX_STRING_LENGTH, stdin) == NULL) {
            break;
        }

        str[strcspn(str, "\n")] = '\0';

        if (strcmp(str, "-1") == 0) {
            break;
        }

        fprintf(fp, "%s\n", str);
    }

    fclose(fp);
    return 0;
}
