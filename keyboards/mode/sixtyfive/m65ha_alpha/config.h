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
#define PRODUCT_ID      0x6566 // 65A + 1 since the pre-alpha version was 6565
#define DEVICE_VER      0x0065 // A for release Alpha
#define PRODUCT         SixtyFive HA

/* Matrix */
#define MATRIX_COL_PINS { B10, B12, C8 , C4 , C5 , B0 , C10, B13, B14, B15, A15, C6 , C7 , A8 , C9}
#define MATRIX_ROW_PINS { A7 , A10, D2 , C12, B1 , C11 }
