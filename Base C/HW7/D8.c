#include <stdio.h>

void printNumAB(int A, int B)
{	
	if (A > B)
	{
		printf("%d ", A);
		printNumAB(A-1, B);
		return;
	}
	else if (A < B)
	{
		printf("%d ", A);
		printNumAB(A+1, B);
		return;
	}
	
	printf("%d", B);
	return;

}


int main(int argc, char **argv)
{
	int A,B;
	scanf("%d", &A);
	scanf("%d", &B);
	printNumAB(A, B);
	return 0;
}