#include <stdio.h> 

int Input(int arr[], int size)
{
    int i = 0, num;
    while(i < size && scanf("%d",&num)==1)
        arr[i++] = num;
    return i;
}


int is_two_same(int size, int a[])
{
    for (int i = 0; i < size; i++)
        for (int j = size - 1; j > i; j--)
            if (a[i] == a[j])
                return 1;
    return 0;
}

int main() { 
    int arr[100];
    int size = Input(arr, 100);

    printf("%d", is_two_same(size, arr));
    
    return 0; 
} 
