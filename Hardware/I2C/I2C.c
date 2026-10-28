#include "I2C.h"

void Dri_I2C_Init(void)
{
    RCC->APB1ENR |= RCC_APB1ENR_I2C2EN;//i2c2在apb1总线上 36Mhz
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN ; // PB


    // pb10 开漏 输出 cnf11   mode11
    // Pb11 开漏 输出 cnf11  mode 11

    GPIOB->CRH |= (GPIO_CRH_MODE10 | GPIO_CRH_MODE11);
    GPIOB->CRH |= (GPIO_CRH_CNF10 | GPIO_CRH_CNF11);

    I2C2->CR1 &= ~I2C_CR1_SMBUS; // 0 i2c模式
    //0010 0100
    I2C2->CR2 = 0x24; // 挂载在APB1上,36Mhz

    I2C2->CCR &= ~I2C_CCR_FS; // 标准模式 100Khz
    // Thigh = CCR ×TPCLK1
    //  1/0.1/2 = ccr 1/36
    // 5=ccr/36
    I2C2->CCR = 180;
    //1000/(1/36)
    I2C2->TRISE=37;

    I2C2->CR1 |= I2C_CR1_PE; // i2c 使能
}

uint8_t Dri_I2C_Start(void)
{
    uint16_t timeout = UINT16_MAX;
    I2C2->CR1 |= I2C_CR1_START;
    while ((!(I2C2->SR1 & I2C_SR1_SB)) && (timeout--))
        ;
    if (timeout)
    {
        return 1;
    }
    return 0;
}

void Dri_I2C_Stop(void)
{
    I2C2->CR1 |= I2C_CR1_STOP;
}

uint8_t Dri_I2C_SendByte(uint8_t byte)
{
    uint16_t timeout = UINT16_MAX;
    while (!(I2C2->SR1 & I2C_SR1_TXE) && timeout--)
        ;
    I2C2->DR = byte;

    timeout = UINT16_MAX;
    while (!(I2C2->SR1 & I2C_SR1_BTF) && timeout--)
        ;
    if (timeout)
    {
        // I2C2->DR;
        return 1;
    }
    return 0;
}

uint8_t Dri_I2C_ReciveByte(void)
{
    uint8_t byte = 0;
    uint16_t timeout = UINT16_MAX;
    while (!(I2C2->SR1 & I2C_SR1_RXNE) && timeout--)
        ; 
    if (timeout)
    {
        //  Dri_Usart_SendChr();
        return I2C2->DR;       
    }
    return 0;
}

uint8_t Dri_I2C_SendAddress(uint8_t address){
     uint16_t timeout = UINT16_MAX;
     I2C2->DR=address;
     while (timeout--&& !(I2C2->SR1&I2C_SR1_ADDR));
    if(timeout){
        I2C2->SR2;
        return 1;
    }
    return 0;    
}

void Dri_I2C_Ack(void)
{
    I2C2->CR1 |= I2C_CR1_ACK;
}
void Dri_I2C_NAck(void)
{
    I2C2->CR1 &= ~I2C_CR1_ACK;
}

