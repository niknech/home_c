#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{	
	int recieved, recieved_prev;
	char* answer = "YES";
	scanf("%d", &recieved_prev);
	
	for (int i=0; i<2; i++)
	{
		scanf("%d", &recieved);
		if (recieved <= recieved_prev)
			answer = "NO";
		recieved_prev = recieved;
	}
	
	printf(answer);
	return 0;
}

