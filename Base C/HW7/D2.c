#include <stdio.h>

int sumNumbers(int N)
{
	static int sum = 0;
	if (N != 0)
	{
		sumNumbers(N-1);
		sum += N;
	}
	return sum;
}

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	printf("%d",sumNumbers(n));
	return 0;
}

