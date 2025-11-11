#include <stdio.h>
#include "stdint.h"
#include "inttypes.h"

int main(int argc, char **argv)
{
	uint32_t a,b;
	scanf("%"PRIu32, &a);
	scanf("%"PRIu32, &b);
	
	while(a && b)
	{
		if (a > b)
			a = a % b;
		else
			b = b % a;
	}
	
	printf("%"PRIu32, a+b);
	return 0;
}

