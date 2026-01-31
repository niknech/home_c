#include <stdio.h> 
#include "inttypes.h"

int extractExp(float value)
{
    union float_union
    {
        float value;
        uint32_t u_value;
    };
    
    union float_union f;
    f.value = value;
    
    return (f.u_value>>23) & 0xFF;
}

int main() 
{
    float value;
    scanf("%f", &value);

    printf("%d", extractExp(value));
    
    return 0; 
} 
