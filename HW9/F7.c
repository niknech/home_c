#include <stdio.h> 
#include <string.h>
 
int compression(int a[], int b[], int N) 
{
    int j = 0;
    int prev_element = 0;
    memset(b, 0, sizeof(b));    

    for (int i = 0; i < N; i++)
    {   
        if (!(a[i] ^ prev_element))
            {
                b[j]++;
            }
            else
            {
                b[++j]++;
            }
            prev_element = a[i];
    }
    return ++j;
}

int main() { 
    int a[] = {0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1};
    int b[17] = {0};

    int size = compression(a,b,17);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", b[i]);
    }

    return 0; 
} 
