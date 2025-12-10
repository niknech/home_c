#include <stdio.h> 

void sort_array(int size, int a[])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = size - 1; j > i; j --)
        {
            if (*(a + j-1) > *(a+j))
            {
                int temp = *(a+j);
                *(a+j) = *(a+j-1);
                *(a+j-1) = temp;
            }
        }
    }
}

int main(void) {
    int a [] = {5,4,2,34,24,3}; 
    sort_array(6, a);

    for (int i = 0; i < 6; i++)
        printf("%d ", a[i]);

    return 0; 
} 
