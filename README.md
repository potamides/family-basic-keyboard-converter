# Nintendo Family BASIC Keyboard (HVC-007) USB Converter
This project contains instructions and code on how to build a USB converter for
the [Nintendo Family BASIC
Keyboard](https://www.nesdev.org/wiki/Family_BASIC_Keyboard). It makes use of
the [tmk_core](https://github.com/tmk/tmk_core) keyboard firmware library and
was tested with the [Pro Micro](https://joy-it.net/en/products/ARD_Pro-Micro)
microcontroller, but other Atmel AVR ATmega32U4 based boards should work as
well.

## Wiring
Connect the Pro Micro pins labeled 7, 8, and 9 to keyboard pins 12, 11, and 10,
respectively (output pins). Connect Pro Micro pins 10, 16, 14, and 15 to
keyboard pins 7, 6, 5, and 4, respectively (input pins). The kebyoard pinout
can be found [here](https://www.nesdev.org/wiki/Expansion_port).

## Build Instructions
Make sure you have [avr-gcc](https://gcc.gnu.org/wiki/avr-gcc),
[avr-libc](https://github.com/avrdudes/avr-libc), and
[avrdude](http://savannah.nongnu.org/projects/avrdude) installed. Then clone
the repository with the following command:
```sh
git clone --recurse-submodules https://github.com/potamides/siemens-pc16-11-converter
```
To build the firmware and program the controller change into the project
directory and run these commands:
```sh
make
avrdude -patmega32u4 -cavr109 -b57600 -Uflash:w:hvc_007.hex -P /dev/ttyACM0
```

You can change the keymap in `keymap.c`. You can find a list of possible key
symbols in
[tmk_core/doc/keycode.txt](https://github.com/tmk/tmk_core/blob/master/doc/keycode.txt).
Look at
[tmk_core/doc/keymap.md](https://github.com/tmk/tmk_core/blob/master/doc/keymap.md)
for more details.
