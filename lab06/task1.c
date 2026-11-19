
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    float A, B;
    int count = 0;

    printf("Enter array size N: ");

    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid array size!\n");
        return 1;
    }

    float *arr = (float*)malloc(n * sizeof(float));

    if (arr == NULL)
    {
        printf("Memory allocation error!\n");
        return 1;
    }

    printf("Enter %d array elements:\n", n);

    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = ", i);

        if (scanf("%f", &arr[i]) != 1)
        {
            printf("Invalid input!\n");
            free(arr);
            arr = NULL;
            return 1;
        }
    }

    printf("Enter A: ");
    if (scanf("%f", &A) != 1)
    {
        free(arr);
        arr = NULL;
        return 1;
    }

    printf("Enter B: ");
    if (scanf("%f", &B) != 1)
    {
        free(arr);
        arr = NULL;
        return 1;
    }

    if (A > B)
    {
        float temp = A;
        A = B;
        B = temp;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= A && arr[i] <= B)
        {
            count++;
        }
    }

    printf("Number of elements in range [%.2f; %.2f]: %d\n",
           A, B, count);

    free(arr);
    arr = NULL;

    return 0;
}
