/*
 * fsm_button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: duchu
 */

#ifndef INC_FSM_BUTTON_H_
#define INC_FSM_BUTTON_H_

#include <fsm.h>
#include "button.h"
#include "timer.h"

#define NONE 	11
#define PRESS 	12
#define HOLD 	13
int segnum;
int buttonState[NO_OF_BUTTONS];

#define BUTTON_DELAY_TIME 5
#define BUTTON_DELAY_HOLD 100
void fsm_button();

#endif /* INC_FSM_BUTTON_H_ */
