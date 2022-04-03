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
#define VENDOR_ID 0x3A37 // ZW for ZoomWalt
#define PRODUCT_ID 0x3A30 // ZP for Zoompad
#define DEVICE_VER 0x0002
#define MANUFACTURER Zoomwalt
#define PRODUCT Zoompad

#define MATRIX_ROWS 7
#define MATRIX_COLS 8

#define MATRIX_COL_PINS { B14, A10, A15, B4 , B0 , A0 , C15, C13 }
#define MATRIX_ROW_PINS { B3 , A8 , C14, B9 , B1 , B10, B12 }
#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

#define STM32_HSECLK 8000000

#define RGB_DI_PIN B15
#define RGBLED_NUM 1

#define WS2812_PWM_COMPLEMENTARY_OUTPUT
#define WS2812_PWM_DRIVER PWMD1
#define WS2812_PWM_CHANNEL 3
#define WS2812_PWM_PAL_MODE 1
#define WS2812_DMA_STREAM STM32_DMA2_STREAM5
#define WS2812_DMA_CHANNEL 6

#define ENCODERS_PAD_A { B8 }
#define ENCODERS_PAD_B { B5 }
