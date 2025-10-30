/*
 * main.c
 * 
 * Copyright 2025 Nikita <Nikita@NICK-PC>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include "stdint.h"

uint32_t powerOfHex(uint8_t power);
void fromHexToDec(uint32_t* hex);

int main(int argc, char **argv)
{
	uint32_t a = 12345678; //hex
	uint32_t b = 1000000; //hex
	fromHexToDec(&a); //конвертация в dec
	fromHexToDec(&b); //конвертация в dec
	printf("%u\r\n", a);
	printf("%u\r\n", b);
	return 0; 
}

void fromHexToDec(uint32_t* hex)
{
	uint32_t temp_hex = *hex;
	uint32_t dec = 0;
	uint8_t power = 0;
	
	while(temp_hex)
	{
		dec += temp_hex % 10 * powerOfHex(power);
		power++;
		temp_hex /= 10;
	}
	
	*hex = dec;
}

uint32_t powerOfHex(uint8_t power)
{
	uint32_t result = 1;
	
	if (!power)
		return result;
	
	for (uint8_t i = 1; i <= power; i++)
	{
		result *=16;
	}
	return result;
}

