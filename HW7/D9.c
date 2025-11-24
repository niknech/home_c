#include <stdio.h>

char* is_prime(int n, int delitel) {
    if (n <= 1) {
        return "NO"; 
    }
    if (delitel * delitel > n) {
        return "YES"; 
    }
    if (n % delitel == 0) {
        return "NO"; 
    }
    return is_prime(n, delitel + 1);
}

int main(int argc, char **argv)
{
	int N;
	scanf("%d", &N);
	printf(is_prime(N, 2));
	return 0;
}

