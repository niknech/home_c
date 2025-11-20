#include <stdio.h>
#include "stdint.h"
#include "inttypes.h"

int middle(int a, int b);

int main(int argc, char **argv)
{
	int a;
	int b;
	scanf("%d", &a);
	scanf("%d", &b);
	printf("%d", middle(a,b));
	return 0;
}

int middle(int a, int b)
{
	return (a+b)/2;
}

