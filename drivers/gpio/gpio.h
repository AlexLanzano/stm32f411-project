#include <stdint.h>

#include "init/stm32f411xe.h"

#define GPIO_PIN_MAX 15

typedef enum gpio_mode {
    GPIO_MODE_INPUT,
    GPIO_MODE_OUTPUT,
    GPIO_MODE_ALTERNATE_FUNCTION,
    GPIO_MODE_ANALOG
} gpio_mode_t;

typedef enum gpio_type {
    GPIO_TYPE_PUSH_PULL,
    GPIO_TYPE_OPEN_DRAIN
} gpio_type_t;

typedef enum gpio_speed {
    GPIO_SPEED_LOW,
    GPIO_SPEED_MEDIUM,
    GPIO_SPEED_FAST,
    GPIO_SPEED_HIGH,
} gpio_speed_t;

typedef enum gpio_pull {
    GPIO_PULL_NONE,
    GPIO_PULL_UP,
    GPIO_PULL_DOWN,
} gpio_pull_t;

typedef enum gpio_pin_value {
    GPIO_PIN_LOW,
    GPIO_PIN_HIGH
} gpio_pin_value_t;

typedef struct gpio_configuration {
    GPIO_TypeDef *port;
    uint32_t pin;
    gpio_mode_t mode;
    gpio_type_t type;
    gpio_speed_t speed;
    gpio_pull_t pull;
} gpio_configuration_t;

void gpio_configure_pin(gpio_configuration_t config);
void gpio_set_pin(GPIO_TypeDef *port, uint32_t pin, gpio_pin_value_t value);
gpio_pin_value_t gpio_get_pin(GPIO_TypeDef *port, uint32_t pin);
