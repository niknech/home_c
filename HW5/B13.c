#include <stdio.h>
#include "stdint.h"
#include "inttypes.h"

int main(int argc, char **argv)
{
	uint32_t number = 0;
	uint8_t even = 0;
	uint8_t odd = 0;
	scanf("%"PRIu32, &number);

	
	while (number)
	{
		(number%10)%2 == 0 ? even++ : odd++;
		
		number /= 10;
	}
	
	printf("%hhd %hhd", even, odd);
	
	return 0;
}

