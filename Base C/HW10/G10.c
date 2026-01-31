#include <stdio.h> 
#include "string.h"

#define SIZE 1001

int main() 
{
    int count = 0;
    int max = 0;
    int cel = 0;

    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    char buffer[SIZE];
    char result[SIZE];

    fgets(buffer, SIZE, input);
    fclose(input);
    
    int size = strlen(buffer);

    for (int i=0; i<size; i++)
    {
        if (buffer[i] != ' ')
            count++;
        else if (count > max)
        {
            max = count;
            cel = i;
            count = 0;
        }
    }

    for (int i=0; i<max; i++)
    {
        result[i] = buffer[cel-max+i];
    }

    fprintf(output, "%s", result);

    fclose(output);
    return 0; 
} 
