#include <stdio.h>

void printDigits(int N)
{
	if (N == 0)
		printf("%d ", 0);
	else
	{
		printf("%d ", N%10);
		if (N/10 == 0) return;
		printDigits(N/10);
	}
}

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	printDigits(n);
	return 0;
}

