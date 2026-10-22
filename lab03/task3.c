
#include <stdio.h>

#define BUFFER_SIZE 256

int main(void) {
    char str[BUFFER_SIZE];
    int i = 0;
    int count = 1;
    int found = 0;

    printf("Enter a string: ");

    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Input error.\n");
        return 1;
    }

    while (str[i] != '\0' && str[i] != '\n') {
        i++;
    }

    str[i] = '\0';
    i = 0;

    while (str[i] != '\0') {
        if (str[i] == str[i + 1]) {
            count++;

            if (count >= 3) {
                found = 1;
            }
        } else {
            count = 1;
        }

        i++;
    }

    if (found) {
        printf("Result: repeated characters found.\n");
    } else {
        printf("Result: no repeated characters found.\n");
    }

    return 0;
}
