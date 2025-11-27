#include <stdio.h>

int minArr(int n, int *arr)
{
	int min = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}

int main(int argc, char **argv)
{
	int arr[5];
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	printf("%d", minArr(5, arr));
	return 0;
}

