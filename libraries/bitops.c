#include <stdint.h>
#include "bitops.h"

void set_bits(volatile uint32_t *bits, uint32_t mask, uint32_t bit, uint32_t value)
{
    *bits &= ~(mask << bit);
    *bits |= value << bit;
}

void set_bit(volatile uint32_t *bits, uint32_t bit, uint32_t value)
{
    set_bits(bits, 0b1, bit, value);
}

uint32_t get_bits(volatile uint32_t *bits, uint32_t mask, uint32_t bit)
{
    return (*bits & (mask << bit)) >> bit;
}

uint32_t get_bit(volatile uint32_t *bits, uint32_t bit)
{
    return get_bits(bits, 0b1, bit);
}
