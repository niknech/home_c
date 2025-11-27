#include <stdio.h>
#include <stdlib.h>

int RewriteMax (int N)
{	
	int result = 0;
	int tmp[20] = {0};
	int i = 19; 
	int count = 0;
	
	while (N)
	{
		tmp[i] = N%10;
		N /= 10;
		i--;
		count++;
	}
	
	for (int k = 20 - count; k < 19; k++)
		for (int j = 20 - count; j < 19; j++)
			if (tmp [j] < tmp [j+1])
			{
				int temp = tmp [j];
				tmp [j] = tmp [j+1];
				tmp[j+1] = temp;
			}
	
	for (int m = 20-count; m < 20; m++)
		result = result * 10 + tmp [m];
	
		
	return result;
}

int main(int argc, char **argv)
{
	int N;
	scanf("%d", &N);
	
	printf("%d", RewriteMax(N));
	
	return 0;
}
