#include <stdio.h>
#include <string.h>

#define SIZE 12

void OffsetArr(int n, int *arr)
{
	int tmp;
	for (int i = 4; i > 0; i--)
	{
		tmp = arr[n-i];
		for (int j = n-1-i; j >= n - 8 - i; j--)
		{
			arr[j+1] = arr[j];
		}
		arr[n-8-i] = tmp;
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
	
	OffsetArr(SIZE, arr);
	
	
	return 0;
}
