#include <stdio.h>
#include "stdint.h"
#include "inttypes.h"

int main(int argc, char **argv)
{
	uint32_t number = 0;
	scanf("%"PRIu32, &number);
	
	for (uint32_t i=10; i<=number; i++)
	{
		uint32_t temp = i;
		uint32_t sum = 0;
		uint32_t proizv = 1;
		while(temp)
		{
			sum += temp%10;
			proizv *= temp%10;
			temp /= 10;
		}
		
		if (sum == proizv)
			printf("%"PRIu32" ", i);
	}
	
	return 0;
}

