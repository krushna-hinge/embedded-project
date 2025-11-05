/*
 * KEYPAD.h
 *
 *  Created on: Oct 14, 2025
 *      Author: krushna
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include<stm32f407xx.h>

#define BV(n)	(1 << (n))

#define KEYMATRIX  GPIOA
#define ROW_1   0
#define ROW_2   1
#define ROW_3   2
#define COL_1   3
#define COL_2   4
#define COL_3   5

extern const char KEY_MATRIX[3][3];

void init_keypad(void);
char scan_keypad(void);
void activte_row(uint8_t row);
uint8_t read_col(uint8_t col);




#endif /* KEYPAD_H_ */
