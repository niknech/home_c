#include <stdio.h> 

int countDigits(int a)
{
    int count = 0;
    while (a)
    {
        a=a/10;
        count++;
    }
    return count;
}

void countLetter()
{
    char b[52];
    char c, prev_c;
    int i = 0;
    prev_c = getchar();
    int count = 1;
    int digits = 0;

    while ((c = getchar())!='.')
    {
        if (c == prev_c)
            count++;
        else
        {
            b[i++] = prev_c;
            
            digits = countDigits(count);
            for (int j = digits - 1; j >= 0; j--)
            {
                b[i+j] = count%10 + 0x30;
                count /=10;
            }
            i += digits; 
            count = 1;
            prev_c = c;
        }
    }

    b[i++] = prev_c;
    digits = countDigits(count);
    for (int j = digits - 1; j >= 0; j--)
    {
        b[i+j] = count%10 + 0x30;
        count /=10;
    }
    i += digits; 


    for (int j = 0; j < i; j++)
        printf("%c", b[j]);
}

int main() { 
    countLetter();
    return 0; 
} 
