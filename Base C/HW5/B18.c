#include <stdio.h>
#include "stdint.h"
#include "inttypes.h"

int main(int argc, char **argv)
{
	uint32_t n = 0;
	scanf("%"PRIu32, &n);
	uint32_t arr[2] = {1, 1};
	
	
	for (int i = 0; i < n; i++)
	{
		if (i < 2)
			printf("%"PRIu32" ", arr[i]);
		else
		{
			uint32_t number = arr[0] + arr[1];
			arr[0] = arr[1];
			arr[1] = number;
			printf("%"PRIu32" ", number);
		}

	}
	
	return 0;
}

