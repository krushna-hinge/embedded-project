/*
 * switch.c
 *
 *  Created on: Oct 15, 2025
 *      Author: krushna
 */
#include "SWITCH.h"

volatile bool BUTTON_PRESS = false;
volatile int press_start_time = 0;

void long_press_handler(void)
{
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
}
