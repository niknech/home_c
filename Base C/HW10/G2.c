#include <stdio.h>
#include "string.h"
 
int FromStrToInt(char* str)
{
    int result = 0;
    char* tmp = str;
    while (*tmp)
    {
        result = result * 10 + *tmp - 0x30;
        tmp++;
    }
    return result;
}

int main() { 
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    if (input == NULL || output == NULL)
    {
        perror("Fail to open files");
        return -1;
    }

    char buffer[100];
    int i = 0;
    int n;
    char c;
    char letter_position = 0x41;
    char num_position = 0x32;



    while ((c = getc(input))!= EOF && c != '\n')
    {
        buffer[i++] = c;
    }
    buffer[i] = '\0';

    n = FromStrToInt(buffer);
    
    i = 0;
    for (i = 0; i < n; i++)
    {
         if (i % 2 == 0)
        {
            buffer[i] = letter_position++;
        }
        else
        {
            num_position = num_position > 0x38 ? 0x32 : num_position;
            buffer[i] = num_position;
            num_position += 2;
        }
    }
    buffer[++i] = '\0';

    fprintf(output, "%s", buffer);

    fclose(output);
    fclose(input);
    return 0; 
} 
