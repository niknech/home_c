#include <stdio.h>
#include "math.h"


char* isPrime(int n) 
{
    if (n <= 1) {
        return "NO";
    }

    if (n <= 3) {
        return "YES";
    }

    if (n % 2 == 0 || n % 3 == 0) {
        return "NO";
    }

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return "NO";
        }
    }
    
    return "YES";
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%s", isPrime(n));
    return 0;
}
