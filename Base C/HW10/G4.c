#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    
    if (input == NULL || output == NULL) {
        perror("Error opening file");
        return 1;
    }
    
    char word1[101], word2[101];
    fscanf(input, "%100s %100s", word1, word2);
    fclose(input);
    
    int freq1[26] = {0};
    int freq2[26] = {0};
    
    for (int i = 0; word1[i] != '\0'; i++) {
        freq1[word1[i] - 'a']++;
    }
    
    for (int i = 0; word2[i] != '\0'; i++) {
        freq2[word2[i] - 'a']++;
    }
    
    char result[27];
    int count = 0;
    
    for (int i = 0; i < 26; i++) {
        if (freq1[i] == 1 && freq2[i] == 1) {
            result[count++] = 'a' + i;
        }
    }
    result[count] = '\0';
    
    for (int i = 0; i < count; i++) {
        if (i > 0) fprintf(output, " ");
        fprintf(output, "%c", result[i]);
    }
    
    fclose(output);
    return 0;
}
