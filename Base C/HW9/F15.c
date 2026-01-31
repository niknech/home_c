#include <stdio.h> 
#include "stdint.h"
#include "math.h"

int count_bigger_abs(int n, int a[])
 {
    int max = INT16_MIN;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i]>max)
        {
            max = a[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (abs(a[i])>abs(max))
        {
            count++;
        }
    }

    
    return count;
 }

int main() { 
    int arr[10] = {1,2,3,4,5,-60,-70,8,9,10};

    printf("%d", count_bigger_abs(10, arr));

    
    return 0; 
} 
