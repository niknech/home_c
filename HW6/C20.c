#include <stdio.h>
#include "string.h"


char* checkBrackets(char* s)
{
	char bracketOpen = '(';
	char bracketClose = ')';
	int len = strlen(s);
	
	for (int i = 0; i <= len-2; i++)
	{
		if (s[i] == bracketOpen)
		{
			if ( s[i+1] == bracketClose)
				i++;
			else if (s[len-2-i] != bracketClose)
				return "NO";
		}
		else
		{
			if (i==0)
				return "NO";
			
			else if (s[len-2-i] != bracketOpen)
				return "NO";
			
		}
	}
	
	return "YES";
}

int main()
{
	char s[100];
	scanf("%s", s);
    printf("%s", checkBrackets(s));
    return 0;
}
