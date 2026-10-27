#ifndef _USART_H
#define _USART_H

#include "stm32f10x.h"
#include "stdio.h"


void Dri_Usart_Init(void);


void Dri_Usart_SendChr(uint8_t chr);

uint8_t Dir_Usart_ReciveChr(void);

void Dri_Usart_SendStr(uint8_t *str);

void  Dir_Usart_ReciveStr(void);

int fputc(int c, FILE *file);


#endif /* _USART_H */

