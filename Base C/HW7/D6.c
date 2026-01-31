#include <stdio.h>

void reverse_string()
{
	char input;
	
	if ((input = getchar()) != '.')
	{
		reverse_string();
		printf("%c", input);
	}
    return;
}


int main(int argc, char **argv)
{
	reverse_string();
	return 0;
}

