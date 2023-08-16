#include <stdint.h>
#include <string.h>
#include "stm32f411xe.h"


extern uint32_t _estack[];
extern uint32_t _sidata[];
extern uint32_t _sdata[];
extern uint32_t _edata[];
extern uint32_t _sbss[];
extern uint32_t _ebss[];
extern uint32_t interrupt_vector_table[];

extern void main();

void *memset2(void *dest, uint8_t value, uint32_t size)
{
    uint8_t *d = dest;

    for (uint32_t i = 0; i < size; i++) {
            d[i] = value;
    }

    return dest;
}

void *memcpy2(void *dest, const void *src, uint32_t size)
{
    uint8_t *d = dest;
    const uint8_t *s = src;
    for (uint32_t i = 0; i < size; i++) {
        d[i] = s[i];
    }

    return dest;
}

void __attribute__((naked)) Reset_Handler()
{
    __asm__("ldr r0, =_estack\n\t"
            "mov sp, r0");

    // Copy data section from flash memory to ram
    uint32_t data_section_size = _edata - _sdata;
    memcpy(_sdata, _sidata, data_section_size*4);

    // Zero out bss
    uint32_t bss_section_size = _ebss - _sbss;
    memset(_sbss, 0, bss_section_size*4);

    // Set Interrupt Vector Table Offset
    SCB->VTOR = (uint32_t)interrupt_vector_table;

    main();
    while(1);
}
