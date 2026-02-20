#include <stdio.h>
#define N 4   // Change N value as needed

int board[N][N];

// Function to check if position is safe
int isSafe(int row, int col) {
    int i, j;

    // Check left side of row
    for(i = 0; i < col; i++)
        if(board[row][i])
            return 0;

    // Check upper diagonal on left side
    for(i=row, j=col; i>=0 && j>=0; i--, j--)
        if(board[i][j])
            return 0;

    // Check lower diagonal on left side
    for(i=row, j=col; j>=0 && i<N; i++, j--)
        if(board[i][j])
            return 0;

    return 1;
}

// Recursive function
int solveNQ(int col) {
    if(col >= N)
        return 1;

    for(int i = 0; i < N; i++) {
        if(isSafe(i, col)) {
            board[i][col] = 1;

            if(solveNQ(col + 1))
                return 1;

            board[i][col] = 0; // Backtrack
        }
    }
    return 0;
}

int main() {
    if(solveNQ(0)) {
        printf("Solution Exists:\n");
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++)
                printf("%d ", board[i][j]);
            printf("\n");
        }
    } else {
        printf("No Solution");
    }
    return 0;
}