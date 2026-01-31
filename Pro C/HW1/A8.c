#include <stdio.h>
#include <stdint.h>
#include "inttypes.h"

int main(void)
{
    uint32_t m;
    if (scanf("%" SCNu32, &m) != 1)
        return 0;

    const uint32_t CAP = 1000000;
    uint32_t pow3 = 1;
    int cnt = 0;
    uint32_t sumLeft = 0;
    uint32_t sumRight = 0;

    while (m > 0)
    {
        uint32_t r = m % 3;

        if (r == 0)
        {
            m /= 3;
        }
        else if (r == 1)
        {
            cnt++;
            sumRight += pow3;
            m /= 3;
        }
        else
        {
            cnt++;
            sumLeft += pow3;
            m = (m + 1) / 3;
        }

        if (sumLeft > CAP || sumRight > CAP)
        {
            printf("-1\n");
            return 0;
        }

        pow3 *= 3;
    }

    printf("%d\n", cnt);
    return 0;
}
