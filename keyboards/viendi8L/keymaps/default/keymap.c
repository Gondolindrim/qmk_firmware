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
#include<print.h>
#include QMK_KEYBOARD_H
#define MEDIA_KEY_DELAY 10
#define ALT_TAB_DELAY 1000
pin_t rgb_indicators_pins[ RGB_PIN_COUNT ] = {RED_INDICATOR_PIN, GREEN_INDICATOR_PIN, BLUE_INDICATOR_PIN};
/*
---------------------------------------
       VIENDI 8L KEYMAP FILE
---------------------------------------
In this file you can customize the layouts for the VIENDI8L keyboard, including the behavior of the encoder. First, a little explanation on how the mechanic of the encoder and the colored indicator works.

The encoder has three modes, which we will call mode zero, mode one and mode two. By clicking the encoder one can cycle between the modes; each mode is indicated by the keyboard through a unique color shone by an RGB indicator.

The modes, as well as the colors themselves, are user-configurable. By default:
	- In mode zero the LED shines red and the encoder and adjusts system volume;
	- In mode one the LED shines green and the encoder controls screen brightness;
	- In mode two the LED shines blue and the encoder acts as a mousewheel.

The way one adjusts the behavior of the encoder is through the MODE(n)_CLOCKWISE and MODE(n)_COUNTERCLOCKWISE variables. Those variables should be set as keycodes.

If you want to adjust the mode colors, you should adjust the MODE(n)_COLOR array; the way this is done is using the predefined color arrays: 
PINK = {0,1,0};
CYAN = {1,0,0};
WHITE = {0,0,0};
YELLOW = {0,0,1};
RED = {0,1,1};
GREEN = {1,0,1};
BLUE = {1,1,0};
OFF = {1,1,1};

Say for instance you want that, in mode one, the clockwise motion of the encoder sends a "next track" keycode while the counter-clockwise motion sends a "previous track". You also want the LED to shine a cyan color. So you should set:
int MODE1_COLOR[3] = {1,0,0};
uint16_t MODE0_CLOCKWISE = KC_MNXT;
uint16_t MODE0_COUNTERCLOCKWISE = KC_MPRV;

---------------------------------------
       STARTUP COLOR
---------------------------------------
During initialization of the microcontroller, from the operating system initialization to matrix initialization, which lasts for about two seconds, the keyboard is not usable. To signal that, you can set a STARTUP_COLOR variable that shines a specific color when the keyboard is in that initialization stage.

---------------------------------------
       ENCODER CLICK DELAY
---------------------------------------
There are two possible behaviors for the encoder click. The first is a "zero-delay" behavior where the encoder click changes encoder modes immediately. This unfortunately makes the encoder click not send any keycodes.

If you want the zero-delay behavior, use
int encoder_click_delay 10

The second behavior is a "delayed" behavior where an encoder click sends an user-definable keycode and to change the encoder mode you have to hold the click for a set amount of time. To enable the delayed behavior you use:
int encoder_click_delay <delay>

Where <delay> is the amount of time in miliseconds you want the user to hold (must be greater than zero) so the mode change is triggered. A time greater than 250 is recommended.

In each mode you can also configure what tapping the encoder click does through the MODE(n)_CLICK variable, also a keycode. By default, mode zero click is media play/pause, mode one click is print screen and mode two click is mouse button 1.

---------------------------------------
    THE THREE LED INDICATORS
---------------------------------------
Additionally, Viendi8L also includes three single-color THT diode indicators that should be soldered  by the user. Their pin locations are defined in the TOP_INDICATOR_PIN, MID_INDICATOR_PIN and BOT_INDICATOR_PIN in ./keyboards/viendi8L/config.h .

By default, from top to bottom, those indicators are the caps lock indicator, num lock indicator, and the layer two indicator which is accessed through the TG(2) keycode. In the default layout, that is hit using Fn (MO(1)) and CTRL.

*/

#define ENCODER_LOW_DELAY 10
#define ENCODER_HIGH_DELAY 500

// Defining encoder click keycode
enum keyboard_keycodes {
        ENCODER_CLICK = SAFE_RANGE,
	ENCDBCH, // Stands for ENCODER DELAY BEHAVIOR CHANGE
	ALT_TAB_SWITCH,
	ALT_TAB_CLICK
};

int encoder_click_delay = 10;


typedef int color[RGB_PIN_COUNT];
#define COLOR(r,g,b) ((color){r,g,b})
#define RED COLOR(0,1,1)
#define GREEN COLOR(1,0,1)
#define BLUE COLOR(1,1,0)
#define YELLOW COLOR(0,0,1)
#define PINK COLOR(0,1,0)

#define STARTUP_COLOR YELLOW

typedef struct _encoder_mode_t {
	color indicator_color;
	uint16_t clockwise_key;
	uint16_t counterclockwise_key;
	uint16_t clicked_key ;
} encoder_mode_t;

#define NUM_ENCODER_MODES 4
const encoder_mode_t encoder_modes[NUM_ENCODER_MODES] = {
	{ .indicator_color = RED, .clockwise_key = KC_VOLD, .counterclockwise_key = KC_VOLU, .clicked_key = KC_MPLY },
	{ .indicator_color = GREEN, .clockwise_key = KC_BRID, .counterclockwise_key = KC_BRIU, .clicked_key = KC_PSCR },
	{ .indicator_color = BLUE, .clockwise_key = KC_WH_D, .counterclockwise_key = KC_WH_U, .clicked_key = KC_BTN1 },
	{ .indicator_color = PINK, .clockwise_key = ALT_TAB_SWITCH, .counterclockwise_key = ALT_TAB_SWITCH, .clicked_key = ALT_TAB_CLICK}, 
};

