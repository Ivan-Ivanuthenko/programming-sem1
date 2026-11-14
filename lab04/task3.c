#include <stdio.h>
#include <stdint.h>

uint16_t pack_data(unsigned int version,
                   unsigned int length,
                   unsigned int crc);

void unpack_data(uint16_t data,
                 unsigned int *version,
                 unsigned int *length,
                 unsigned int *crc);

uint16_t pack_data(unsigned int version,
                   unsigned int length,
                   unsigned int crc)
{
    return (uint16_t)(
        (version & 0x0F) |
        ((length & 0xFF) << 4) |
        ((crc & 0x0F) << 12)
    );
}

void unpack_data(uint16_t data,
                 unsigned int *version,
                 unsigned int *length,
                 unsigned int *crc)
{
    *version = data & 0x0F;
    *length = (data >> 4) & 0xFF;
    *crc = (data >> 12) & 0x0F;
}

int main(void)
{
    unsigned int version = 5;
    unsigned int length = 150;
    unsigned int crc = 10;

    unsigned int restoredVersion;
    unsigned int restoredLength;
    unsigned int restoredCrc;

    uint16_t packet;

    printf("Telemetry packet packing\n");

    printf("\nOriginal data:\n");
    printf("Protocol version: %u\n", version);
    printf("Packet length: %u\n", length);
    printf("CRC: %u\n", crc);

    packet = pack_data(version, length, crc);

    printf("\nPacked packet:\n");
    printf("HEX: 0x%04X\n", packet);

    unpack_data(packet,
                &restoredVersion,
                &restoredLength,
                &restoredCrc);

    printf("\nRestored data:\n");
    printf("Protocol version: %u\n", restoredVersion);
    printf("Packet length: %u\n", restoredLength);
    printf("CRC: %u\n", restoredCrc);

    if (version == restoredVersion &&
        length == restoredLength &&
        crc == restoredCrc)
    {
        printf("\nData verification: SUCCESS\n");
    }
    else
    {
        printf("\nData verification: FAILED\n");
    }

    return 0;
}