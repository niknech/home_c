#include <stdio.h>
#include <stdint.h>

typedef struct 
{
	float k;
	float b;
	uint8_t is_valid;
} Line_t;

void CalculateLine (int8_t x1, int8_t y1, int8_t x2, int8_t y2, Line_t* line)
{
	//если x1 и x2 равны, то решений у системы нет
	if (!(x1-x2))
	{
		line->is_valid = 0;
		return;
	}
	
	line->is_valid = 1;
	line->k = (float) (y1-y2)/(x1-x2);
	line->b =  y1 - x1 * line->k;
	return;
}

int main(int argc, char **argv)
{
	int8_t x1,y1,x2,y2;
	Line_t line = {0,0,0};
	scanf("%hhd %hhd %hhd %hhd", &x1, &y1, &x2, &y2);
	CalculateLine(x1,y1,x2,y2,&line);
	printf("%.2f %.2f", line.k, line.b);
	return 0;
}

