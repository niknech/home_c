#include <stdio.h>
#include <string.h>

#define SIZE 10

int CheckRepeat (int n, int *arr, int *result)
{	
	int already_added = 0;
	int count = 0;
	
	for (int i = 0; i < n; i++)
	{
		for(int k = 0; k < count; k++)
			if (result[k] == arr[i])
			{
				already_added = 1;
				break;
			}
		
		if (already_added)
		{
			already_added = 0;
			continue;
		}
		
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] == arr[j])
			{
				result[count] = arr[i];
				count++;
				break;
			}
		}
	}
	
	return count;
}

int main(int argc, char **argv)
{
	int arr[SIZE];
	int result[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	int count = CheckRepeat(SIZE, arr, result);
	for (int i = 0; i < count; i++)
		printf("%d ", result[i]);
	
	
	return 0;
}
