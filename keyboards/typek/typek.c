/* Copyright 2020 Álvaro "Gondolindrim" Volpato
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

#include "typek.h"


void board_init(void) {
	rgblight_set_effect_range(0,24);
}

bool led_update_kb(led_t led_state) {
	rgblight_setrgb_at( led_state.caps_lock? 0xFF : 0x00,0x00,0x00,24);
	return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
	switch (get_highest_layer(state)) {
	case 1:
		rgblight_setrgb_at (0x00,0xFF,0x00,25);
		rgblight_setrgb_at (0x00,0x00,0x00,26);
		break;
	case 2:
		rgblight_setrgb_at (0x00,0x00,0x00,25);
		rgblight_setrgb_at (0x00,0x00,0xFF,26);
		break;
	default: //  for any other layers, or the default layer
		rgblight_setrgb_at (0x00,0x00,0x00,25);
		rgblight_setrgb_at (0x00,0x00,0x00,26);
		break;
	}
	return state;
}
