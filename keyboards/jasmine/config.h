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
#define VENDOR_ID 0x4753 // GS for GraveShift
#define PRODUCT_ID 0x2A53 // For JS
#define DEVICE_VER 0x0001
#define MANUFACTURER GraveShift
#define PRODUCT Jasmine65

#define MATRIX_ROWS 5
#define MATRIX_COLS 15
//                        C0 , C1 , C2 , C3 , C4 , C5 , C6 , C7 , C8 , C9 , C10, C11, C12, C13, C14
#define MATRIX_COL_PINS { A2 , C14, C13, B9 , B8 , B5 , B4 , B3 , A15, A10, C8 , B15, B14, B13, B12 }
//                        R0 , R1 , R2 , R3 , R4
#define MATRIX_ROW_PINS { B1 , B10, C15, A0 , A1 }
#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

#define STM32_HSECLK 8000000

#define EEPROM_I2C_24LC256
