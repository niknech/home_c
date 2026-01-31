#include <stdio.h>
#include "stdint.h"

uint16_t SumAll(uint16_t N)
{
	static uint16_t count = 1;
	static uint16_t sum = 0;
	if(count <= N)
		{
			sum = sum + count;
			count++;
			SumAll(N);
		}
	return(sum);
}

int main()
{
	uint16_t N;
	scanf("%hu", &N);
	printf("%hu", SumAll(N));
    return 0;
}
