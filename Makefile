TOOLCHAIN_PATH = compiler/arm-none-eabi/bin/arm-none-eabi-

GCC = $(TOOLCHAIN_PATH)gcc
LD = $(TOOLCHAIN_PATH)ld
OBJCOPY = $(TOOLCHAIN_PATH)objcopy

INCLUDE = -I.
CFLAGS = -Wall -Werror -c -ffreestanding -nostdlib -mcpu=cortex-m4 $(INCLUDE) -g \
         -MMD -MF $(DEPDIR)/$*.d
LDFLAGS ?= --omagic -static

DEPDIR = .deps/

SOURCE = $(wildcard *.c) \
         $(wildcard init/*.c) \
         $(wildcard drivers/*/*.c) \
         $(wildcard libraries/*.c)

OBJECTS = $(patsubst %.c,%.o,$(SOURCE))

DEPENDS = $(patsubst %.c,$(DEPDIR)/%.d,$(SOURCE))

all: boot.bin

%.d:
	@mkdir -p $(@D)

%.o: %.c Makefile
	$(GCC) $(CFLAGS) -o $@ $<

boot.elf: $(OBJECTS) linker.ld
	$(LD) $(LDFLAGS) -T linker.ld -o $@ $(OBJECTS)

%.bin: %.elf
	$(OBJCOPY) $^ -O binary $@

.PHONY: build-toolchain
build-toolchain:
	cd compiler; \
	make CONFIG=configs/arm-none-eabi.mk

.PHONY: clean
clean:
	rm -rf $(DEPDIR) $(OBJECTS) *.bin *.elf

.PHONY: flash
flash:
	dfu-util -a 0 -i 0 -s 0x08000000:leave -D boot.bin

include $(DEPENDS)
