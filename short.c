#include <stdio.h>
#define INF 9999
#define MAX 10

int main() {
    int graph[MAX][MAX], dist[MAX], visited[MAX];
    int n, start, i, j, count, min, next;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if(graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    for(i = 0; i < n; i++) {
        dist[i] = graph[start][i];
        visited[i] = 0;
    }

    dist[start] = 0;
    visited[start] = 1;

    for(count = 1; count < n; count++) {
        min = INF;

        for(i = 0; i < n; i++) {
            if(dist[i] < min && !visited[i]) {
                min = dist[i];
                next = i;
            }
        }

        visited[next] = 1;

        for(i = 0; i < n; i++) {
            if(!visited[i] && min + graph[next][i] < dist[i]) {
                dist[i] = min + graph[next][i];
            }
        }
    }

    printf("\nShortest distance from vertex %d:\n", start);
    for(i = 0; i < n; i++) {
        printf("To vertex %d = %d\n", i, dist[i]);
    }

    return 0;
}