#include <stdio.h>
#include <string.h>

#define SIZE 10

void CheckNullArr(int n, int *arr, int *result)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i]/10%10 == 0)
		{
			result[count] = arr[i];
			count++;
		}
	}
	
	for (int i = 0; i<count; i++)
		printf("%d ", result[i]);
			
	return;
}

int main(int argc, char **argv)
{
	int arr[SIZE];
	int result[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	CheckNullArr(SIZE, arr, result);
	
	
	return 0;
}
