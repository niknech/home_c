#include <stdio.h>

int main(int argc, char **argv)
{
	int a,b;
	scanf("%d", &a);
	scanf("%d", &b);
	
	char* result = a>b ? "Above" : a<b ? "Less" : "Equal";
	printf(result);
	return 0;
}

