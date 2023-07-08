# stm32f411-project

A repository containing drivers and application code for the stm32f411
MCU

## Directory Structure
`compiler/` - Contains scripts to build the cross compiler

`drivers/` - Contains code to interface directly with hardware and peripherals

`init/` - Contains the start-up code to configure and bringup the stm32f411 MCU

`libraries/` - Contains utility code that can be used throughout the project

## Build dependencies
- dfu-util
- make
- gcc

## How to build

First clone in the repository and it's submodules by doing this
command

`git clone https://github.com/AlexLanzano/stm32f411-project.git --recurse-submodules`

next you need to build the cross-compiler so you can build binaries
for the stm32f411 board

`make build-toolchain`

Now your're ready to build the actual binary by doing the following command

`make`

## How to flash to the board

1. To flash to the board you need to connect to the MCU via USB.

2. Power on the board with pins BOOT0 high and BOOT1 low to boot into
system memory. On the Adafruit black pill board you can hold down the
BOOT0 button while press and releasing the reset button


Now you can run the following command to flash the image to the board
`make flash`
