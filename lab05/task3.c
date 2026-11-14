
#include <stdio.h>
#include <stddef.h>

int is_palindrome(const int *start_ptr, ptrdiff_t length)
{
    if (start_ptr == NULL || length <= 0)
    {
        return 0;
    }

    const int *left_ptr = start_ptr;
    const int *right_ptr = start_ptr + length - 1;

    while (left_ptr < right_ptr)
    {
        if (*left_ptr != *right_ptr)
        {
            return 0;
        }

        left_ptr++;
        right_ptr--;
    }

    return 1;
}

int main(void)
{
    int numbers[] = {1, 2, 3, 2, 1};

    const int *start_ptr = numbers;
    const int *end_ptr = numbers + sizeof(numbers) / sizeof(*numbers);

    ptrdiff_t length = end_ptr - start_ptr;

    printf("Array: ");

    const int *ptr = start_ptr;

    while (ptr < end_ptr)
    {
        printf("%d ", *ptr);
        ptr++;
    }

    printf("\n");

    if (is_palindrome(start_ptr, length))
    {
        printf("Result: The array is a palindrome.\n");
    }
    else
    {
        printf("Result: The array is not a palindrome.\n");
    }

    return 0;
}
