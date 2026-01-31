#include <stdio.h> 
#include "string.h"

void print_digit(char s[])
{
    int a[10] = {0};
    int n;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 0x30 && s[i]<= 0x39)
        {
            n = s[i] - 0x30;
            a[n]++;
        }
    }

    for (int i = 0; i<10; i++)
        if (a[i] > 0)
            printf("%d %d\n", i, a[i]);
}

int main() { 
    char s[100] = {0};
    scanf("%[^\n]", s);

    print_digit(s);
    return 0; 
} 
