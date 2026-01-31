#include <stdio.h>
#include <inttypes.h>

uint32_t inverseHighestByte(uint32_t value)
{
    return (value ^ 0xFF000000);
}

int main(void)
{
    uint32_t value;

    scanf("%" SCNu32 , &value);

    printf("%" PRIu32, inverseHighestByte(value));

    return 0;
}