int pin_count;
void set_indicator_colors(const color target_color){
	for (pin_count = 0 ; pin_count < RGB_PIN_COUNT ; pin_count++) writePin(rgb_indicators_pins[pin_count], target_color[pin_count]) ;
}

int encoder_mode_count = 0;
void board_init(void){
	// Set the RGB indicator pins as open drain and set the startup color
	for (pin_count = 0 ; pin_count < RGB_PIN_COUNT ; pin_count++){
		palSetLineMode(rgb_indicators_pins[pin_count], PAL_MODE_OUTPUT_OPENDRAIN);
	}
	set_indicator_colors(STARTUP_COLOR);

	// Set the three LED indicator pins as open drain and set them off	
	palSetLineMode(TOP_INDICATOR_PIN, PAL_MODE_OUTPUT_OPENDRAIN);	
	palSetLineMode(MID_INDICATOR_PIN, PAL_MODE_OUTPUT_OPENDRAIN);	
	palSetLineMode(BOT_INDICATOR_PIN, PAL_MODE_OUTPUT_OPENDRAIN);
	writePin(TOP_INDICATOR_PIN, 1);
	writePin(MID_INDICATOR_PIN, 1);
	writePin(BOT_INDICATOR_PIN, 1);
};

void keyboard_post_init_user(void){
	for (pin_count = 0 ; pin_count < RGB_PIN_COUNT ; pin_count++) writePin(rgb_indicators_pins[pin_count], encoder_modes[0].indicator_color[pin_count]);
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [0] = LAYOUT_all(
        ENCODER_CLICK, KC_NLCK, KC_PAST, KC_DEL , KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC,
              KC_P7  , KC_P8  , KC_P9  , KC_PPLS, KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
              KC_P4  , KC_P5  , KC_P6  , KC_P6  , KC_CAPS, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT , KC_BSPC,
	      KC_P1  , KC_P2  , KC_P3  , KC_PENT, KC_LSFT, KC_BSLS, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, KC_NUHS,
              KC_P0  , KC_P0  , KC_PDOT, KC_PDOT, KC_LCTL,          KC_LGUI, KC_LALT,                   MO(1),            KC_RCTL, KC_P0  , KC_LEFT, KC_DOWN, KC_RGHT, KC_SLSH
	),
   [1] = LAYOUT_all(
              KC_NLCK, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,                   KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        )
};


bool is_alt_tab_active = false; // Flag to check if alt tab is active
uint16_t alt_tab_timer = 0;     // Time trigger for alt tab
uint16_t mapped_code = 0;
uint16_t held_keycode_timer = 0;

void encoder_update_user(uint8_t index, bool clockwise) {
	if (clockwise){
		mapped_code = encoder_modes[ encoder_mode_count ].clockwise_key;
	} else {
		mapped_code = encoder_modes[ encoder_mode_count ].counterclockwise_key;
	}
	switch (mapped_code) {
		case ALT_TAB_SWITCH:
			if(!is_alt_tab_active) {
				is_alt_tab_active = true;
				register_code(KC_LALT);
			}
			alt_tab_timer = timer_read32();
			tap_code16(!clockwise ? KC_TAB : S(KC_TAB));
			break;
		default:
		{
			register_code(mapped_code);
			held_keycode_timer = timer_read32();
			while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY)
			; /* no-op */
			unregister_code(mapped_code);
			break;
		}
	}
}

uint16_t held_click_timer;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case ENCODER_CLICK:
			if (record->event.pressed) { // What to do when the encoder is pressed
				held_click_timer = timer_read();
			} else { // What to do when encoder is released
				if (timer_elapsed(held_click_timer) < encoder_click_delay ){ // Checking if the time the encoder click was held was smaller than the delay defined. If it was, just register whatever it is the click does
					switch ( encoder_modes[ encoder_mode_count ].clicked_key ){
						case ALT_TAB_CLICK:
							unregister_code(KC_LALT);
							is_alt_tab_active = false;
							break;
						default:
							register_code( encoder_modes[ encoder_mode_count ].clicked_key );
							uint16_t held_keycode_timer = timer_read();
							while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY);
							unregister_code( encoder_modes[ encoder_mode_count ].clicked_key );
							break;
					}
				} else { // If the encoder click was held for more time than the delay:
					encoder_mode_count++ ; // Shifts encoder mode
					encoder_mode_count = encoder_mode_count%NUM_ENCODER_MODES ; // This makes sure encoder_mode_count keeps cycling between 0,1,...,NUM_ENCODER_MODES and doesnt eventually overflow
					set_indicator_colors( encoder_modes[ encoder_mode_count ].indicator_color ); // Set indicator color to the corresponding defined color
				};
			};
			return false; // Skip all further processing of this key
		default:
			return true; // Process all other keycodes normally
	};
};

// Setting up caps lock and num lock indicators
bool led_update_kb(led_t led_state) {
	bool res = led_update_user(led_state);
	if(res) {
		writePin(TOP_INDICATOR_PIN, !led_state.caps_lock);
		writePin(MID_INDICATOR_PIN, !led_state.num_lock);
    	};
	return res;
}

layer_state_t layer_state_set_user(layer_state_t state) {
	switch (get_highest_layer(state)) {
		case 1:
			writePin(BOT_INDICATOR_PIN, 0);
			break;
		default: //  for any other layers, or the default layer
			writePin(BOT_INDICATOR_PIN, 1);
			break;
	}
	return state;
}

void housekeeping_task_user(void) { // The very important timer.
	if (is_alt_tab_active) {
		if (timer_elapsed(alt_tab_timer) > ALT_TAB_DELAY) {
			unregister_code(KC_LALT);
			is_alt_tab_active = false;
		}
	}
}
