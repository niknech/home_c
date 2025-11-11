#include <stdio.h>
#include "stdint.h"
#include "inttypes.h"

int main(int argc, char **argv)
{
	uint32_t number = 0;
	scanf("%"PRIu32, &number);
	uint32_t result = 0;
	
	while(number)
	{
		result += number % 10;
		number /=10;
	}
	
	printf("%"PRIu32, result);
	
	return 0;
}

