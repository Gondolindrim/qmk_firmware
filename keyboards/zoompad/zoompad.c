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

#include "zoompad.h"
void board_init(void) {
	setPinInput(B6);
	setPinInput(B7);
}

uint16_t indicator_color[3] = { 0xFF, 0xFF, 0xFF } ;

bool led_update_kb(led_t led_state) {
//    if (led_state.num_lock) current_color = indicator_color ;
//    else current_color = {0x00,0x00,0x00};
    if (led_state.num_lock){
        for (int i = 0 ; i < 3 ; i++) rgblight_setrgb_at( indicator_color[0] , indicator_color[1] , indicator_color[2] , 0);
    } else {
        for (int i = 0 ; i < 3 ; i++) rgblight_setrgb_at( 0x00 , 0x00 , 0x00 , 0);
    }
    return true;
}

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if(!encoder_update_user(index, clockwise)) return false;
    if (index == 0) {
        if (clockwise) tap_code_delay(KC_VOLU, 10);
        else tap_code_delay(KC_VOLD, 10);
    }   
    return true;
}
#endif
