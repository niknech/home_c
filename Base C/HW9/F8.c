#include <stdio.h> 

int find_skipped(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            if (a[j] < a[j-1])
            {
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++)
        if (a[i+1] - a[i] != 1)
            return a[i] + 1;
}

int main() { 
    int arr[1000];
    int i = 0, num;

    while (scanf("%d", &num) && num!=0)
        arr[i++] = num;

    printf("%d", find_skipped(arr, i));
    return 0; 
} 
