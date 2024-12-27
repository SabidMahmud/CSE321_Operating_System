#include <stdio.h>

int main() {
    float num1, num2, result;

    printf("Enter the first number: ");
    scanf("%f", &num1);

    printf("Enter the second number: ");
    scanf("%f", &num2);

    if (num1 > num2) {
        result = num1 - num2;
        printf("Num1 > Num2.\nSo, Subtraction result: %f\n", result);
    } else if (num1 < num2) {
        result = num1 + num2;
        printf("Num1 < Num2. \nSo, Addition result: %f\n", result);
    } else {
        result = num1 * num2;
        printf("Num1 == Num2.\nMultiplication result: %f\n", result);
    }

    return 0;
}
