/* Copyright 2022 Gondolindrim <gondolindrim@acheronproject.com>
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

#define SCRL_INDEX 0
#define NUML_INDEX 1
#define CAPS_INDEX 2


// INDICATOR CALLBACK ------------------------------------------------------------------------------
bool led_update_kb(led_t led_state) {
    // First decides if action is needed. If a user code is defined, or the indicator is disabled, then does not act.
    bool res = led_update_user(led_state);
    led_state.caps_lock   ? rgblight_setrgb_at(0xFF , 0x00 , 0x00 , CAPS_INDEX) : rgblight_setrgb_at(0,0,0, CAPS_INDEX);
    led_state.scroll_lock ? rgblight_setrgb_at(0X00 , 0xFF , 0x00 , SCRL_INDEX) : rgblight_setrgb_at(0,0,0, SCRL_INDEX);
    led_state.num_lock    ? rgblight_setrgb_at(0x00 , 0x00 , 0xFF , NUML_INDEX) : rgblight_setrgb_at(0,0,0, NUML_INDEX);
    return res;
}
