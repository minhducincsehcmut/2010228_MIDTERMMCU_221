/*
 * fsm_button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: duchu
 */


#include "fsm_button.h"
int segnum = 9;

void update(int index){
	switch(index){
	case 0:
		segnum++;
		segnum %= 10;
		break;
	case 1:
		segnum--;
		if(segnum <= -1) segnum = 9;
		break;
	case 2:
		segnum = 0;
		break;
	default:
		break;
	}
}

int buttonState[NO_OF_BUTTONS] = {NONE,NONE,NONE};
int countTimerForHoldEventStart = BUTTON_DELAY_HOLD*3/BUTTON_DELAY_TIME;
void fsm_button(){
	for(int i = 0; i < NO_OF_BUTTONS; i++){
		switch(buttonState[i]){
		case NONE:
			if(timer1_flag == 1){
				if(isButtonPressed(i) == 1){
					buttonState[i] = PRESS;
					status = MANUAL;
					setTimer2(AUTO_SET_TIME);
					update(i);
					setTimer1(BUTTON_DELAY_TIME);
				}
			}
			break;
		case PRESS:
			if(timer1_flag == 1){
				if(isButtonPressed(i) == 0){

					countTimerForHoldEventStart = BUTTON_DELAY_HOLD*3/BUTTON_DELAY_TIME;

				}
				else{
					if(countTimerForHoldEventStart <= 0){
						countTimerForHoldEventStart = BUTTON_DELAY_HOLD*3/BUTTON_DELAY_TIME;
						buttonState[i] = HOLD;
						update(i);
						status = MANUAL;
						setTimer2(AUTO_SET_TIME);
						setTimer1(BUTTON_DELAY_HOLD);
					}
					else{
						countTimerForHoldEventStart--;
						setTimer1(BUTTON_DELAY_TIME);
					}
				}
			}
			break;
		case HOLD:
			if(timer1_flag == 1){
				if(isButtonPressed(i) == 0)
					buttonState[i] = NONE;
				else{
					update(i);
					status = MANUAL;
					setTimer2(AUTO_SET_TIME);
					setTimer1(BUTTON_DELAY_HOLD);
				}
			}
			break;

		}
	}
}
