/*
 * button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: duchu
 */


#include "button.h"
static GPIO_PinState Reg3[NO_OF_BUTTONS];

static GPIO_PinState Reg0[NO_OF_BUTTONS];
static GPIO_PinState Reg1[NO_OF_BUTTONS];
static GPIO_PinState Reg2[NO_OF_BUTTONS];

static uint8_t buttonPressed_flag[NO_OF_BUTTONS] = {0,0,0};
uint16_t INPUT_BUTTON[NO_OF_BUTTONS] = {BUTTON1_Pin, BUTTON2_Pin, BUTTON3_Pin};

void button_reading(void){
	for(int i = 0; i < NO_OF_BUTTONS; i++){
		Reg2[i] = Reg1[i];
		Reg1[i] = Reg0[i];
		Reg0[i] = HAL_GPIO_ReadPin(BUTTON_PORT, INPUT_BUTTON[i]);
		if(Reg1[i] == Reg2[i]){
			Reg3[i] = Reg2[i];
			if(Reg3[i] == BUTTON_PRESSED){
				buttonPressed_flag[i]  = 1;
			}
			else{
				buttonPressed_flag[i] = 0;
			}
		}
	}
}
int isButtonPressed(int buttonNumber){
	if(buttonPressed_flag[buttonNumber] == 1){
		buttonPressed_flag[buttonNumber] = 0;
		return 1;
	}
	return 0;
}
