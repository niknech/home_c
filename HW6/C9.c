#include <stdio.h>
#include "string.h"
#include "stdlib.h"


int factorial(int n)
{
	int result = 1;
	
	for (int i = 1; i<=n; i++)
	{
		result *= i;
	}
	
	return result;
}




int main()
{
	int number;
	scanf("%d", &number);
	printf("%d", factorial(number));
    return 0;
}
