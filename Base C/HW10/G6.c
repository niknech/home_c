#include <stdio.h> 
#include "string.h"

int is_palindrom(char* str)
{
    int size = strlen(str);
    //int unparity = size % 2 == 0 ? 0 : 1;
    int result = 1;

    for (int i = 0; i < size/2; i++)
    {
        if (str[i] != str[size - 1 - i])
            {
                result = 0;
                break; 
            }
    }
    return result;

}

int main() 
{ 
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    char buffer[1000];
    fscanf(input, "%s", buffer);
    fclose(input);
    
    int result = is_palindrom(buffer);

    if (result)
        fprintf(output, "%s", "YES");
    else
        fprintf(output, "%s", "NO");

    fclose(output);
    return 0; 
} 
