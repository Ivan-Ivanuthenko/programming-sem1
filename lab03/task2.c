
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

int main(void) {
    int matrix[SIZE][SIZE];
    int i, j;
    int max_element = 0;
    int found = 0;

    srand((unsigned int)time(NULL));

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % 101 - 50;
        }
    }

    printf("Original matrix:\n");

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%6d", matrix[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (i == j && i + j == SIZE - 1) {
                if (!found || matrix[i][j] > max_element) {
                    max_element = matrix[i][j];
                    found = 1;
                }
            }
        }
    }

    if (found) {
        printf("\nMaximum on both diagonals: %d\n", max_element);
    } else {
        printf("\nNo common diagonal element found.\n");
    }

    printf("\nMatrix after processing:\n");

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%6d", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
