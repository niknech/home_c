#include <stdio.h>
#include "string.h"


int is_digit(char c)
{
	int result = 0;
   	if (c >= 0x30 && c <= 0x39)
		result = 1;
	return result;
}

int main()
{
	char c;
	int count = 0;
    while ((c=getchar())!='.')
    {
		count += is_digit(c);
	}
    printf("%d", count);
    return 0;
}
