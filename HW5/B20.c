#include <stdio.h>
#include "stdint.h"
#include "inttypes.h"
#include "math.h"

int main(int argc, char **argv)
{
	uint32_t number = 0;
	scanf("%"PRIu32, &number);	
	
	if (number < 2)
	{
		printf ("NO");
		return 0;
	}
	
	if (number == 2)
	{
		printf ("YES");
		return 0;
	}
	
	if (number % 2 == 0)
	{
		printf ("NO");
		return 0;
	}
	
	uint32_t max = sqrt(number);
	
	for(uint32_t i = 3; i <= max; i++)
	{
		if (number % i == 0)
		{
			printf ("NO");
			return 0;
		}
	}
	
	printf("YES");
	
	return 0;
}

