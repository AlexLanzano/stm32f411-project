#ifndef STRING_H
#define STRING_H

#include <stdint.h>
#include <stdarg.h>
#include <stdbool.h>

void *memset(void *dest, uint8_t value, uint32_t size);
void *memcpy(void *dest, const void *source, uint32_t size);
void *memcpy_reverse(void *dest, const void *source, uint32_t size);
int memcmp(const void *mem1, const void *mem2, uint32_t size);
void *memmove(void *dest, const void *source, uint32_t size);

void *memset16(void *dest, uint16_t value, uint32_t size);
void *memcpy16(void *dest, const void *source, uint32_t size);
void *memcpy_reverse16(void *dest, const void *source, uint32_t size);
int memcmp16(const void *mem1, const void *mem2, uint32_t size);
void *memmove16(void *dest, const void *source, uint32_t size);

void *memset32(void *dest, uint32_t value, uint32_t size);
void *memcpy32(void *dest, const void *source, uint32_t size);
void *memcpy_reverse32(void *dest, const void *source, uint32_t size);
int memcmp32(const void *mem1, const void *mem2, uint32_t size);
void *memmove32(void *dest, const void *source, uint32_t size);

#endif
