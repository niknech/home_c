#include <stdio.h>
#include <inttypes.h>

uint32_t quantityOfBits(uint32_t value)
{
    uint32_t count = 0;

    while (value)
    {
        count = count + (value & 0x01);
        value >>= 1;
    }

    return count;
}

int main(void)
{
    uint32_t value;

    scanf("%" SCNu32 , &value);

    printf("%" PRIu32, quantityOfBits(value));

    return 0;
}
