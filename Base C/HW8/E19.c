#include <stdio.h>
#include <stdlib.h>

void PrintDigits (int N)
{	
	if (N == 0)
		return;
	PrintDigits(N/10);
	printf("%d ", N%10);
		
	return;
}

int main(int argc, char **argv)
{
	int N;
	scanf("%d", &N);
	
	PrintDigits (N);
	
	return 0;
}