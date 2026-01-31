#include <stdio.h>
#include <inttypes.h>

uint32_t MaxSequence(uint32_t value, uint8_t K)
{
    uint32_t result = 0;
    uint32_t mask = 0;
    while (K)
    {
        mask = (mask << 1) | 1;
        K--;
    }

    while (value)
    {
        if ((value & mask) > result)
            result = value & mask;
        
        value >>= 1;
    }

    return result;
}

int main(void)
{
    uint32_t value;
    uint8_t K;

    scanf("%" SCNu32 " %" SCNu8, &value, &K);

    printf("%" PRIu32, MaxSequence(value, K));

    return 0;
}
