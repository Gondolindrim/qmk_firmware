# Noxary X60 V2 PCB QMK firmware

![x60v2](https://cdn.shopify.com/s/files/1/0071/6377/3043/products/NX_X60-V2-5th-AE_001_dist_9a6b2b27-8f49-4f03-9284-7aad9188cab2_1296x.jpg?v=1633791366)

A 60% by Noxary Works

* Keyboard Maintainer: [Gondolindrim](https://github.com/Gondolindrim)
* Hardware Supported: proprietary PCB
* Hardware Availabilit: as of december 2021, the board has not enteredy group buy yet.

## How to flash

### Enter bootloader

The DFU state in the bootloader can be accessed in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: press the button on the front of the PCB, next to caps lock, for at least five seconds
* **Keycode in layout**: Press the key mapped to `RESET` if it is available (top left or escape key in layer 1 of the default keymap).

## Compile firmware

Make example for this keyboard (after setting up your build environment):

    make noxary/x60:default

To directly flash the PCB after it is put into a DFU state, use

    make noxary/x60:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
