#include <stdio.h> 

 int count_between(int from, int to, int size, int a[])
 {
    int count = 0;
    
    for (int i = 0; i < size; i++)
    {
        if (a[i] >= from && a[i]<=to)
            count++;
    }

    return count;
 }

int main() { 
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    printf("%d",count_between(2, 6, 10, arr));

    
    return 0; 
} 
