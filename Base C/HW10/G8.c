#include <stdio.h> 
#include "string.h"

#define SIZE 1001

void sort(int a[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = n - 1; j > i; j--)
            if (a[j] < a[j-1])
            {
                int tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
            }
}

int main() 
{ 
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    char buffer[SIZE];
    int numbers[SIZE];
    int number = 0;
    int digit = 0;
    int i = 0;

    char c;
    while((c=fgetc(input))!=EOF && c!='\n')
    {
        if (c >= 0x30 && c<=0x39)
        {
            
            number = number * 10 + c - 0x30;
            digit++;

            /*if (number == 0)
                {
                    numbers[i++] = number;
                    digit = 0;
                }*/
        }
        else
        {
            if (digit)
            {
                numbers[i++] = number;
                number = 0;
                digit = 0;
            }
        }
    }

    if (digit)
        numbers[i++] = number;

    fclose(input);
        
   sort(numbers, i);

   for (int j = 0; j < i; j++)
    fprintf(output, "%d ", numbers[j]);

    fclose(output);
    return 0; 
} 
