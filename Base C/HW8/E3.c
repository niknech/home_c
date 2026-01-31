#include <stdio.h>

void MinMaxArr(int n, int *arr, int *max, int *posMax, int *min, int *posMin)
{
	*max = arr[0];
	*min = arr[0];
	*posMax = 1;
	*posMin = 1;
	
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < *min)
		{
			*min = arr[i];
			*posMin = i+1;
		}
		
		if (arr[i] > *max)
		{
			*max = arr[i];
			*posMax = i+1;
		}
	}
}

int main(int argc, char **argv)
{
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	int max, posMax, min, posMin;
	
	MinMaxArr(10, arr, &max, &posMax, &min, &posMin);
	
	printf("%d %d %d %d", posMax, max, posMin, min);
	return 0;
}
