#include <stdio.h>

void binPacking(int *items, int binCapacity, int numItems) {
    int binCount = 0;
    // Array to store remaining space in each bin. Max bins possible is numItems.
    int bin_rem[numItems]; 

    // Place items one by one
    for (int i = 0; i < numItems; i++) {
        // Find the first bin that can accommodate items[i]
        int j;
        for (j = 0; j < binCount; j++) {
            if (bin_rem[j] >= items[i]) {
                bin_rem[j] -= items[i];
                break; // Item placed, move to next item
            }
        }

        // If no existing bin could accommodate the item, start a new bin
        if (j == binCount) {
            bin_rem[binCount] = binCapacity - items[i];
            binCount++; // Increment the number of bins
        }
    }

    printf("Number of bins required using First Fit: %d\n", binCount);
}

int main() {
    printf("BIN PACKING Algorithm (First Fit)\n");
    printf("Enter the number of items in Set: ");
    int n, i;
    scanf("%d", &n);
    int a[n]; // Using a variable-length array (C99 feature)
    printf("Enter %d items:", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter the bin capacity: ");
    int size;
    scanf("%d", &size);

    binPacking(a, size, n);

    return 0;
}
