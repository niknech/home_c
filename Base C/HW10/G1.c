#include <stdio.h> 
#include "string.h"
#define SIZE 1000
 
int main() { 
    
    char str[SIZE];
    int count=0;
    char c;

    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    while ((c=getc(input))!= EOF && c != '\n')
    {
        str[count++] = c;
    }
    str[count] = '\0';

    for (int i = 0; i < 3; i++)
    {
        if (i)
            fprintf(output, ", ");
        fprintf(output, str, "%s");
    }
    fprintf(output, " %d", count);

    fclose(input);
    fclose(output);

    return 0; 
}