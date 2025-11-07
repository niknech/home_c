#include <stdio.h>

int main(int argc, char **argv)
{
	int recieved = 0;
	int max = 0;
	scanf("%d", &recieved);
	
	while (recieved)
	{
		max = recieved % 10 > max ? recieved % 10 : max;
		recieved /=10;
	}
	
	printf("%d", max);
	return 0;
}

