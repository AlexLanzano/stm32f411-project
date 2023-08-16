#ifndef BIT_OPS_H
#define BIT_OPS_H

#include <cstdint>

namespace BitOps {
	static constexpr uint32_t MASK1 = 0x1;
	static constexpr uint32_t MASK2 = 0x3;
	static constexpr uint32_t MASK3 = 0x7;
	static constexpr uint32_t MASK4 = 0xf;
	static constexpr uint32_t MASK5 = 0x1f;
	static constexpr uint32_t MASK6 = 0x3f;
	static constexpr uint32_t MASK7 = 0x7f;
	static constexpr uint32_t MASK8 = 0xff;
	static constexpr uint32_t MASK9 = 0x1ff;
	static constexpr uint32_t MASK10 = 0x3ff;
	static constexpr uint32_t MASK11 = 0x7ff;
	static constexpr uint32_t MASK12 = 0xfff;
	static constexpr uint32_t MASK13 = 0x1fff;
	static constexpr uint32_t MASK14 = 0x3fff;
	static constexpr uint32_t MASK15 = 0x7fff;
	static constexpr uint32_t MASK16 = 0xffff;
	static constexpr uint32_t MASK17 = 0x1ffff;
	static constexpr uint32_t MASK18 = 0x3ffff;
	static constexpr uint32_t MASK19 = 0x7ffff;
	static constexpr uint32_t MASK20 = 0xfffff;
	static constexpr uint32_t MASK21 = 0x1fffff;
	static constexpr uint32_t MASK22 = 0x3fffff;
	static constexpr uint32_t MASK23 = 0x7fffff;
	static constexpr uint32_t MASK24 = 0xffffff;
	static constexpr uint32_t MASK25 = 0x1ffffff;
	static constexpr uint32_t MASK26 = 0x3ffffff;
	static constexpr uint32_t MASK27 = 0x7ffffff;
	static constexpr uint32_t MASK28 = 0xfffffff;
	static constexpr uint32_t MASK29 = 0x1fffffff;
	static constexpr uint32_t MASK30 = 0x3fffffff;
	static constexpr uint32_t MASK31 = 0x7fffffff;
	static constexpr uint32_t MASK32 = 0xffffffff;

	void SetBit(uint32_t *dest, uint8_t bit, uint32_t mask, uint32_t value);
	uint32_t GetBit(uint32_t *source, uint8_t bit, uint32_t mask);
}

#endif
