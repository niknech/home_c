#include <stdio.h>
#include "stdint.h"
#include "inttypes.h"

int main(int argc, char **argv)
{
	char input = '\0';
	uint32_t count = 0;
	uint32_t number = 0;
	while((input = getchar()) != '\n')
	{
		if (input >= '0' && input <= '9')
				number = number * 10 + input - '0';
			
		if (input == ' ')
		{
			number%2 == 0 ? count++ : 0;
			number = 0;
		}
	}
	printf("%"PRIu32, count);
	return 0;
}

