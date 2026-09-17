#include <stdio.h>

int main(void) {
    printf("Size of char: %zu bytes\n", sizeof(char));
    printf("Size of short: %zu bytes\n", sizeof(short));
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of long: %zu bytes\n", sizeof(long));
    printf("Size of long long: %zu bytes\n", sizeof(long long));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));
    printf("Size of void*: %zu bytes\n", sizeof(void*));

    unsigned char byte_test = 255;

    printf("\nBefore overflow:\n");
    printf("Decimal: %u\n", byte_test);
    printf("Hex: 0x%02X\n", byte_test);

    byte_test = byte_test + 1;

    printf("\nAfter overflow:\n");
    printf("Decimal: %u\n", byte_test);
    printf("Hex: 0x%02X\n", byte_test);

    return 0;
}