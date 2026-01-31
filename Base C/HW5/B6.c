#include <stdio.h>
#include "stdint.h"
#include "inttypes.h"

int main(int argc, char **argv)
{
	uint32_t number = 0;
	uint8_t prev_digit = 0;
	scanf("%"PRIu32, &number);
	
	char* message = "NO";
	
	prev_digit = number%10;
	number /=10;
	
	while (number)
	{
		if (number%10 == prev_digit)
		{
			message = "YES";
			break;
		}
		else
		{
			prev_digit = number%10;
			number /=10;
		}
	}
	
	printf(message);
	return 0;
}

