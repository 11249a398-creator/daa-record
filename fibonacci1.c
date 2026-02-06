#include <stdio.h>

// Function declaration
int fibonacci(int n);

int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        printf("Fibonacci series:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", fibonacci(i));
        }
    }

    return 0;
}

// Recursive function definition
int fibonacci(int n) {
    if (n == 0)
        return 0;          // base case
    else if (n == 1)
        return 1;          // base case
    else
        return fibonacci(n - 1) + fibonacci(n - 2); // recursive call
}
