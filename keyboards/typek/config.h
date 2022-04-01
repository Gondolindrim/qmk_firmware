/*
Copyright 2022 Gondolindrim

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
#define VENDOR_ID 0x7179 // GO for GOK
#define PRODUCT_ID 0x8475 // TK for TypeK
#define DEVICE_VER 0x0001 
#define MANUFACTURER gok
#define PRODUCT TypeK

#define MATRIX_ROWS 5
#define MATRIX_COLS 14

#define MATRIX_COL_PINS { A3 , B12, B14, A10, B0 , B1 , B10, B3 , C15, C14, C13, B9 , B8 , B5 }
#define MATRIX_ROW_PINS { A7 , A8 , A15, A1 , A2 }

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

#define STM32_HSECLK 8000000

#define RGB_DI_PIN B15
#define RGBLED_NUM 27
#define RGBLIGHT_ANIMATIONS

#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_TWINKLE

#define RGBLIGHT_DEFAULT_MODE (RGBLIGHT_MODE_RAINBOW_SWIRL + 5)

#define WS2812_PWM_COMPLEMENTARY_OUTPUT
#define WS2812_PWM_DRIVER PWMD1
#define WS2812_PWM_CHANNEL 3
#define WS2812_PWM_PAL_MODE 1
#define WS2812_DMA_STREAM STM32_DMA2_STREAM5
#define WS2812_DMA_CHANNEL 6

#define RGBLIGHT_LED_MAP {26,25,24,0,1,23,22,11,10,9,8,7,6,5,4,3,2,12,13,14,15,16,17,18,19,20,21}
