#include <stdio.h>
#include <stdlib.h>

int **alloc2DArray(int rows, int cols) {
    int **board = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        board[i] = malloc(cols * sizeof(int));
    }
    return board;
}

int main() {

    int rows = 0;
    int cols = 0;

    printf(".........................GAME OF LIFE.........................\n\n");
    printf("Enter the Number of Rows: \n");
    scanf("%d", &rows);

    printf("Enter Number of Columns: \n");
    scanf("%d", &cols);

    int **board = alloc2DArray(rows, cols);

    return 0;
}
