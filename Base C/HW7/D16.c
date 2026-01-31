#include <stdio.h>

char* is2pow(int n)
{
	if (n == 1)
		return "YES";
	
	if (n % 2 == 0)
	{
		return is2pow(n/2);
	}
	else
		return "NO";
}

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	printf(is2pow(n));
	
	return 0;
}

