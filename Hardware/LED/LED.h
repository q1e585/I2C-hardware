#ifndef _LED_H
#define _LED_H

#include<stm32f10x.h>

#define LED1 GPIO_ODR_ODR0
#define LED2 GPIO_ODR_ODR1
#define LED3 GPIO_ODR_ODR8



void LED_Init(void);

void LED_OffAll(void);

void LED_Off(uint32_t i);

void LED_On(uint32_t i);

void LED_Run(void);


void LED_toggle(uint32_t i);

#endif /* _LED_H */

