#ifndef GPIO_H
#define GPIO_H

#include <cstdint>

static constexpr uint32_t GPIO_MODER_OFFSET = 0x00;
static constexpr uint32_t GPIO_OTYPER_OFFSET = 0x04;
static constexpr uint32_t GPIO_OSPEEDR_OFFSET = 0x08;
static constexpr uint32_t GPIO_PUPDR_OFFSET = 0x0C;
static constexpr uint32_t GPIO_IDR_OFFSET = 0x10;
static constexpr uint32_t GPIO_ODR_OFFSET = 0x14;

enum class GpioMode : uint8_t {
	INPUT,
	OUTPUT,
	ALTERNATIVE,
	ANALOG
};

enum class GpioValue : uint32_t {
	LOW,
	HIGH
};

enum class GpioOutputType : uint8_t {
	PUSH_PULL,
	OPEN_DRAIN
};

enum class GpioOutputSpeed : uint8_t {
	LOW,
	MEDIUM,
	FAST,
	HIGH
};

enum class GpioPullResistor : uint8_t {
	NONE,
	PULL_UP,
	PULL_DOWN,
	RESERVED
};

class GpioDriver {
public:
	GpioDriver(uint32_t baseAddress);
	~GpioDriver();

	int Configure(uint8_t pin, GpioMode mode);
	int Set(uint8_t pin, GpioValue value);
	GpioValue Get(uint32_t pint);
	int SetMode(uint8_t pin, GpioMode mode);
	int SetOutputType(uint8_t pin, GpioOutputType outputType);
	int SetOutputSpeed(uint8_t pin, GpioOutputSpeed outputSpeed);
	int SetPullResistor(uint8_t pin, GpioPullResistor pullResistor);

private:
	uint8_t *m_baseAddress;
};

#endif
