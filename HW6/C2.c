#include <stdio.h>
#include "stdint.h"
#include "inttypes.h"

int power(int16_t number, uint8_t power);

int main(int argc, char **argv)
{
	int16_t number;
	uint8_t pow;
	scanf("%hd", &number);
	scanf("%hhu", &pow);
	printf("%d", power(number, pow));
	return 0;
}

int power(int16_t number, uint8_t power)
{
	uint32_t result = 1;
	
	for (uint8_t i = 1; i <= power; i++)
	{
		result *=number;
	}
	return result;
}

