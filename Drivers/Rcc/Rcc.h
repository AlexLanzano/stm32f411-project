#ifndef RCC_H
#define RCC_H

#include <cstdint>

class RccDriver {
public:
    RccDriver(uint32_t baseAddress);
    ~RccDriver() {};

    void EnableGpioaClock();


private:
    uint8_t *m_baseAddress;

	static constexpr uint32_t RCC_AHB1ENR_OFFSET = 0x30;
	static constexpr uint32_t RCC_AHB1ENR_GPIOAEN_BIT = 0x0;
};

#endif
