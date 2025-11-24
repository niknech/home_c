#include <stdio.h>

void printNumbers(int N)
{
	if (N != 0)
	{
		printNumbers(N-1);
		printf("%d ", N);
	}
}

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	printNumbers(n);
	return 0;
}

