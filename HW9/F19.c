#include <stdio.h> 
#include "stdint.h"

int CountPos(int matrix[][5], int size)
{
    int count = 0;
    int average = 0;
    int j = 0;

    for (int i = 0; i < size; i++)
    {
        average = average + matrix[i][j];
        j++;
    }
    average = average / size;
        
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] > 0 && matrix[i][j] > average)
                count++;
                
        }

    return count;
}

int main() { 
    
    int size = 5;
    int matrix[size][size];
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            scanf("%d", &matrix[i][j]);
    
    printf("%d", CountPos(matrix, size));
    return 0; 
} 
