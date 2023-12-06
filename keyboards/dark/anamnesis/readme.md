# Gondolindrim X Dark Anamnesis

The Anamnesis is an F-row-less TKL keyboard designed by Dark, with a PCB designer by Gondolindrim.

* Keyboard Maintainer: [Gondolindrim](https://github.com/Gondolindrim)
* Hardware Supported: proprietary PCB using STM32F411R microcontroller;
* Availability: as of november 2022 both keyboard and PCB were sold in a private Group Buy; therefore availability is limited.

## How to flash

### Enter bootloader

The DFU state in the bootloader can be accessed in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (INSERT in the default keymap) and plug in the keyboard;
* **Physical reset button**: press and hold the button on the back of the PCB, for at least five seconds;
* **Keycode in layout**: Press the key mapped to `QK_BOOT`; in the default layout, that is top left key (INSERT) in layer 1.

### How to compile and flash

You can compile the Iron 165R2 default keymap by using the following:

    make dark/anamnesis:default

And use dfu-util in the command line or through a GUI like QMK toolbox to upload the firmware to the PCB. To directly flash the PCB after it is put into a DFU state, use:

    make dark/anamnesis:default:flash

