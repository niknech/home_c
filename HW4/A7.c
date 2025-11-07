#include <stdio.h>

int main(int argc, char **argv)
{
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);
	if (a>b)
		printf("%d %d", b, a);
	else
		printf("%d %d", a, b);
	return 0;
}

