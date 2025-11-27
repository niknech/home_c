#include <stdio.h>

int SumPos(int n, int *arr)
{
	int result = 0;
	
	for (int i = 0; i < n; i++)
		if (arr[i] > 0)
			result += arr[i];
	return result;
}

int main(int argc, char **argv)
{
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	printf("%d", SumPos(10, arr));
	
	
	return 0;
}