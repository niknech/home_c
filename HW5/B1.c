#include <stdio.h>
#include "inttypes.h"

uint32_t power(uint8_t number, uint8_t power);

int main(int argc, char **argv)
{
	uint8_t number = 0;
	scanf("%hhu", &number);
	
	for (int i = 1; i<=number; i++)
	{
		for (int j = 1; j<=3; j++)
		{
			printf("%"PRIu32" ", power(i, j));	
		}
		printf("\n");
	}
	
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
