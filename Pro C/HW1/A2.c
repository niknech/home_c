#include <stdio.h>
#include <inttypes.h>

uint32_t LeftShift(uint32_t value, uint8_t K)
{
    return (value >> K) | (value << (32 - K));
}

int main(void)
{
    uint32_t value;
    uint8_t K;

    scanf("%" SCNu32 " %" SCNu8, &value, &K);

    printf("%" PRIu32, LeftShift(value, K));

    return 0;
}
