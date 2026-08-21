/* Copyright 2026 Gondolindrim
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

void keyboard_post_init_kb(void){
    rgblight_set_effect_range(0, 20);
    keyboard_post_init_user();
}

void keyboard_pre_init_kb(void) {
    // Configure pin A0 as a push-pull output
    gpio_set_pin_output_push_pull(B10);
    gpio_set_pin_output_push_pull(C8);
    gpio_set_pin_output_push_pull(B5);
    gpio_set_pin_output_push_pull(B4);
}


bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if(res) {
        gpio_write_pin(B10, led_state.caps_lock);
        gpio_write_pin(C8, led_state.num_lock);
        gpio_write_pin(B5, led_state.caps_lock);
        gpio_write_pin(B4, led_state.caps_lock);
    }
    return res;
}
