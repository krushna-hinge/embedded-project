/*
 * keypad.c
 *
 *  Created on: Oct 14, 2025
 *      Author: krushna
 */

#include "KEYPAD.h"

const char KEY_MATRIX[3][3]={
		{'1','2','3'},
		{'4','5','6'},
		{'7','8','9'}
};

void init_keypad(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	KEYMATRIX -> MODER &= ~(BV(COL_1 * 2 +1) | BV(COL_1 * 2) | BV(COL_2 * 2 + 1)| BV(COL_2 * 2) |BV(COL_3 * 2)| BV(COL_3 * 2 +1));
	KEYMATRIX -> MODER |= BV(ROW_1 * 2) | BV(ROW_2 * 2) | BV(ROW_3 * 2);
	KEYMATRIX -> MODER &= ~(BV(ROW_1 * 2 + 1 ) | BV(ROW_2 * 2 + 1 ) | BV(ROW_3 * 2 +1));

	KEYMATRIX -> OSPEEDR |= BV(ROW_1 * 2) | BV(ROW_2 * 2) | BV(ROW_3 * 2);
	KEYMATRIX -> OSPEEDR &= ~(BV(ROW_1 * 2 + 1 ) | BV(ROW_2 * 2 + 1 ) | BV(ROW_3 * 2 +1));

	KEYMATRIX -> OSPEEDR |= BV(COL_1 * 2) | BV(COL_2 * 2) | BV(COL_3 * 2);
	KEYMATRIX -> OSPEEDR &= ~(BV(COL_1 * 2 + 1 ) | BV(COL_2 * 2 + 1 ) | BV(COL_3 * 2 +1));

	KEYMATRIX -> PUPDR |=  BV(COL_1 * 2 + 1) | BV(COL_2 * 2 + 1)| BV(COL_3 * 2 + 1);
	KEYMATRIX -> PUPDR &= ~(BV(COL_1 * 2 ) | BV(COL_2 * 2 )| BV(COL_3 * 2 ));


}

char scan_keypad(void)
{
	for(uint8_t row = 0; row < 3 ;row++)
	{
		activte_row(row);
		for(uint8_t col = 0; col < 3;col++)
		{
			if(read_col(col))
					{
						return KEY_MATRIX[row][col];
					}
		}


	}
	return 0;
}

void activte_row(uint8_t row)
{
	KEYMATRIX -> ODR &= ~(BV(ROW_1) | BV(ROW_2)| BV(ROW_3));

	KEYMATRIX -> ODR |= BV(row);
}

uint8_t read_col(uint8_t col)
{
	uint8_t pin = col + 3;
	return (KEYMATRIX -> IDR & (1 << pin)) ? 1 : 0;
}



