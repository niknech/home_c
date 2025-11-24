#include <stdio.h>


void printNum(int n)
{
	static int i = 0;
	static int a = 1;
	
	if (i < n)
	{
		int j = 0;
		
		while (j<a)
		{
			if (i >= n)
				break;
			printf("%d ", a);
			j++;
			i++;
		}
		a++;
		printNum(n);
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

