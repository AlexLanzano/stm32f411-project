#include <cstdio>
#include <vector>
#include <cstdint>
#include <cstdlib>
#include <memory>

#include "Boards/Stm32f411.h"
#include "Drivers/Rcc/Rcc.h"
#include "Drivers/Gpio/Gpio.h"

void main()
{
	RccDriver rcc(Stm32f411::RCC_ADDR);
	GpioDriver gpioa(Stm32f411::GPIOA_ADDR);

    rcc.EnableGpioaClock();

    gpioa.Configure(0, GpioMode::OUTPUT);
    gpioa.Set(0, GpioValue::HIGH);
}
