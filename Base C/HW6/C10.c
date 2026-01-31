#include <stdio.h>


int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }

    if (n <= 3) {
        return 1;
    }

    if (n % 2 == 0 || n % 3 == 0) {
        return 0;
    }

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }
    
    return 1;
}


void print_simple(int n)
{
	while(n > 1)
	{
		for (int i = 2; i <= n; i++)
		{
			if (isPrime(i))
			{
				if(n % i == 0)
				{
					printf("%d ", i);
					n /= i;
					break;
				}
			}
		}
	}
}




int main()
{
	int number;
	scanf("%d", &number);
	print_simple(number);
    return 0;
}
