#include <stdio.h>
#include "stdint.h"
 
int find_max_array(int size, int a[])
{
    int max = INT16_MIN;

    for (int i; i < size; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

int main() { 
    int arr[100];
    int i = 0, num;

    while (scanf("%d", &num))
        arr[i++] = num;

    printf("%d", find_max_array(100, arr));
    return 0; 
} 
