/*
Copyright 2020 Gondolindrim

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0xAC11
#define PRODUCT_ID 0x5241 // RA for Raphael
#define DEVICE_VER 0x0001 // Rev. Alpha
#define MANUFACTURER AcheronProject
#define PRODUCT Raphael rev Alpha

#define MATRIX_ROWS 9
#define MATRIX_COLS 15

                     //   C0 , C1 , C2 , C3 , C4 , C5 , C6 , C7 , C8 , C9 , C10, C11, C12, C13, C14
#define MATRIX_COL_PINS { B14, A10, B3 , B9 , B8 , B5 , B12, B10, B1 , B0 , A7 , A5 , A1 , C14, C15 }
                       // R0 , R1 , R2 , R3 , R4 , R5 , R6 , R7 , R8 
#define MATRIX_ROW_PINS { A0 , B4 , C13, A4 , B13, B15, A8 , A3 , A15 } 

#define BOOTMAGIC_LITE_ROW 5
#define BOOTMAGIC_LITE_COLUMN 0

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

#define BACKLIGHT_PIN           A6
#define BACKLIGHT_PWM_DRIVER    PWMD3
#define BACKLIGHT_PWM_CHANNEL   1
#define BACKLIGHT_PAL_MODE      2
#define BACKLIGHT_LEVELS 20
#define BACKLIGHT_BREATHING
#define BREATHING_PERIOD 5

#define STM32_HSECLK 8000000

#define LED_CAPS_LOCK_PIN A2

// If this is defined, the caps lock LED will turn on and off according to the state of caps lock. If not, the LED will shine like all other LEDs despite the caps lock state.
#define CAPSLOCK_INDICATOR
