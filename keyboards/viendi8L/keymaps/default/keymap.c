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

#include QMK_KEYBOARD_H
#define MEDIA_KEY_DELAY 3

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

int encoder_click_delay = 10;

// Set colored indicator colors

// Defining 3-bit colors for the indicator LED

int STARTUP_COLOR[3] = {0,0,1};
int MODE0_COLOR[3] = {0,1,1};
int MODE1_COLOR[3] = {1,0,1};
int MODE2_COLOR[3] = {1,1,0};

#define MODE0_CLOCKWISE KC_VOLD
#define MODE0_COUNTERCLOCKWISE KC_VOLU
#define MODE0_CLICK KC_MPLY

#define MODE1_CLOCKWISE KC_BRID
#define MODE1_COUNTERCLOCKWISE KC_BRIU
#define MODE1_CLICK KC_PSCREEN

#define MODE2_CLOCKWISE KC_WH_U
#define MODE2_COUNTERCLOCKWISE KC_WH_D
#define MODE2_CLICK KC_BTN1

uint16_t encoder_clockwise_modes[3] = {MODE0_CLOCKWISE, MODE1_CLOCKWISE, MODE2_CLOCKWISE };
uint16_t encoder_counterclockwise_modes[3] = {MODE0_COUNTERCLOCKWISE, MODE1_COUNTERCLOCKWISE, MODE2_COUNTERCLOCKWISE };
uint16_t encoder_click_modes[3] = {MODE0_CLICK, MODE1_CLICK, MODE2_CLICK };

int encoder_mode_count = 0;

void board_init(void){
	// Set the RGB indicator pins as open drain and set the startup color
	palSetLineMode(RED_INDICATOR_PIN, PAL_MODE_OUTPUT_OPENDRAIN);	
	writePin(RED_INDICATOR_PIN, STARTUP_COLOR[0]);
	palSetLineMode(GREEN_INDICATOR_PIN, PAL_MODE_OUTPUT_OPENDRAIN);	
	writePin(GREEN_INDICATOR_PIN, STARTUP_COLOR[1]);
	palSetLineMode(BLUE_INDICATOR_PIN, PAL_MODE_OUTPUT_OPENDRAIN);	
	writePin(BLUE_INDICATOR_PIN, STARTUP_COLOR[2]);

	// Set the three LED indicator pins as open drain and set them off	
	palSetLineMode(TOP_INDICATOR_PIN, PAL_MODE_OUTPUT_OPENDRAIN);	
	palSetLineMode(MID_INDICATOR_PIN, PAL_MODE_OUTPUT_OPENDRAIN);	
	palSetLineMode(BOT_INDICATOR_PIN, PAL_MODE_OUTPUT_OPENDRAIN);

	writePin(TOP_INDICATOR_PIN, 1);
	writePin(MID_INDICATOR_PIN, 1);
	writePin(BOT_INDICATOR_PIN, 1);
};

void keyboard_post_init_user(void){
	writePin(RED_INDICATOR_PIN, MODE0_COLOR[0]);
	writePin(GREEN_INDICATOR_PIN, MODE0_COLOR[1]);
	writePin(BLUE_INDICATOR_PIN, MODE0_COLOR[2]);
};

// Defining encoder click keycode
enum keyboard_keycodes {
        ENCODER_CLICK = SAFE_RANGE,
	ENCDBCH // Stands for ENCODER DELAY BEHAVIOR CHANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [0] = LAYOUT_all(
        ENCODER_CLICK, KC_PSLS, KC_PAST, KC_DEL , KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC,
              KC_P7  , KC_P8  , KC_P9  , KC_PPLS, KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
              KC_P4  , KC_P5  , KC_P6  , KC_P6  , KC_CAPS, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT , KC_BSPC,
	      KC_P1  , KC_P2  , KC_P3  , KC_PENT, KC_LSFT, KC_BSLS, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, KC_NUHS,
              KC_P0  , KC_P0  , KC_PDOT, KC_PDOT, KC_LCTL,          KC_LGUI, KC_LALT,                   RGB_TOG,          KC_RCTL, KC_P0  , KC_LEFT, KC_DOWN, KC_RGHT, KC_SLSH
	)
};

void encoder_update_user(uint8_t index, bool clockwise) {
	uint16_t held_keycode_timer = timer_read();
	uint16_t mapped_code        = 0;
	if (clockwise) {
		mapped_code = encoder_clockwise_modes[ encoder_mode_count ];
	} else {
		mapped_code = encoder_counterclockwise_modes [ encoder_mode_count ];
	}
	register_code(mapped_code);
	while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY);
	unregister_code(mapped_code);
};

uint16_t held_click_timer;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case ENCODER_CLICK:
			if (record->event.pressed) { // What to do when the encoder is pressed
				held_click_timer = timer_read();
			} else { // What to do when encoder is released
				if (timer_elapsed(held_click_timer) < encoder_click_delay ){ // Checking if the time the encoder click was held was smaller than the delay defined. If it was, just register whatever it is the click does
					register_code( encoder_click_modes[ encoder_mode_count ] );
					uint16_t held_keycode_timer = timer_read();
					while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY);
					unregister_code( encoder_click_modes[ encoder_mode_count ] );
				} else { // If the encoder click was held for more time than the delay:
					encoder_mode_count++ ; // Shifts encoder mode
					encoder_mode_count = encoder_mode_count%3 ; // This makes sure encoder_mode_count keeps cycling between 0,1,2 and doesnt eventually overflow
					switch (encoder_mode_count){
						case 0:
							writePin(RED_INDICATOR_PIN, MODE0_COLOR[0]);
							writePin(GREEN_INDICATOR_PIN, MODE0_COLOR[1]);
							writePin(BLUE_INDICATOR_PIN, MODE0_COLOR[2]);
							break;
						case 1:
							writePin(RED_INDICATOR_PIN, MODE1_COLOR[0]);
							writePin(GREEN_INDICATOR_PIN, MODE1_COLOR[1]);
							writePin(BLUE_INDICATOR_PIN, MODE1_COLOR[2]);
							break;
						case 2:
							writePin(RED_INDICATOR_PIN, MODE2_COLOR[0]);
							writePin(GREEN_INDICATOR_PIN, MODE2_COLOR[1]);
							writePin(BLUE_INDICATOR_PIN, MODE2_COLOR[2]);
							break;
						default:
							writePin(RED_INDICATOR_PIN, 0);
							writePin(GREEN_INDICATOR_PIN, 0);
							writePin(BLUE_INDICATOR_PIN, 0);
							break;
					};
				};
			};
			return false; // Skip all further processing of this key
		default:
			return true; // Process all other keycodes normally
		};
	};
