#include <stdint.h>
#include <stddef.h>

#include "gpio.h"
#include "init/stm32f411xe.h"
#include "libraries/bitops.h"

static void gpio_set_mode(GPIO_TypeDef *port, uint32_t pin, gpio_mode_t mode)
{
    set_bits(&port->MODER, 0b11, 2 * pin, mode);
}

static void gpio_set_type(GPIO_TypeDef *port, uint32_t pin, gpio_type_t type)
{
    set_bit(&port->OTYPER, pin, type);

}

static void gpio_set_speed(GPIO_TypeDef *port, uint32_t pin, gpio_speed_t speed)
{
    set_bits(&port->OSPEEDR, 0b11, 2 * pin, speed);
}

static void gpio_set_pull(GPIO_TypeDef *port, uint32_t pin, gpio_pull_t pull)
{
    set_bits(&port->PUPDR, 0b11, 2 * pin, pull);
}

void gpio_configure_pin(gpio_configuration_t config)
{
    /* assert(config.port != NULL); */
    /* assert(config.pin < GPIO_PIN_MAX); */

    gpio_set_mode(config.port, config.pin, config.mode);
    gpio_set_type(config.port, config.pin, config.type);
    gpio_set_speed(config.port, config.pin, config.speed);
    gpio_set_pull(config.port, config.pin, config.pull);
}

void gpio_set_pin(GPIO_TypeDef *port, uint32_t pin, gpio_pin_value_t value)
{
    /* assert(port != NULL); */
    /* assert(pin < GPIO_PIN_MAX); */

    set_bit(&port->ODR, pin, value);
}

gpio_pin_value_t gpio_get_pin(GPIO_TypeDef *port, uint32_t pin)
{
    /* assert(port != NULL); */
    /* assert(pin < GPIO_PIN_MAX); */

    return get_bit(&port->IDR, pin);
}
