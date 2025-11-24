#include <stdio.h>

void printDigits(int N)
{
	static int firstCall = 1;
    
    if(N == 0 && firstCall)
    {
        printf("0");  
        firstCall = 0;
        return;
    }
    
    firstCall = 0;
	
	if(N == 0)
        return;
	
	printDigits(N/10);
	printf("%d ", N%10);
}

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	printDigits(n);
	return 0;
}

