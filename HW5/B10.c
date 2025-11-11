#include <stdio.h>
#include "stdint.h"
#include "inttypes.h"

int main(int argc, char **argv)
{
	uint32_t number = 0;
	uint8_t prev_digit = 0;
	scanf("%"PRIu32, &number);
	prev_digit = number%10;
	number /=10;
	
	while (number)
	{
		if (number%10 >= prev_digit)
		{
			printf("NO");
			return 0;
		}
		prev_digit = number%10;
		number /= 10;
	}
	
	printf("YES");
	
	return 0;
}

