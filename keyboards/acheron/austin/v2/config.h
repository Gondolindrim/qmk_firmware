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

#include "config_common.h"

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 19

//                        C0 , C1 , C2 , C3 , C4 , C5 , C6 , C7 , C8 , C9 , C10, C11, C12, C13, C14, C15, C16, C17, C18
#define MATRIX_COL_PINS { A5 , A4 , A3 , A2 , A1 , A0 , C6 , B12, A10, C9 , B8 , B5 , A15, C1 , C0 , C12, C11, C10, C3 }
//                        R0 , R1 , R2 , R3 , R4 , R5 , R6 , R7 , R8 , R9
#define MATRIX_ROW_PINS { C4 , C5 , B0 , C7 , B9 , C2 , A8 , A6 , B10, A7 }
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define RGB_DI_PIN B15
#define RGBLED_NUM 20
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
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL+5

#define WS2812_PWM_COMPLEMENTARY_OUTPUT
#define WS2812_PWM_DRIVER PWMD1
#define WS2812_PWM_CHANNEL 3
#define WS2812_PWM_PAL_MODE 1
#define WS2812_DMA_STREAM STM32_DMA2_STREAM5
#define WS2812_DMA_CHANNEL 6

#define BACKLIGHT_PIN         B1
#define BACKLIGHT_PWM_DRIVER  PWMD3
#define BACKLIGHT_PWM_CHANNEL 4
#define BAKCLIGHT_PAL_MODE    2
#define BACKLIGHT_LEVELS      20
#define BACKLIGHT_BREATHING
#define BREATHING_PERIOD      10

#define WEAR_LEVELING_LOGICAL_SIZE 2048
#define WEAR_LEVELING_BACKING_SIZE 4096

#define CAPS_INDICATOR_PIN C8
#define INDICATOR_1_PIN D2
#define INDICATOR_2_PIN B3
#define INDICATOR_3_PIN B4
