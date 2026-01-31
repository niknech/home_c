#include <stdio.h>

int recurs_power(int n, int p)
{
	static int current_pow = 1;
	static int firstCallFlag = 1;
	static int result;
	
	if (firstCallFlag)
	{
		result = n;
		firstCallFlag = 0;
	}
	
	if (p == 0)
		return 1;
	
	if (current_pow == p)
		return result;
	
	result *= n;
	current_pow++;
	
	return recurs_power(n,p);
	
}

int main(int argc, char **argv)
{
	int n, p;
	scanf("%d", &n);
	scanf("%d", &p);
	printf("%d ", recurs_power(n,p));
	
	return 0;
}

