#include <stdio.h>
#include "math.h"

char* grow_up(int n)
{
	int prev_digit = n%10;
	n /=10;
	while (n)
	{
		if (n%10<prev_digit)
		{
			prev_digit = n%10;
			n/=10;
		}
		else
			return "NO";
	}
	
	return "YES";
}

int main()
{
    int x;
    scanf("%d", &x);
    printf("%s", grow_up(x));
    return 0;
}
