#include <stdio.h>
#include "math.h"

char* CheckParity(int x)
{
	int sum = 0;
	
	while(x)
	{
		sum += x%10;
		x/=10;
	}
	
	if (sum%2 == 0)
		return "YES";
	else
		return "NO";
}

int main()
{
    int x;
    scanf("%d", &x);
    printf("%s", CheckParity(x));
    return 0;
}
