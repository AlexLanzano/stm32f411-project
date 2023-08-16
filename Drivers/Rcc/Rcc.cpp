#include <cstdint>
#include "Libraries/BitOps.h"
#include "Drivers/Rcc/Rcc.h"


RccDriver::RccDriver(uint32_t baseAddress)
{
	m_baseAddress = (uint8_t *)baseAddress;
}

void RccDriver::EnableGpioaClock()
{
    uint32_t *registerAHB1ENR = (uint32_t *)(m_baseAddress + RCC_AHB1ENR_OFFSET);
    BitOps::SetBit(registerAHB1ENR, RCC_AHB1ENR_GPIOAEN_BIT, BitOps::MASK1, 1);
}
