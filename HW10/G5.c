#include <stdio.h> 
#include "string.h"
 
int main() 
{ 
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    char buffer[1000];
    fgets(buffer, 1001, input);
    fclose(input);
    
    for(int i=0; i<strlen(buffer); i++)
    {
        switch (buffer[i])
        {
            case 'A':
                buffer[i] = 'B';
                break;
            case 'a':
                buffer[i] = 'b';
                break;
            case 'B':
                buffer[i] = 'A';
                break;
            case 'b':
                buffer[i] = 'a';
                break;
        }
        fputc(buffer[i], output);
    }
    
    fclose(output);
    return 0; 
} 
