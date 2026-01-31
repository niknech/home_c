#include <stdio.h> 
#include "string.h"

#define SIZE 1001

int checkResultArr(char* result, int k, char c)
{
    for (int i = 0; i < k; i++)
    {
        if (result[i] == c)
            return 1;
    }
    return 0;
}

int main() 
{
    int k = 0;

    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    char buffer[SIZE];
    char result[SIZE];

    fgets(buffer, SIZE, input);
    fclose(input);
    
    int size = strlen(buffer);

    for (int i=0; i<size; i++)
    {
        if (buffer[i] == ' ')
            continue;

        if (!checkResultArr(result, k, buffer[i]))
            result[k++] = buffer[i];
        
    }

    fprintf(output, "%s", result);

    fclose(output);
    return 0; 
} 
