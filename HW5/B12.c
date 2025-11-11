#include <stdio.h>
#include "stdint.h"
#include "inttypes.h"

int main(int argc, char **argv)
{
	uint32_t number = 0;
	uint8_t min = 0;
	uint8_t max = 0;
	scanf("%"PRIu32, &number);
	min = number%10;
	number /=10;
	max = min;
	
	
	while (number)
	{
		if (number%10 > max)
			max = number%10;
		else if (number%10 < min)
			min = number%10;
		
		number /= 10;
	}
	
	printf("%hhd %hhd", min, max);
	
	return 0;
}

