#include <stdio.h>
#include "stdint.h"
#include "inttypes.h"

int main(int argc, char **argv)
{
	uint32_t number = 0;
	scanf("%"PRIu32, &number);
	
	while (number)
	{
		if ((number%10)%2 != 0)
		{
			printf("NO");
			return 0;
		}
		number /= 10;
	}
	
	printf("YES");
	
	return 0;
}

