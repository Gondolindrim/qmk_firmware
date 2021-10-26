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
#define PRODUCT_ID      0x6565 // For 65A
#define DEVICE_VER      0x8065 // PA for pre-Alpha
#define PRODUCT         SixtyFive HA

/* Matrix */
#define MATRIX_COL_PINS { B10, B12, C8 , C5 , B0 , B1 , C10, B13, B14, B15, A15, C6 , C7 , C9 , A8 }
#define MATRIX_ROW_PINS { C4 , A10, D2 , C12, A7 , C11 }
