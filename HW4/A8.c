#include <stdio.h>

int main(int argc, char **argv)
{
	int recieved = 0;
	int max = 0;
	scanf("%d", &max);
	
	for (int i = 0; i < 2; i++)
	{
		scanf("%d", &recieved);
		max = recieved > max ? recieved : max;
	}
	
	printf("%d", max);
	return 0;
}

