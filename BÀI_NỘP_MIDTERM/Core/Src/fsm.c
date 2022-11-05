/*
 * fsm_full.c
 *
 *  Created on: Nov 5, 2022
 *      Author: duchu
 */


#include <fsm.h>
int status = AUTO;
void fsm_simple_buttons_run(){
	for(int i = 0; i < NO_OF_BUTTONS; i++){
		switch(status){
		case AUTO:
			if(timer2_flag == 1){
				segnum--;
				if(segnum <= 0) segnum = 0;
				setTimer2(AUTO_TIME);
			}
			break;
		case MANUAL:
			if(timer2_flag == 1){
				status = AUTO;
				setTimer2(AUTO_TIME);
			}
			break;
		default:
			break;
		}
	}
}

