#include "key.h"
#include "led.h"
//#include "delay.h"

void Int_key_Init(void)
{
    // 打开apb2上的 AFIO和GPIO使能
    RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
    RCC->APB2ENR |= RCC_APB2ENR_IOPFEN;
    // 设置GPIOF10的工作模式 10(上下拉输入) 00(输入模式)
    GPIOF->CRH &= ~(GPIO_CRH_CNF10 | GPIO_CRH_MODE10);
    GPIOF->CRH |= GPIO_CRH_CNF10_1;
    GPIOF->ODR &= ~GPIO_ODR_ODR10; // 设置为下拉输入

    // 选择exti10的外部中断输入源
    AFIO->EXTICR[2] |= AFIO_EXTICR3_EXTI10_PF;
    // 允许输入线10的上升沿触发中断
    EXTI->RTSR |= EXTI_RTSR_TR10;
    // 开发线10的中断请求
    EXTI->IMR |= EXTI_IMR_MR10;

    // 设置系统中断优先级分组 011 抢占优先级为0-15 没有响应优先级
    NVIC_SetPriorityGrouping(3);
    // 设置中断通道的优先级
    NVIC_SetPriority(EXTI15_10_IRQn, 4);
    // 使能这个中断通道
    NVIC_EnableIRQ(EXTI15_10_IRQn);
}

