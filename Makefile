TOOLCHAIN_PATH = compiler/arm-none-eabi/bin/arm-none-eabi-

GCC = $(TOOLCHAIN_PATH)gcc
GPP = $(TOOLCHAIN_PATH)g++
LD = $(TOOLCHAIN_PATH)ld
OBJCOPY = $(TOOLCHAIN_PATH)objcopy

INCLUDE = -I.
CFLAGS = -Wall -Werror -c -ffreestanding -mthumb -mcpu=cortex-m4 $(INCLUDE) -g \
         -MMD -MF $(DEPDIR)/$*.d
CPPFLAGS = -fno-exceptions -fno-unwind-tables
LDFLAGS ?= --omagic -static

DEPDIR = .deps/

C_SOURCE = $(wildcard Init/*.c)

CPP_SOURCE = $(wildcard *.cpp) \
             $(wildcard Init/*.cpp) \
             $(wildcard Drivers/*/*.cpp) \
             $(wildcard Libraries/*.cpp)

OBJECTS = $(patsubst %.c,%.c.o,$(C_SOURCE)) \
          $(patsubst %.cpp,%.cpp.o,$(CPP_SOURCE))

DEPENDS = $(patsubst %.c,$(DEPDIR)/%.d,$(C_SOURCE)) \
          $(patsubst %.cpp,$(DEPDIR)/%.d,$(CPP_SOURCE))

all: boot.bin

%.d:
	@mkdir -p $(@D)

%.c.o: %.c Makefile
	$(GCC) $(CFLAGS) -o $@ $<

%.cpp.o: %.cpp Makefile
	$(GPP) $(CPPFLAGS) $(CFLAGS) -o $@ $<

boot.elf: $(OBJECTS) linker.ld
	$(GPP) -Wl,-N -Wl,-T,linker.ld -mthumb -o $@ $(OBJECTS) -static-libgcc

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
