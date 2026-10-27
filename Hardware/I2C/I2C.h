#ifndef _I2C_H
#define _I2C_H

#include "stm32f10x.h"
#include "delay.h"

void Dri_I2C_Init(void);
uint8_t Dri_I2C_Start(void);
void Dri_I2C_Stop(void);
uint8_t Dri_I2C_SendByte(uint8_t byte);
uint8_t Dri_I2C_ReciveByte(void);
uint8_t Dri_I2C_SendAddress(uint8_t address);

void Dri_I2C_Ack(void);
void Dri_I2C_NAck(void);

#endif /* _I2C_H */
