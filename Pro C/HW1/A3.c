#include <stdio.h>
#include <inttypes.h>

uint32_t TakeBits(uint32_t value, uint8_t K)
{
    uint32_t mask = 0;
    while (K)
    {
        mask = (mask << 1) | 1;
        K--;
    }
    return (value & mask);
}

int main(void)
{
    uint32_t value;
    uint8_t K;

    scanf("%" SCNu32 " %" SCNu8, &value, &K);

    printf("%" PRIu32, TakeBits(value, K));

    return 0;
}
