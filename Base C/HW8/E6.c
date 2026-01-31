#include <stdio.h>

#define SIZE 12

float AvArr(int n, int *arr)
{
	float result = 0;
	
	for (int i = 0; i < n; i++)
		result += arr[i];
			
	return result/n;
}

int main(int argc, char **argv)
{
	int arr[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	printf("%.2f", AvArr(SIZE, arr));
	
	
	return 0;
}
