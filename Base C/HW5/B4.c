#include <stdio.h>
#include "stdint.h"
#include "inttypes.h"

int main(int argc, char **argv)
{
	uint32_t number = 0;
	scanf("%"PRIu32, &number);
	uint8_t count = 0;
	
	while(number)
	{
		number /=10;
		count++;
	}
	
	if (count == 3)
		printf("YES");
	else
		printf("NO");
	
	return 0;
}

