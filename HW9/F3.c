#include <stdio.h> 
#include "stdint.h"
#include "inttypes.h"

void print_digits()
{
    char c;
    int n;
    int a[10] = {0};

    while ((c=getchar())!='\n')
    {
        if (c >= 0x30 && c<= 0x39)
            n = c - 0x30;
        else
            return;

        a[n]++;
    }
    
    for (int i = 0; i < 10; i++)
        {
            if (a[i] > 0)
                printf ("%d %d\n", i, a[i]);
        }

    return;
}

int main() { 
    print_digits();
    return 0; 
} 
