#include <stdio.h>

void print_digits(int n)
{
	if (n == 0) return;
	
	int digit = n%10;
	print_digits(n/10);
	printf("%d ", digit);
}

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	print_digits(n);
	
	return 0;
}

