
#include <stdio.h>
#include <stdint.h>

void configure_register(uint32_t *reg)
{
    if (reg == NULL)
    {
        return;
    }

    *reg |= (1u << 6);

    *reg &= ~(1u << 0);

    *reg ^= (1u << 15);
}

int check_status_flag(const uint32_t *reg, uint8_t bit_pos)
{
    if (reg == NULL || bit_pos >= 32)
    {
        return 0;
    }

    return ((*reg >> bit_pos) & 1u);
}

int main(void)
{
    uint32_t reg = 0x01010001u;

    printf("Register before: 0x%08X\n", reg);

    configure_register(&reg);

    printf("Register after:  0x%08X\n", reg);

    printf("Bit 24 status: %d\n",
           check_status_flag(&reg, 24));

    return 0;
}
