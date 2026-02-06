#include <stdio.h>

// Function declaration
long long factorial(int n);

int main() {
    int num;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d is %lld\n", num, factorial(num));
    }

    return 0;
}

// Recursive function definition
long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;   // base case
    } else {
        return n * factorial(n - 1); // recursive call
    }
}
