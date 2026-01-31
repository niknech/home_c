#include <stdio.h> 

int CountDiagonal(int matrix[][5], int size)
{
    int sum = 0;
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + matrix[i][j];
        j++;
    }
    return sum;
}

int main() { 
    
    int size = 5;
    int matrix[5][5];
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            scanf("%d", &matrix[i][j]);
    
    printf("%d", CountDiagonal(matrix, size));
    return 0; 
} 
