#include <stdio.h> 
#include "inttypes.h"

struct pack_array 
{
    uint32_t array; // поле для хранения упакованного массива из 0 и 1
    uint32_t count0 : 8; // счетчик нулей в array
    uint32_t count1 : 8; // счетчик единиц в array
};

void array2struct(int arr[], struct pack_array* s)
{
    for (int i = 0; i < 32; i++)
    {
        s->array = (s->array << 1) | arr[i];
        
        if (arr[i]) s->count1++;
        else s->count0++;
    }
    return;
}

int main() 
{
    struct pack_array s = {0,0,0};
    int arr[32];
    
    for (int i = 0; i < 32; i++)
        scanf("%d", arr + i);
    
    array2struct(arr, &s);
    printf("%" PRIu32 " %d %d", s.array, s.count0, s.count1);
    
    return 0; 
} 
