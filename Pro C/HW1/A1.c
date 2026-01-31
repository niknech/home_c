#include <stdio.h>
#include <inttypes.h>

char CesarCode(char c, uint8_t N)
{
    if (c == ' ')
        return c;

    N %= 26;

    if (c >= 'A' && c <= 'Z')
    {
        return (char)('A' + ((c - 'A' + N) % 26));
    }

    if (c >= 'a' && c <= 'z')
    {
        return (char)('a' + ((c - 'a' + N) % 26));
    }

    return c;
}

int main(void)
{
    char c;
    uint32_t N;

    scanf("%" SCNu32" ", &N);  

    uint8_t shift = N % 26; 

    while ((c = getchar()) != '.')
    {
        putchar(CesarCode(c, shift));
    }

    putchar('.');

    return 0;
}
