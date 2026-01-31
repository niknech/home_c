#include <stdio.h>
#include "math.h"

float sinus(float x)
{

    float pi = 3.14159265f;
    
    x = x * pi / 180;
    
    float result = 0.0f;
    float a = x; 
    int n = 1;
  
    while (fabsf(a) >= 0.001f)
    {
        result += a;  
        a = -a * x * x / ((2*n) * (2*n + 1));
        n++;
    }
    
    return result;
}

int main()
{
    float x;
    scanf("%f", &x);
    printf("%.3f\n", sinus(x));
    return 0;
}
