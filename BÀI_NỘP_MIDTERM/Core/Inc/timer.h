/*
 * timer.h
 *
 *  Created on: Nov 5, 2022
 *      Author: duchu
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#define TIMECYCLE	1
int timer1_counter;
int timer1_flag;
int timer2_counter;
int timer2_flag;
int timer3_counter;
int timer3_flag;


void timerRun();
void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);

#endif /* INC_TIMER_H_ */
