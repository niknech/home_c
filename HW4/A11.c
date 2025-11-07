#include <stdio.h>

int main(int argc, char **argv)
{
	int recieved = 0;
	int max = 0;
	int min = 0;
	scanf("%d", &max);
	min = max;
	
	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &recieved);
		max = recieved > max ? recieved : max;
		min = recieved < min ? recieved : min;
	}
	
	printf("%d", max+min);
	return 0;
}

