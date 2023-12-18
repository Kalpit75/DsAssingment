#include <stdio.h>

#define ROWS 3
#define COLS 3

void displayMatrix(int mat[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void joinMatrices(int mat1[ROWS][COLS], int mat2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = mat1[i][j] || mat2[i][j];
        }
    }
}

void productMatrices(int mat1[ROWS][COLS], int mat2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = mat1[i][j] && mat2[i][j];
        }
    }
}

void booleanProductMatrices(int mat1[ROWS][COLS], int mat2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < ROWS; k++) {
                result[i][j] = result[i][j] || (mat1[i][k] && mat2[k][j]);
            }
        }
    }
}

int main() {
    int matrix1[ROWS][COLS] = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 1, 0}
    };

    int matrix2[ROWS][COLS] = {
        {0, 1, 1},
        {1, 1, 0},
        {0, 0, 1}
    };

    int resultJoin[ROWS][COLS];
    int resultProduct[ROWS][COLS];
    int resultBooleanProduct[ROWS][COLS];

    printf("Matrix 1:\n");
    displayMatrix(matrix1);

    printf("\nMatrix 2:\n");
    displayMatrix(matrix2);

    joinMatrices(matrix1, matrix2, resultJoin);
    printf("\nJoin Result:\n");
    displayMatrix(resultJoin);

    productMatrices(matrix1, matrix2, resultProduct);
    printf("\nProduct Result:\n");
    displayMatrix(resultProduct);

    booleanProductMatrices(matrix1, matrix2, resultBooleanProduct);
    printf("\nBoolean Product Result:\n");
    displayMatrix(resultBooleanProduct);

    return 0;
}
