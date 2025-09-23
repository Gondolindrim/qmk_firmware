/* Copyright 2020 Gondolindrim
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

#define F13_LED_PIN C2
#define ESC_LED_PIN C2

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        gpio_write_pin(F13_LED_PIN, 1);
        gpio_write_pin(ESC_LED_PIN, 1);
    }
    else {
        gpio_write_pin(F13_LED_PIN, 0);
        gpio_write_pin(ESC_LED_PIN, 0);
    }
    return true;
}
