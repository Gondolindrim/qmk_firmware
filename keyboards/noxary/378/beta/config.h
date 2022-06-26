/*
Copyright 2022 Álvaro "Gondolindrim" Volpato  <gondolindrim@acheronproject.com>

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
#define VENDOR_ID       0x4E58 //"NX"
#define PRODUCT_ID      0x017A // 378
#define DEVICE_VER      0x0001
#define MANUFACTURER    Noxary
#define PRODUCT         Noxary 378


/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 17

//                        C0 , C1 , C2 , C3 , C4 , C5 , C6 , C7 , C8 , C9 , C10, C11, C12, C13, C14, C15, C16
#define MATRIX_COL_PINS { A2 , A0 , A15, B9 , B8 , B5 , B4 , A10, A8 , B15, B14, B13, B12, B10, B1 , B0 , A7}
#define MATRIX_ROW_PINS { A6 , A1 , C13, C14, C15 }
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    5

#define STM32_HSECLK 8000000 // Crystal clock definition

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define CAPS_INDICATOR_PIN B3

// Defining the EEPROM
#define EEPROM_I2C_24LC256

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
