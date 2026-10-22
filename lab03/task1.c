
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

int main(void) {
    int arr[SIZE];
    int i, temp;

    srand((unsigned int)time(NULL));

    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 101 - 50;
    }

    printf("Original array:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%4d", arr[i]);
    }
    printf("\n");

    for (i = 0; i < SIZE / 2; i++) {
        temp = arr[i];
        arr[i] = arr[SIZE - 1 - i];
        arr[SIZE - 1 - i] = temp;
    }

    printf("Reversed array:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%4d", arr[i]);
    }
    printf("\n");

    return 0;
}
