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

void PrintPrimeDel(int n)
{
	static int del = 2;
	
	if (n==1) return;
	
	if (n % del == 0 && isPrime(del) == 1)
	{
		printf("%d ", del);
		n /= del;
		if (n == 1) return;
		PrintPrimeDel(n);
	}
	else
	{
		del++;
		PrintPrimeDel(n);
	}
	return;
}

int main(int argc, char **argv)
{
	int N;
	scanf("%d", &N);
	PrintPrimeDel(N);
	return 0;
}

