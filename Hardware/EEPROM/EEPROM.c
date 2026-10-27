#include "EEPROM.h"

#define DEV 0xA0

void Int_Eeprom_Init()
{
    Dri_I2C_Init();
}

void Int_Eeprom_Writebyte(uint8_t byte[], uint8_t address, uint8_t len)
{
    uint8_t i = 0;
    Dri_I2C_Start();
    Dri_I2C_SendAddress(DEV);
    Dri_I2C_SendByte(address);
    for (i = 0; i < len; i++)
    {
        Dri_I2C_SendByte(byte[i]);
    }
    Dri_I2C_Stop();
    Delay_ms(5);
}

void Int_Eeprom_Readebyte(uint8_t byte[], uint8_t address, uint8_t len)
{
    uint8_t i = 0;

    Dri_I2C_Start();
    Dri_I2C_SendAddress(DEV);
    Dri_I2C_SendByte(address);
    Dri_I2C_Start();
    Dri_I2C_SendAddress(DEV + 1);
    for (i = 0; i < len; i++)
    {
        if (i == len - 1)
        {
            Dri_I2C_NAck();
            Dri_I2C_Stop();//发送完当前字节在发送停止信号
        }
        else
        {
            Dri_I2C_Ack();
        }
        byte[i] = Dri_I2C_ReciveByte();
    }
}
