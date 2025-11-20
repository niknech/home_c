#include <stdio.h>
#include "string.h"
#include "stdlib.h"


char* FromLowToHigh()
{
	char ch;
	int size = 1;
	char *str = malloc(size);
	int len = 0;
	
	while ((ch = getchar()) != '.')
	{
		if (ch >= 0x61 && ch <= 0x7A)
			str[len++] = ch - 0x20;
		else
			str[len++] = ch;
		
		if (len==size)
		{
			size++;
			str = realloc(str, size);
		}
	}
	str[len] = '\0';
	
	return str;
}




int main()
{
	printf("%s", FromLowToHigh());
    return 0;
}
