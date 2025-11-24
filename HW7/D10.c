#include <stdio.h>


int pow2(int pow)
{
	int result = 1;
		
	for (int i = 1; i <= pow; i++)
		result *= 2;
		
	return result;
}


void CountBin(int dec)
{
	static int firstTimeFlag = 1;
	static int count = 0;
	
	if (dec == 0 && firstTimeFlag)
	{
		printf("%d", 0);
		return;
	}
	
	firstTimeFlag = 0;
	
	if(dec != 0)
    {   
		int ostatok = dec % 2;
        count += ostatok;
        CountBin(dec/2);

    }
    else
		printf("%d", count);
		
    return;
    
}

int main(int argc, char **argv)
{
	int N;
	scanf("%d", &N);
	CountBin(N);
	return 0;
}

