/* Copyright 2023 Gondolindrim
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "quantum.h"

uint32_t free_pins[] = {B8, B7, B6, B13, B12, B10, B1, B0, C5, C4, A7, A6, A5, A4, A3, A2, A1, A0}; 

void keyoard_post_init_kb(void) {
    // Seting free pins as outputs and setting them low
    for(int i = 0; i < sizeof(free_pins) / sizeof(uint32_t); i++)
    {
        setPinOutput(free_pins[i]);
        writePinLow(free_pins[i]);
    }
    keyboard_post_init_user();
}
