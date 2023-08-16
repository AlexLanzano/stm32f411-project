#include "init/stm32f411xe.h"

void rcc_enable_gpioa_clock()
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
}

void rcc_enable_gpiob_clock()
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
}

 void rcc_enable_gpioc_clock()
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
}

void rcc_enable_gpiod_clock()
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
}

void rcc_enable_gpioe_clock()
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
}

void rcc_enable_gpioh_clock()
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;
}
