#include <stdio.h>

#define MAX 10
#define INF 9999

int main() {
    int n, cost[MAX][MAX];
    int visited[MAX] = {0};
    int i, j, count = 1;
    int current = 0, nextCity;
    int totalCost = 0, min;

    printf("TRAVELLING SALESMAN PROBLEM (Greedy Method)\n");
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0 && i != j)
                cost[i][j] = INF;  // Replace 0 with INF except diagonal
        }
    }

    visited[current] = 1;
    printf("Tour: %d ", current + 1);

    while(count < n) {
        min = INF;
        nextCity = -1;

        for(i = 0; i < n; i++) {
            if(!visited[i] && cost[current][i] < min) {
                min = cost[current][i];
                nextCity = i;
            }
        }

        if(nextCity != -1) {
            visited[nextCity] = 1;
            printf("-> %d ", nextCity + 1);
            totalCost += min;
            current = nextCity;
            count++;
        }
    }

    // Return to starting city
    totalCost += cost[current][0];
    printf("-> %d", 1);

    printf("\nTotal Cost: %d\n", totalCost);

    return 0;
}
