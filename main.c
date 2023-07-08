#include "drivers/rcc/rcc.h"
#include "drivers/gpio/gpio.h"

void main()
{
    rcc_enable_gpioa_clock();

    gpio_configure_pin(
        (gpio_configuration_t){
            .port = GPIOA,
            .pin = 0,
            .mode = GPIO_MODE_OUTPUT,
            .type = GPIO_TYPE_PUSH_PULL,
            .speed = GPIO_SPEED_MEDIUM,
            .pull = GPIO_PULL_DOWN
        });

    gpio_set_pin(GPIOA, 0, GPIO_PIN_HIGH);
}
