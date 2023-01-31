/*
 Copyright 2022 Gondolindrim <gondolindrim@acheronproject.com>

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

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 14

#define MATRIX_COL_PINS { A3 , A2 , A1 , B0 , A7 , A6 , B8 , B9 , B5 , B4 , B3 , A15, C14, C13 }
#define MATRIX_ROW_PINS { A4 , A5 , B10, A10, A0 , C15 }
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define BACKLIGHT_PWM_DRIVER PWMD3
#define BACKLIGHT_PWM_CHANNEL 4
#define BACKLIGHT_PAL_MODE 2
#define BACKLIGHT_PIN B1
#define BACKLIGHT_LEVELS 5
#define BACKLIGHT_CAPS_LOCK
