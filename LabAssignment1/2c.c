#include <stdio.h>
#include <string.h>
#include <ctype.h>

void create_new_pass(char password[]);

int main() {
    char passwd[100];

    printf("Enter the password: ");
    scanf("%s", passwd);

    create_new_pass(passwd);

    return 0;
}

void create_new_pass(char password[]) {

    int has_digit = 0, upper = 0, lower = 0, special = 0;

    for (int i = 0; i < strlen(password); i++) {
        if (islower(password[i]))lower = 1;
        if (isupper(password[i]))upper = 1;
        if (isdigit(password[i]))has_digit = 1;
        if (strchr("_$#@", password[i]))special = 1;
    }

    if (has_digit && lower && upper && special) printf("• OK ");
    else {
        if (!has_digit) printf("Digit missing, ");
        if (!upper) {
            printf("Uppercase character missing, ");
        }
        if (!lower) {
            printf("Lowercase character missing, ");
        }
        if (!special) {
            printf("Special character missing, ");
        }
    }
}