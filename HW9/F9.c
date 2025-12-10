#include <stdio.h>
#include "stdint.h"

void swap_negmax_last(int size, int a[])
{
    int min = INT16_MIN;
    int number, swapped = 0;

    for (int i = 0; i < size; i++)
    {
        if (a[i]< 0 && a[i] > min)
        {
            min = a[i];
            number = i;
            swapped = 1;
        }
    }
    
    if (swapped)
    {
        a[number] = a[size-1];
        a[size-1] = min;
    }

}

int main() { 
    int arr[1000];
    int i = 0, num;

    while (scanf("%d", &num))
        arr[i++] = num;

    swap_negmax_last(i,arr);

    for (int j = 0; j < i; j++)
        printf("%d ", arr[j]);

    return 0; 
} 
