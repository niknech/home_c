#include <stdio.h>
#include "stdint.h"
#include "inttypes.h"

int main(int argc, char **argv)
{
	uint32_t number = 0;
	uint32_t turned_over_number = 0;
	scanf("%"PRIu32, &number);
	
	while (number)
	{
		turned_over_number = turned_over_number * 10 + number%10;
		number /= 10;
	}
	
	printf("%"PRIu32, turned_over_number);
	
	return 0;
}

