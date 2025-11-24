#include <stdio.h>

void PrintOdd()
{
	
	int number;
	
	scanf("%d", &number);
	
	if (number == 0) return;
	
	if (number % 2 != 0)
		printf("%d ",  number);
	
	PrintOdd();
	
	return;
}

int main(int argc, char **argv)
{
	PrintOdd();
	
	return 0;
}
