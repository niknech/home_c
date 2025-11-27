#include <stdio.h>
#include <string.h>

#define SIZE 10

void swap (int *a, int *b)
{
	int tmp = *b;
	*b = *a;
	*a = tmp;
	return;
}

void SortArr(int n, int *arr)
{
	for (int i = 0; i < n-1; i++)
	{
		if (i < n/2)
			for (int j = 0; j < n/2-i-1; j++)
			{
				if (arr[j] > arr[j+1])
				{
					swap(&arr[j], &arr[j+1]);
				}
			}
		else
			for (int j = n/2; j < n-1; j++)
			{
				if (arr[j] < arr[j+1])
				{
					swap(&arr[j], &arr[j+1]);
				}
			}
		
	}
	
	for (int i = 0; i<n; i++)
		printf("%d ", arr[i]);
			
	return;
}

int main(int argc, char **argv)
{
	int arr[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	SortArr(SIZE, arr);
	
	
	return 0;
}