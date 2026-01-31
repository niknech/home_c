#include <stdio.h>
#include "stdint.h"
 
void change_max_min(int size, int a[])
{
    int min = INT16_MAX;
    int max = INT16_MIN;
    int min_index, max_index;

    for (int i = 0; i < size; i++)
    {
        if (a[i]<min)
        {
            min = a[i];
            min_index = i;
        }
        if (a[i]>max)
        {
            max = a[i];
            max_index = i;
        }
    }

    int temp = a[max_index];
    a[max_index] = a[min_index];
    a[min_index] = temp;
}

int main() { 
    
    /*int arr[1000];
    int i = 0, num;

    while (scanf("%d", &num))
        arr[i++] = num; */

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    change_max_min(10, arr);

    return 0; 
} 
