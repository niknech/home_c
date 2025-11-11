#include <stdio.h>
#include "inttypes.h"

uint32_t power(uint8_t number, uint8_t power);

int main(int argc, char **argv)
{
	uint8_t a = 0;
	uint8_t b = 0;
	scanf("%hhu", &a);
	scanf("%hhu", &b);
	uint32_t result = 0;
	for (int i = a; i<=b; i++)
	{
		result += power(i, 2);
		
	}
	printf("%"PRIu32" ", result);	
	return 0;
}

uint32_t power(uint8_t number, uint8_t power)
{
	uint32_t result = 1;
	
	for (uint8_t i = 1; i <= power; i++)
	{
		result *=number;
	}
	return result;
}
