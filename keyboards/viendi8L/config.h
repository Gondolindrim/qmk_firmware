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
#define VENDOR_ID       0x8673 // VI for Viendi
#define PRODUCT_ID      0x0876 // 8L
#define DEVICE_VER      0x0001
#define MANUFACTURER    Viendi
#define PRODUCT         8L

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 18

#define MATRIX_COL_PINS { B4 , B5 , B6 , B9 , A3 , A2 , A4 , A1 , A5 , A7 , B3 , A10, A9 , A8 , B14, B12, B11, B10}
#define MATRIX_ROW_PINS { B0 , B1 , B2 , A15, A13}
#define DIODE_DIRECTION COL2ROW

#define BACKLIGHT_PIN           A6
#define BACKLIGHT_PWM_DRIVER    PWMD3
#define BACKLIGHT_PWM_CHANNEL   1
#define BACKLIGHT_PAL_MODE      1
#define BACKLIGHT_LEVELS 6
#define BACKLIGHT_BREATHING
#define BREATHING_PERIOD 6

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define RGB_DI_PIN B15
#define RGBLED_NUM 16
#define RGBLIGT_LIMIT_VAL 200
#define RGBLIGHT_SLEEP
#define RGBLIGHT_ANIMATIONS

#define ENCODERS_PAD_A { B7 }
#define ENCODERS_PAD_B { B8 }
#define ENCODER_RESOLUTION 2

#define RED_INDICATOR_PIN C14
#define GREEN_INDICATOR_PIN C13
#define BLUE_INDICATOR_PIN C15
#define RGB_PIN_COUNT 3

#define TOP_INDICATOR_PIN A0
#define MID_INDICATOR_PIN F1
#define BOT_INDICATOR_PIN F0

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
