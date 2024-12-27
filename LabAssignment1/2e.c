#include <stdio.h>
#include <string.h>

int main() {
    char text[100];

    printf("Enter a string: ");
    scanf("%s", text);

    int len = strlen(text);
    char right_s[len+1];
    int k = 0;

    for (int j = len - 1; j >= 0; j--) {
        right_s[k] = text[j];
        k++;
    }

    right_s[k] = '\0';

    if (strcmp(text, right_s) == 0) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome.\n");
    }

    return 0;
}