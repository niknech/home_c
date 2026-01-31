#include <stdio.h>

float average(int n, int *arr)
{
	static float result = 0.0f;
	static int i = 0;
	if (i >= n)
		return result/n;
		
	result += arr[i];
	i++;
	average(n, arr);
}

int main(int argc, char **argv)
{
	int arr[5];
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	printf("%.3f", average(5, arr));
	return 0;
}
