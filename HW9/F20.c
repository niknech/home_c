#include <stdio.h> 
#define SIZE 10

typedef enum
{
    EVEN,
    ODD
} Parity_t;

int MultDigits(int n, Parity_t parity)
{
    int result = 1;

    while(n)
    {
        int digit = n%10;

        switch(parity)
        {
            case EVEN:
                if (digit % 2 == 0)
                    result *= digit;
                break;
            case ODD:
                if (digit % 2 != 0)
                    result *= digit;
                break;               
        }
        n/=10;
    }
    return result;
}

void ChangeArr(int arr[])
{
    int countEven = 0;
    int countOdd = 0;

    for (int i = 0; i < SIZE; i++)
        if (arr[i]%2==0)
            countEven++;
        else
            countOdd++;

    if (countEven > countOdd)
    {
        for (int i = 0; i < SIZE; i++)
            if (arr[i] % 2 != 0)
                arr[i] = MultDigits(arr[i], ODD);
    }
    else
    {
        for (int i = 0; i < SIZE; i++)
            if (arr[i] % 2 == 0)
                arr[i] = MultDigits(arr[i], EVEN);        
    }

}

int main() { 
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++)
        scanf("%d", &arr[i]);

    ChangeArr(arr);

    for (int i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);

    return 0; 
} 
