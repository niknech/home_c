#include <stdio.h>

#define SIZE 12

void InvArr(int n, int *arr)
{
	int tmp;
	
	for (int i = 0; i < n/6; i++)
	{
		tmp = arr[i];
        arr[i] = arr[n/3 - 1 - i];
        arr[n/3 - 1 - i] = tmp;

		tmp = arr[n/3 + i];
		arr[n/3+i] = arr[n*2/3 -1 -i];
		arr[n*2/3 -1 -i] = tmp;

		tmp = arr[n*2/3 + i];
		arr[n*2/3 + i] = arr[n-1-i];
		arr[n-1-i] = tmp;
	}
		
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
	
	InvArr(SIZE, arr);
	
	
	return 0;
}
