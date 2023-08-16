#include <cstdint>
#include "Libraries/BitOps.h"

void BitOps::SetBit(uint32_t *dest, uint8_t bit, uint32_t mask, uint32_t value)
{
	*dest = ((~mask << bit) & *dest) | (value << bit);
}

uint32_t BitOps::GetBit(uint32_t *source, uint8_t bit, uint32_t mask)
{
	return (*source & (mask << bit)) >> bit;
}
