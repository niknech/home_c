#include <stdio.h>

int pow2(int pow)
{
	int result = 1;
		
	for (int i = 1; i <= pow; i++)
		result *= 2;
		
	return result;
}


void DecToBin(int dec)
{
	static int firstTimeFlag = 1;
	
	if (dec == 0 && firstTimeFlag)
	{
		printf("%d", 0);
		return;
	}
	
	firstTimeFlag = 0;
	
	if(dec != 0)
    {
        int ostatok = dec % 2;
        DecToBin(dec/2);
        printf("%d", ostatok);
    }
    return;
    
}


int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	DecToBin(n);
	return 0;
}

