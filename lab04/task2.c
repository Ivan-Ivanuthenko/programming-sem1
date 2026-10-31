#include <stdio.h>
#include <stdint.h>

uint32_t set_bit(uint32_t reg, unsigned int n);
uint32_t clear_bit(uint32_t reg, unsigned int n);
uint32_t toggle_bit(uint32_t reg, unsigned int n);
int check_bit(uint32_t reg, unsigned int n);
void print_binary(uint32_t reg);

uint32_t set_bit(uint32_t reg, unsigned int n)
{
    return reg | (1u << n);
}

uint32_t clear_bit(uint32_t reg, unsigned int n)
{
    return reg & ~(1u << n);
}

uint32_t toggle_bit(uint32_t reg, unsigned int n)
{
    return reg ^ (1u << n);
}

int check_bit(uint32_t reg, unsigned int n)
{
    return (reg & (1u << n)) != 0;
}

void print_binary(uint32_t reg)
{
    for (int i = 31; i >= 0; i--)
    {
        printf("%u", (reg >> i) & 1u);

        if (i % 4 == 0)
        {
            printf(" ");
        }
    }

    printf("\n");
}

int main(void)
{
    uint32_t reg = 0x00400021;

    printf("32-bit GPIO register emulation\n");

    printf("\nInitial register:\n");
    print_binary(reg);

    printf("\n1. Set bit 12:\n");
    printf("Before: ");
    print_binary(reg);

    reg = set_bit(reg, 12);

    printf("After:  ");
    print_binary(reg);

    printf("\n2. Clear bit 0:\n");
    printf("Before: ");
    print_binary(reg);

    reg = clear_bit(reg, 0);

    printf("After:  ");
    print_binary(reg);

    printf("\n3. Toggle bit 5:\n");
    printf("Before: ");
    print_binary(reg);

    reg = toggle_bit(reg, 5);

    printf("After:  ");
    print_binary(reg);

    printf("\n4. Check bit 22:\n");
    printf("Register: ");
    print_binary(reg);

    if (check_bit(reg, 22))
    {
        printf("Bit 22 is SET (1).\n");
    }
    else
    {
        printf("Bit 22 is CLEAR (0).\n");
    }

    return 0;
}