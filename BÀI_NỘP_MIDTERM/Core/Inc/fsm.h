/*
 * fsm_full.c
 *
 *  Created on: Nov 5, 2022
 *      Author: duchu
 */

#ifndef INC_FSM_FULL_C_
#define INC_FSM_FULL_C_
#include "button.h"
#include "fsm_button.h"
#include "timer.h"



#define AUTO_SET_TIME	1000  // thoi gian cho la 10s truoc khi chuyen trang thai
#define AUTO_TIME 100         // 1s cap nhat led 1 lan
#define AUTO 	7
#define MANUAL 	8
int status;

void fsm_simple_buttons_run();


#endif /* INC_FSM_FULL_C_ */
