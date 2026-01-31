#include <stdio.h> 
#include <inttypes.h>

int main() 
{ 
    uint32_t N, value;
    uint32_t result = 0;

    scanf("%" SCNu32 , &N);
    for (int i=0; i<N; i++)
    {
        scanf("%" SCNu32 , &value);
        result ^= value;
    }

    printf("%" PRIu32 , result);

    return 0; 
} 
