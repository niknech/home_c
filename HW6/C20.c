#include <stdio.h>
#include "string.h"


char* checkBrackets(char* s)
{
	int countOpen = 0;
	int countClose = 0;
	
	while ( *s != '.')
	{
		switch(*s)
		{
			case '(':
				countOpen++;
				break;
			case ')':
				countClose++;
		}
		if (countOpen<countClose)
			return "NO";
			
		s++;
	}
	
	if (countOpen == countClose)
		return "YES";
	else
		return "NO";
}

int main()
{
	char s[1500];
	scanf("%s", s);
    printf("%s", checkBrackets(s));
    return 0;
}
