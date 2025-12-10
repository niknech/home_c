#include <stdio.h> 

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

 int sum_between_ab(int from, int to, int size, int a[])
 {
    int sum = 0;
    
    if (from > to)
        swap(&from, &to);

    for (int i = 0; i < size; i++)
    {
        if (a[i] >= from && a[i]<=to)
            sum += a[i];
    }

    return sum;
 }

int main() { 
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    printf("%d",count_between(2, 6, 10, arr));

    
    return 0; 
} 
