#include <stdio.h>
#include "string.h"


int digit_to_num(char c)
{
	int result = 0;
   	if (c >= 0x30 && c <= 0x39)
		result = c - 0x30;
	return result;
}

int main()
{
	char c;
	int sum = 0;
    while ((c=getchar())!='.')
    {
		sum += digit_to_num(c);
	}
    printf("%d", sum);
    return 0;
}
