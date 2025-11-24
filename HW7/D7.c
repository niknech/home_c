#include <stdio.h>

void printNum(int N)
{
	if (N >= 1)
	{
		printf("%d ", N);
		printNum(N-1);
	}
	return;
}


int main(int argc, char **argv)
{
	int N;
	scanf("%d", &N);
	printNum(N);
	return 0;
}

