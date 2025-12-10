#include <stdio.h> 
#include "stdint.h"

int MaxArr(int arr[], int size)
{
    int max = INT16_MIN;
    for (int i = 0; i < size; i++)
        if (arr[i]>max)
            max = arr[i];
    
    return max;
}

int SumMax(int matrix[][10], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
        sum = sum + MaxArr(matrix[i], size);

    return sum;
}

int main() { 
    
    int size = 10;
    int matrix[10][10];
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            scanf("%d", &matrix[i][j]);
    
    printf("%d", SumMax(matrix, size));
    return 0; 
} 
