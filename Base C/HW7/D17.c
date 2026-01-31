#include <stdio.h>

int akkerman(int m, int n)
{
	if (m == 0)
		return n+1;
	else if (m > 0 && n == 0)
		return akkerman(m-1, 1);
	else
		return akkerman(m-1, akkerman(m,n-1));
}

int main(int argc, char **argv)
{
	int n,m;
	scanf("%d", &m);
	scanf("%d", &n);
	printf("%d", akkerman(m,n));
	
	return 0;
}

