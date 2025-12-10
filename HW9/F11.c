#include <stdio.h>
#include "stdint.h"

void print_min_sum(int size, int arr[])
{
    int result [2] = {0};
    int min = INT16_MAX;

    for (int i = 0; i < size; i++)
        for (int j = i+1; j<size; j++)
            if (arr[i] + arr[j] < min)
            {
                result[0] = i;
                result[1] = j;
                min = arr[i] + arr[j];
            }

    printf("%d %d", result[0], result[1]);
}

int main() { 
    int arr[1000] = {0};
    int i = 0, num;

    while (i<30)
        scanf("%d", &arr[i++]);

    print_min_sum(i, arr);

    return 0; 
} 
