#include "Libraries/BitOps.h"
#include "Drivers/Gpio/Gpio.h"
#include <cstdint>

GpioDriver::GpioDriver(uint32_t baseAddress)
{
	m_baseAddress = (uint8_t *)baseAddress;
}
GpioDriver::~GpioDriver()
{

}

int GpioDriver::Configure(uint8_t pin, GpioMode mode)
{
	SetMode(pin, mode);
	SetOutputType(pin, GpioOutputType::PUSH_PULL);
	SetOutputSpeed(pin, GpioOutputSpeed::MEDIUM);
	SetPullResistor(pin, GpioPullResistor::PULL_UP);
	return 0;
}

int GpioDriver::Set(uint8_t pin, GpioValue value)
{
	uint32_t *registerODR = (uint32_t *)(m_baseAddress + GPIO_ODR_OFFSET);
	BitOps::SetBit(registerODR, pin, BitOps::MASK1, (uint32_t)value);
	return 0;
}

GpioValue GpioDriver::Get(uint32_t pin)
{
	uint32_t *registerIDR = (uint32_t *)(m_baseAddress + GPIO_IDR_OFFSET);
	return (GpioValue)BitOps::GetBit(registerIDR, pin, BitOps::MASK1);
}

int GpioDriver::SetMode(uint8_t pin, GpioMode mode)
{
	uint32_t *registerMODER = (uint32_t *)(m_baseAddress + GPIO_MODER_OFFSET);
	BitOps::SetBit(registerMODER, pin<<1, BitOps::MASK2, (uint8_t)mode);
	return 0;
}

int GpioDriver::SetOutputType(uint8_t pin, GpioOutputType outputType)
{
	uint32_t *registerOTYPER = (uint32_t *)(m_baseAddress + GPIO_OTYPER_OFFSET);
	BitOps::SetBit(registerOTYPER, pin, BitOps::MASK1, (uint8_t)outputType);
	return 0;
}

int GpioDriver::SetOutputSpeed(uint8_t pin, GpioOutputSpeed outputSpeed)
{
	uint32_t *registerOSPEEDR = (uint32_t *)(m_baseAddress + GPIO_OSPEEDR_OFFSET);
	BitOps::SetBit(registerOSPEEDR, pin<<1, BitOps::MASK2, (uint8_t)outputSpeed);
	return 0;
}

int GpioDriver::SetPullResistor(uint8_t pin, GpioPullResistor pullResistor)
{
	uint32_t *registerPUPDR = (uint32_t *)(m_baseAddress + GPIO_PUPDR_OFFSET);
	BitOps::SetBit(registerPUPDR, pin<<1, BitOps::MASK2, (uint8_t)pullResistor);
	return 0;
}
