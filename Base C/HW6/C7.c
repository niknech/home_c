#include <stdio.h>
#include "stdint.h"
#include "inttypes.h"

uint32_t ConvertToDec(uint32_t n, uint8_t p)
{
	uint32_t result = 0;
	uint32_t digit = 1;
	
	while(n >= p)
	{
		result = result + (n%p)*digit;
		digit = 10*digit;
		n=n/p;
	}
	result = result + n*digit;
	return result;
}




int main()
{
	uint32_t n;
	uint32_t p;
	scanf("%"PRIu32, &n);
	scanf("%"PRIu32, &p);
	printf("%"PRIu32, ConvertToDec(n, p));
    return 0;
}
