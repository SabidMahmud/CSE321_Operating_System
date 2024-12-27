#include <stdio.h>

int check_perfect(int num);

int main() {
    int lowerBound, upperBound;

    printf("lower bound: ");
    scanf("%d", &lowerBound);
    printf("upper bound: ");
    scanf("%d", &upperBound);

    for (int i = lowerBound; i <= upperBound; i++) {
        if (check_perfect(i) == 1) printf("%d\n", i);
    }

    return 0;

}


int check_perfect(int num) {
    int sum = 0;
    int i = 1;
    
    while (i < num) {
        if (num % i == 0) {
            sum += i;
        }
        i++;
    }
    
    if (sum == num) {
        return 1;
    } else {
        return 0;
    }
}