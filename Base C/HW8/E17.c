#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void UniqueArr (int *arr)
{	
	int count = 0;
	int result [SIZE] = {0};
	int repeated = 0;
	
	for (int i = 0; i < SIZE; i++)
	{
		for (int k = 0; k < SIZE; k++)
			if (arr[i] == arr[k])
				repeated++;
		
		if (repeated == 1)
		{
			result[count] = arr[i];
			count++;
		}
		repeated = 0;		
	}
	
	for (int i = 0; i < count; i++)
		printf("%d ", result[i]);
	return;
}

int main(int argc, char **argv)
{
	int arr[SIZE];
	
	for (int i = 0; i < SIZE; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	UniqueArr (arr);
	
	return 0;
}
