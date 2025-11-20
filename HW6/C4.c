#include <stdio.h>

int f(int x)
{
    if (x >= -2 && x < 2)
        return x * x;
    else if (x >= 2)
        return x * x + 4 * x + 5;
    else
        return 4;
}

int main()
{
    int x;
    int max = 0;
    
    while (scanf("%d", &x) == 1 && x != 0)
    {
        int y = f(x);
        if (y > max)
            max = y;
    }
    
    printf("%d\n", max);
    return 0;
}
