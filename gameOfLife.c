#include <stdio.h>
#include <stdlib.h>

int **alloc2DArray(int rows, int cols) {
    int **board = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        board[i] = malloc(cols * sizeof(int));
    }
    return board;
}

void free2DArray(int **array, int rows) {
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
}

void init2DArray(int **array, int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            array[r][c] = 0;
        }
    }
}

void printBoard(int **board, int rows, int cols) {

    printf("\n");

    for (int i = 0; i < 2 * rows + 1; i++) {
        printf("-");
    }
    printf("\n");

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (board[r][c] == 0) {
                printf("| ");
            } else {
                printf("|\u2588");
            }
        }
        printf("|\n");
    }

    for (int i = 0; i < 2 * cols + 1; i++) {
        printf("-");
    }
    printf("\n\n");
}

int main(void) {

    int rows = 0;
    int cols = 0;

    printf(".........................GAME OF LIFE.........................\n\n");
    printf("Enter the Number of Rows: \n");
    scanf("%d", &rows);

    printf("Enter Number of Columns: \n");
    scanf("%d", &cols);

    printf("\n");

    int **board = alloc2DArray(rows, cols);
    init2DArray(board, rows, cols);

    printf("How many alive cells do you want: ");
    int aliveCells = 0;
    scanf("%d", &aliveCells);

    for (int i = 0; i < aliveCells; i++) {
        printf("Enter the coordinates for cell %d: ", i + 1);
        int r = 0;
        int c = 0;

        scanf("%d %d", &r, &c);
        board[r][c] = 1;
    }

    printBoard(board, rows, cols);

    free2DArray(board, rows);

    return 0;
}
