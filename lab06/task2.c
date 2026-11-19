
#include <stdio.h>
#include <stdlib.h>

int main()
{
    size_t capacity = 3;
    size_t count = 0;

    double *arr = (double*)malloc(capacity * sizeof(double));

    if (arr == NULL)
    {
        printf("Memory allocation error!\n");
        return 1;
    }

    double value;

    printf("Enter numbers (number < 0.001 to stop):\n");

    while (1)
    {
        printf("Number: ");

        if (scanf("%lf", &value) != 1)
        {
            printf("Invalid input!\n");
            free(arr);
            arr = NULL;
            return 1;
        }

        if (value < 0.001)
        {
            break;
        }

        if (count == capacity)
        {
            size_t new_capacity = capacity * 2;

            double *temp = (double*)realloc(
                arr, new_capacity * sizeof(double)
            );

            if (temp == NULL)
            {
                printf("Memory reallocation error!\n");
                free(arr);
                arr = NULL;
                return 1;
            }

            arr = temp;
            capacity = new_capacity;

            printf("Buffer expanded to %zu elements.\n", capacity);
        }

        arr[count] = value;
        count++;
    }

    printf("\nEntered numbers:\n");

    for (size_t i = 0; i < count; i++)
    {
        printf("%.3f ", arr[i]);
    }

    printf("\nTotal number of elements: %zu\n", count);
    printf("Final buffer capacity: %zu\n", capacity);

    free(arr);
    arr = NULL;

    return 0;
}
