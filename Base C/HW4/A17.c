#include <stdio.h>
#include <stdlib.h>

int main() {
	char *seasons[] = {"spring", "summer", "autumn", "winter"};
    int month;
    scanf("%d", &month);
    printf("%s\n", seasons[((month + 9) % 12) / 3]);
    
    return 0;
}

