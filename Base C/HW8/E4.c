#include <stdio.h>

int SumMax(int n, int *arr)
{
	int max = arr[0] > arr[1] ? arr[0] : arr[1];
	int prev_max = arr[0] < arr[1] ? arr[0] : arr[1];
	
	for (int i = 2; i < n; i++)
	{
		if (arr[i] > prev_max)
		{
			if (arr[i] > max)
			{
				prev_max = max;
				max = arr[i];
			}
			else
				prev_max = arr[i];
		}
	}
	return max+prev_max;
}

int main(int argc, char **argv)
{
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	printf("%d", SumMax(10, arr));
	
	
	return 0;
}