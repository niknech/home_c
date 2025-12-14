#include <stdio.h> 
#include "string.h"

int main() 
{ 
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    int small = 0, large = 0;

    char buffer[10000];
    fgets(buffer, 10000, input);
    fclose(input);
    
    for (int i = 0; i < strlen(buffer); i++)
        if (buffer[i] >= 0x61 && buffer[i] <= 0x7A)
            small++;
        else if (buffer[i] >= 0x41 && buffer[i] <= 0x5A)
            large++;

    fprintf(output, "%d %d", small, large);

    fclose(output);
    return 0; 
} 
