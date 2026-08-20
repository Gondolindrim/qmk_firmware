# "Bowlttleship" QMK firmware

![b3](https://i.imgur.com/zovOPTv.png)

	The Bowlttleship is a "battleship" keyboard with double-function-row.

* Keyboard Maintainer: [Gondolindrim](https://github.com/Gondolindrim)
* Hardware Supported: STM32F072
* Hardware Availability: this keyboard has not entered public buy as of july 2026.

Make example for this keyboard (after setting up your build environment), depending on your variant:

    make bowl/bowlttleship/b3s:default
    make bowl/bowlttleship/b3h:default

Flashing example for this keyboard:

    make bowl/bowlttleship/b3s:default:flash
    make bowl/bowlttleship/b3h:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 2 ways:

* **Bootmagic reset**: Hold down the top left/right key (for the left/right splits respectively) and plug in the keyboard.
* **Physical reset button**: while the PCB is plugged in, push and hold the physical reset button on the back of the PCB for 5 seconds or more, then release.
