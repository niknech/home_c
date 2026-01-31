#include <stdio.h>
#include "math.h"

float cosinus(float x)
{

    float pi = 3.14159265f;
    
    x = x * pi / 180;
    
    float result = 0.0f;
    float a = 1; 
    int n = 1;
  
    while (fabsf(a) >= 0.001f)
    {
        result += a;
        if (n == 1)
			a = -a * x * x / 2;
		else
			a = -a * x * x / (n*(n+1));
        n=n+2;
    }
    
    return result;
}

int main()
{
    float x;
    scanf("%f", &x);
    printf("%.3f\n", cosinus(x));
    return 0;
}
