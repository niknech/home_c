#include <stdio.h>
#include "stdint.h"
#include "inttypes.h"

int main(int argc, char **argv)
{
	uint32_t number = 0;
	uint8_t count = 0;
	scanf("%"PRIu32, &number);
	
	while (number)
	{
		if (number%10 == 9)
			count++;
		number /=10;	
	}
	
	if (count == 1)
		printf("YES");
	else
		printf("NO");
	
	return 0;
}

