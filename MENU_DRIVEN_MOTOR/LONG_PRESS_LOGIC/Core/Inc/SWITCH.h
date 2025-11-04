/*
 * SWITCH.h
 *
 *  Created on: Oct 15, 2025
 *      Author: krushna
 */

#ifndef INC_SWITCH_H_
#define INC_SWITCH_H_

#define LONG_PRESS_THRESHOLD 1000



#define CENTER_BUTTON GPIO_PIN_0
#define LEFT_BUTTON   GPIO_PIN_1
#define RIGHT_BUTTON  GPIO_PIN_2
#define UP_BUTTON     GPIO_PIN_3
#define DOWN_BUTTON   GPIO_PIN_4


#include <stdbool.h>
#include "stm32f4xx_hal.h"

extern volatile bool BUTTON_PRESS;
extern volatile int press_start_time;


void long_press_handler(void);


#endif /* INC_SWITCH_H_ */
