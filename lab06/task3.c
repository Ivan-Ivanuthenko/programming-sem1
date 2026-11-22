#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("Enter number of audio samples: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of samples!\n");
        return 1;
    }

    float *left = (float*)malloc(n * sizeof(float));
    float *right = (float*)malloc(n * sizeof(float));

    if (left == NULL || right == NULL) {
        printf("Memory allocation error!\n");
        free(left);
        free(right);
        left = NULL;
        right = NULL;
        return 1;
    }

    printf("Enter left channel samples:\n");
    for (int i = 0; i < n; i++) {
        printf("Left[%d]: ", i);
        scanf("%f", &left[i]);
    }

    printf("Enter right channel samples:\n");
    for (int i = 0; i < n; i++) {
        printf("Right[%d]: ", i);
        scanf("%f", &right[i]);
    }

    printf("\nAudio data:\n");
    for (int i = 0; i < n; i++) {
        printf("Sample %d: Left = %.2f, Right = %.2f\n",
               i, left[i], right[i]);
    }

    free(left);
    free(right);

    left = NULL;
    right = NULL;

    return 0;
}