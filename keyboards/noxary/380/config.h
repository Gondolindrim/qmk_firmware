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
#define VENDOR_ID 0x4E58 //"NX"
#define PRODUCT_ID 0x017C // "380" 
#define DEVICE_VER 0x0001
#define MANUFACTURER Noxary
#define PRODUCT SharkPCB Noxary 380

#define MATRIX_ROWS 7
#define MATRIX_COLS 18

//                        C0 , C1 , C2 , C3 , C4 , C5 , C6 , C7 , C8 , C9 , C10, C11, C12, C13, C14, C15, C16, C17                   
#define MATRIX_COL_PINS { B10, B0 , A7 , A6 , A5 , A4 , A3 , A2 , A0 , A8 , B15, C14, B14, B13, A10, A15, B4 , B5 }
//                        R0 , R1 , R2 , R3 , R4 , R5 , R6
#define MATRIX_ROW_PINS { B9 , B8 , B12, A1 , C15, C13, B3 }
#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

#define BACKLIGHT_PIN           B1
#define BACKLIGHT_PWM_DRIVER    PWMD3
#define BACKLIGHT_PWM_CHANNEL   4
#define BACKLIGHT_PAL_MODE      2
#define BACKLIGHT_LEVELS 20
#define BACKLIGHT_BREATHING
#define BREATHING_PERIOD 5
#define BACKLIGHT_ON_STATE 1
#define BACKLIGHT_CAPS_LOCK

#define STM32_HSECLK 8000000

// Adjusting the wear-levelled EEPROM is needed because the default 1024 is not enough for 4 dynamic layers
#define WEAR_LEVELING_LOGICAL_SIZE 2048
#define WEAR_LEVELING_BACKING_SIZE 4096
