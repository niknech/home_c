#include <stdio.h>

int main(int argc, char **argv)
{
	int recieved = 0;
	int min = 0;
	scanf("%d", &min);
	
	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &recieved);
		min = recieved < min ? recieved : min;
	}
	
	printf("%d", min);
	return 0;
}

