#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int MaxCountArr (int *arr, int n)
{	
	int max = -2147483648;
	int count [SIZE] = {0};
	
	for (int i = 0; i < SIZE; i++)
		for (int j = i+1; j < SIZE; j++)
			if (arr[j] == arr[i])
				count[i]++;
	
	for (int i = 0; i < SIZE; i++)
		if(count[i] > max)
			max = i;
	
	return arr[max];
}

int main(int argc, char **argv)
{
	int arr[SIZE];
	
	for (int i = 0; i < SIZE; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	printf("%d", MaxCountArr(arr, SIZE));
	
	return 0;
}
