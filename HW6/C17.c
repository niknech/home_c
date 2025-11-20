#include <stdio.h>
#include "math.h"


char* is_happy_number(int n) 
{
	int sum = 0;
	int proizv = 1;
	
    while(n)
    {
		sum += n%10;
		proizv *= n%10;
		n/=10;
	}
	
	if (sum == proizv)
		return "YES";
	else
		return "NO";
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%s", is_happy_number(n));
    return 0;
}
