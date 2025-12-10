#include <stdio.h> 

char* CheckChess(char* coordinate)
{
    const char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int index;

    for (int i = 0; i < 8; i++)
        if (*coordinate == letters[i])
        {
            index = i + 1;
            break;
        }

    coordinate[1] -=0x30;

    if ((index+coordinate[1])%2==0)
        return "BLACK";
    else
        return "WHITE";
}

int main() { 
    
    char coordinate[2];

    scanf("%c%c", &coordinate[0], &coordinate[1]);
    printf(CheckChess(coordinate));

    return 0; 
} 
