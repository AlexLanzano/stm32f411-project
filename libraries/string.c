#include <stdint.h>
#include <stdarg.h>
#include <libraries/string.h>

#define UINT_STRING_MAX 16

char g_char_lut[] = "0123456789abcdef";

void *memset(void *dest, uint8_t value, uint32_t size)
{
    uint8_t *d = dest;

    for (uint32_t i = 0; i < size; i++) {
            d[i] = value;
    }

    return dest;
}

void *memcpy(void *dest, const void *src, uint32_t size)
{
    uint8_t *d = dest;
    const uint8_t *s = src;
    for (uint32_t i = 0; i < size; i++) {
        d[i] = s[i];
    }

    return dest;
}

void *memcpy_reverse(void *dest, const void *src, uint32_t size)
{
    uint8_t *d = dest;
    const uint8_t *s = src;
    uint32_t i, n;
    for (i = 0, n = size-1; i < size; i++, n--) {
        d[i] = s[n];
    }

    return dest;
}

int memcmp(const void *mem1, const void *mem2, uint32_t size)
{
    const uint8_t *m1 = mem1;
    const uint8_t *m2 = mem2;

    for (uint32_t i = 0; i < size;i++) {
        if (m1[i] > m2[i]) {
            return 1;
        }

        if (m1[i] < m2[i]) {
            return -1;
        }
    }
    return 0;
}

void *memmove(void *dest, const void *source, uint32_t size)
{
    uint8_t temp[size];
    memcpy(temp, source, size);
    memcpy(dest, temp, size);

    return dest;
}

void *memset16(void *dest, uint16_t value, uint32_t size)
{
    uint16_t *d = dest;

    for (uint32_t i = 0; i < size; i++) {
            d[i] = value;
    }

    return dest;
}

void *memcpy16(void *dest, const void *src, uint32_t size)
{
    uint16_t *d = dest;
    const uint16_t *s = src;
    for (uint32_t i = 0; i < size; i++) {
        d[i] = s[i];
    }

    return dest;
}

void *memcpy_reverse16(void *dest, const void *src, uint32_t size)
{
    uint16_t *d = dest;
    const uint16_t *s = src;
    uint32_t i, n;
    for (i = 0, n = size-1; i < size; i++, n--) {
        d[i] = s[n];
    }

    return dest;
}

int memcmp16(const void *mem1, const void *mem2, uint32_t size)
{
    const uint16_t *m1 = mem1;
    const uint16_t *m2 = mem2;

    for (uint32_t i = 0; i < size;i++) {
        if (m1[i] > m2[i]) {
            return 1;
        }

        if (m1[i] < m2[i]) {
            return -1;
        }
    }
    return 0;
}

void *memmove16(void *dest, const void *source, uint32_t size)
{
    uint16_t temp[size];
    memcpy16(temp, source, size);
    memcpy16(dest, temp, size);

    return dest;
}

void *memset32(void *dest, uint32_t value, uint32_t size)
{
    uint32_t *d = dest;

    for (uint32_t i = 0; i < size; i++) {
            d[i] = value;
    }

    return dest;
}

void *memcpy32(void *dest, const void *src, uint32_t size)
{
    uint32_t *d = dest;
    const uint32_t *s = src;
    for (uint32_t i = 0; i < size; i++) {
        d[i] = s[i];
    }

    return dest;
}

void *memcpy_reverse32(void *dest, const void *src, uint32_t size)
{
    uint32_t *d = dest;
    const uint32_t *s = src;
    uint32_t i, n;
    for (i = 0, n = size-1; i < size; i++, n--) {
        d[i] = s[n];
    }

    return dest;
}

int memcmp32(const void *mem1, const void *mem2, uint32_t size)
{
    const uint32_t *m1 = mem1;
    const uint32_t *m2 = mem2;

    for (uint32_t i = 0; i < size;i++) {
        if (m1[i] > m2[i]) {
            return 1;
        }

        if (m1[i] < m2[i]) {
            return -1;
        }
    }
    return 0;
}

void *memmove32(void *dest, const void *source, uint32_t size)
{
    uint32_t temp[size];
    memcpy32(temp, source, size);
    memcpy32(dest, temp, size);

    return dest;
}
