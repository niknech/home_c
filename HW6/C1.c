#include <stdio.h>

int abs (int number);

int main(int argc, char **argv)
{
	int number;
	scanf("%d", &number);
	printf("%d", abs(number));
	return 0;
}

int abs (int number)
{
	return number > 0 ? printf("%d", number) : printf ("%d", -number);
}

