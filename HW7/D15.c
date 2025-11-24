#include <stdio.h>

int max_find()
{
	static int max = 0;
	static int firstTimeFlag = 1;
	int number;
	
	if (firstTimeFlag)
	{
		scanf("%d", &max);
		firstTimeFlag = 0;
	}
	
	scanf("%d", &number);
	
	if (number == 0) return max;
	
	if (number > max)
		max = number;
	
	max_find();
	
	return max;
}

int main(int argc, char **argv)
{
	printf("%d", max_find());
	
	return 0;
}

