#include <stdio.h>
#include "stdint.h"
#include "inttypes.h"

int main(int argc, char **argv)
{
	uint32_t number = 0;
	uint8_t digit = 0;
	uint8_t digits[10] = {0};
	scanf("%"PRIu32, &number);
	
	while (number)
	{
		digit = number%10;
		digits[digit]++;
		
		if (digits[digit] > 1)
		{
			printf("YES");
			return 0;
		}
		number /= 10;
	}
	
	printf("NO");
	
	return 0;
}

