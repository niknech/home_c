#include <stdio.h>


int nod(int a, int b)
{
	while (a!=0 && b!=0)
	{
		if (a>b)
			a = a%b;
		else
			b = b%a;
	}
	return a+b;
}




int main()
{
	int a;
	int b;
	scanf("%d", &a);
	scanf("%d", &b);
	printf("%d", nod(a,b));
    return 0;
}
