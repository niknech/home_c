#include <stdio.h>
#include "stdint.h"
#include "inttypes.h"

int main(int argc, char **argv)
{
	uint32_t number = 0;
	uint32_t sum = 0;
	scanf("%"PRIu32, &number);	
	
	while(number)
	{
		sum += number%10;
		number /=10;
	}
	
	sum == 10 ? printf("YES") : printf("NO");
	
	return 0;
}

