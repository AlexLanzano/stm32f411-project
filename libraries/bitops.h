#ifndef BITOPS_H
#define BITOPS_H

#include <stdint.h>

void set_bits(volatile uint32_t *bits, uint32_t mask, uint32_t bit, uint32_t value);
void set_bit(volatile uint32_t *bits, uint32_t bit, uint32_t value);

uint32_t get_bits(volatile uint32_t *bits, uint32_t mask, uint32_t bit);
uint32_t get_bit(volatile uint32_t *bits, uint32_t bit);

#endif
