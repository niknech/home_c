#include <stdio.h>
#include "stdint.h"
#include "inttypes.h"

int main(int argc, char **argv)
{
	char input = '\0';
	uint32_t count = 0;
	while((input = getchar()) != '\n')
	{
		if (input == ' ')
			count++;
	}
	printf("%"PRIu32, count);
	return 0;
}

