#include "stdio.h"
#include "string.h"
#include "inttypes.h"


void FindMax (int value, int* max, int* count)
{

    uint32_t x = value ^ *max;
    if (!x)
    {
        *max = value;
        (*count)++;
        return;
    }

    uint32_t y = 1 << 31;

    uint8_t s_value = (value >> 31) & 1;
    uint8_t s_max = (*max >> 31) & 1;

    if (!(s_value ^ s_max))
    {
        while(!(y & x)) y >>= 1;

        if (value & y)
        {
            *max = value;
            *count = 1;
            return;
        }
    }
    else if (!(s_value & 1))
    {
        *max = value;
        *count = 1;
        return;
    }
}

int main (int argc, char* argv[])
{
    int max = INT32_MIN;
    int count = 0;

    int N, value;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &value);
        FindMax(value, &max, &count);
    }

    printf("%d", count);

    return 0;
}