#include <stdio.h>
#include "stdint.h"
#include "inttypes.h"

uint64_t powerOfTwo(uint8_t power)
{
	uint64_t result = 1;
	
	power--;
	
	for (uint8_t i = 1; i <= power; i++)
	{
		result *=2;
	}
	return result;
}

int main()
{
	uint8_t N;
	scanf("%hhu", &N);
	printf("%llu", powerOfTwo(N));
    return 0;
}
