#include "LED.h"

uint32_t leds[3] = {
    LED1, LED2, LED3};

void LED_OffAll()
{
    GPIOA->ODR |= (LED1 | LED2 | LED3);
   
}
void LED_Init()
{
    // 1.打开rcc apb2enr pa使能
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

    // 设置工作模式
    GPIOA->CRL &= ~(GPIO_CRL_CNF0 | GPIO_CRL_CNF1 | GPIO_CRL_MODE0 | GPIO_CRL_CNF1);
    GPIOA->CRH &= ~(GPIO_CRH_CNF8 | GPIO_CRH_MODE8);
    // cnf 00 推挽   mode 11; 高速
    GPIOA->CRL |= (GPIO_CRL_MODE0 | GPIO_CRL_MODE1);
    GPIOA->CRH |= GPIO_CRH_MODE8;
    LED_OffAll();
}

void LED_Off(uint32_t i)
{
    GPIOA->ODR |= leds[i];
}

void LED_On(uint32_t i)
{
    GPIOA->ODR &= ~leds[i];
}
void delay(){
    for(uint32_t i=0;i<=100000;i++){
        for(uint8_t j=0;j<100;j++){

        }
    }
}
void LED_Run()
{
    uint32_t i = 0;
    while (1)
    {
        LED_On(i);
        delay();
        LED_Off(i);
        i++;
        if(i>2)i=0;
    }
}

void LED_toggle(uint32_t i){
    GPIOA->ODR ^= leds[i];
}




