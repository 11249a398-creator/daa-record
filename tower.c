#include <stdio.h>

// Function to solve Tower of Hanoi
void towerOfHanoi(int n, char source, char destination, char auxiliary);

int main() {
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    printf("Steps to solve Tower of Hanoi:\n");
    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}

// Recursive function definition
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    towerOfHanoi(n - 1, source, auxiliary, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, destination, source);
}
