#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void PosNegArr (int *arr, int **pos, int **neg, int *posCount, int *negCount)
{	
	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] > 0)
		{
			*(*pos + *posCount) = arr[i];
			*posCount = *posCount + 1;
		}
		else if (arr[i] < 0)
		{
			*(*neg + *negCount) = arr[i];
			*negCount = *negCount + 1;
		}
	}
	
	int *tmp = realloc(*pos, *posCount*sizeof(int));
	*pos = tmp;
	tmp = realloc(*neg, *negCount*sizeof(int));
	*neg = tmp;
	
	return;
}

int main(int argc, char **argv)
{
	int arr[SIZE];
	int *pos = malloc(SIZE * sizeof(int));
	int *neg = malloc(SIZE * sizeof(int));
	int posCount = 0;
	int negCount = 0;
	
	for (int i = 0; i < SIZE; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	PosNegArr (arr, &pos, &neg, &posCount, &negCount);
	
	for (int i = 0; i < posCount; i++)
		printf("%d ", pos[i]);
		
	for (int i = 0; i < negCount; i++)
		printf("%d ", neg[i]);
	
	free(pos);
	free(neg);
	
	return 0;
}
