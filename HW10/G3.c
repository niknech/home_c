#include <stdio.h> 
 
int main() { 
    char buffer[1000];

    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    fseek(input, 0, SEEK_END);
    int size = ftell(input);
    fseek(input,0,SEEK_SET);

    fgets(buffer, size, input);

    char cell = buffer[size-2];

    for (int i = 0; i < size-2; i++)
    {
        if (buffer[i] == cell)
        {
            if(i)
                fputc(' ', output);
            fprintf(output, "%d", i);    
        }
    }

    fclose(input);
    fclose(output);
    return 0; 
} 
