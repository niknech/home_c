#include <stdio.h>
#include <string.h>

#define SIZE 10

void OffsetArr(int n, int *arr)
{
	int tmp = arr[n-1];
	memmove(arr + 1, arr, (n - 1) * sizeof(int));
	arr[0] = tmp;
	
	
	for (int i = 0; i < n; i++)
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
