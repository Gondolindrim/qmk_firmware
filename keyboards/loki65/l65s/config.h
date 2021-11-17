/*
 Copyright 2020 Álvaro "Gondolindrim" Volpato <alvaro.volpato@usp.br>

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

/* USB Device descriptor parameter */
#define VENDOR_ID       0x7675 // LK for Loki
#define PRODUCT_ID      0x6583 // For 65S
#define DEVICE_VER      0x0001
#define MANUFACTURER    Loki65
#define PRODUCT         L65S

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

#define MATRIX_COL_PINS { B14, A3 , A4 , B12, A8 , A15, A0 , B3 , B4 , B5 , B8 , B9 , C13, C14, C15}
#define MATRIX_ROW_PINS { A5 , A6 , A10, B10, A1 }
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define EEPROM_I2C_24LC128
//#define I2C1_CLOCK_SPEED 400000
//#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2

#define EARLY_INIT_PERFORM_BOOTLOADER_JUMP TRUE

#define STM32_HSECLK 8000000

#define OPENDRAIN_INDICATORS
#define LED_CAPS_LOCK_PIN A2

#define RGB_DI_PIN B15
#define RGBLED_NUM 16
#define RGBLIGHT_LIMIT_VAL 150
#define RGBLIGHT_ANIMATIONS

#define WS2812_PWM_COMPLEMENTARY_OUTPUT
#define WS2812_PWM_DRIVER PWMD1
#define WS2812_PWM_CHANNEL 3
#define WS2812_PWM_PAL_MODE 1
#define WS2812_DMA_STREAM STM32_DMA2_STREAM5
#define WS2812_DMA_CHANNEL 6


/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

#define TAP_CODE_DELAY 50
