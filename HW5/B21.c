#include <stdio.h>

int main(int argc, char **argv)
{
	char recieved_symbol = '\0';
	
	while ((recieved_symbol = getchar()) != '.')
	{
		if (recieved_symbol >= 0x41 && recieved_symbol <= 0x5A)
			recieved_symbol += 0x20;
		putchar(recieved_symbol);
	}
	
	return 0;
}

