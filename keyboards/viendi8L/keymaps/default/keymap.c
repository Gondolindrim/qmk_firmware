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
#define BEHAVIOR_CHANGE_DELAY 3000

// Defining encoder click keycode
enum keyboard_keycodes {
        ENCODER_CLICK = SAFE_RANGE,
	ENCDBCH,// Stands for ENCODER DELAY BEHAVIOR CHANGE
	ALTTABS,// For alt-tab-switch
	ALTTABC,// For alt-tab-click
	ENCMUP, // Encoder mode up
	ENCMDN, // Encoder mode down
	TGLCK,  // Toggle lock mode
	FND     // Toggle layer 2 on tap, turn layer 1 on hold
};

uint16_t encoder_click_delay = ENCODER_HIGH_DELAY;


typedef int color[RGB_PIN_COUNT];
#define COLOR(r,g,b) ((color){r,g,b})
#define RED COLOR(0,1,1)
#define GREEN COLOR(1,0,1)
#define BLUE COLOR(1,1,0)
#define YELLOW COLOR(0,0,1)
#define PINK COLOR(0,1,0)
#define WHITE COLOR(0,0,0)
#define CYAN COLOR(1,0,0)
#define OFF COLOR(1,1,1)

#define STARTUP_COLOR WHITE

typedef struct _encoder_mode_t {
	color indicator_color;
	uint16_t clockwise_key[4];
	uint16_t counterclockwise_key[4];
	uint16_t clicked_key[4] ;
} encoder_mode_t;

const encoder_mode_t encoder_modes[] = {
	{ .indicator_color = RED    , .clockwise_key = {KC_VOLD, ENCMDN, KC_NO  , KC_NO  }, .counterclockwise_key = {KC_VOLU, ENCMUP, KC_NO  , KC_NO  }, .clicked_key = {KC_MUTE, KC_MPLY, KC_NO  , KC_NO  } },
	{ .indicator_color = GREEN  , .clockwise_key = {KC_WH_D, ENCMDN, KC_WH_D, KC_WH_D}, .counterclockwise_key = {KC_WH_U, ENCMUP, KC_WH_U, KC_WH_U}, .clicked_key = {KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1} },
	{ .indicator_color = BLUE   , .clockwise_key = {ALTTABS, ENCMDN, ALTTABS, ALTTABS}, .counterclockwise_key = {ALTTABS, ENCMUP, ALTTABS, ALTTABS}, .clicked_key = {ALTTABC, ALTTABC, ALTTABC, ALTTABC} }, 
	// Insert your custom encoder mode here
};

#define NUM_ENCODER_MODES (sizeof(encoder_modes)/sizeof(encoder_modes[0]))

int pin_count;
void set_indicator_colors(const color target_color){
	for (pin_count = 0 ; pin_count < RGB_PIN_COUNT ; pin_count++) writePin(rgb_indicators_pins[pin_count], target_color[pin_count]) ;
}

// This counter is used to track what encoder mode is being used at a certain time
int encoder_mode_count = 0;

// Board init: RGB indicator iss set to STARTUP_COLOR and the THT indicators are set
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

#define TCAPS LT(1, KC_CAPS) // Tap-CAPS configuration: MO(1) when held, CAPS when tapped

// ------------------------------------------------------------------------------------------------
// Defining the FND key, short for FN DANCE: if held, turns layer 1 on and if tapped toggles layer 2
// Define a type for as many tap dance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Declare the functions to be used with your tap dance key(s)

// Function associated with all tap dances
td_state_t cur_dance(qk_tap_dance_state_t *state);

// Functions associated with individual tap dances
void fnd_finished(qk_tap_dance_state_t *state, void *user_data);
void fnd_reset(qk_tap_dance_state_t *state, void *user_data);
// ------------------------------------------------------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [0] = LAYOUT_all(
        ENCODER_CLICK, KC_PSLS, KC_PAST, KC_BSPC, KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC,
              KC_PMNS, KC_P7  , KC_P8  , KC_P9  , KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
              KC_PPLS, KC_P4  , KC_P5  , KC_P6  , TCAPS  , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT , KC_BSPC,
	      KC_PENT, KC_P1  , KC_P2  , KC_P3  , KC_LSFT, KC_BSLS, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, KC_NUHS,
              KC_PENT, KC_P0  , KC_P0  , KC_PDOT, KC_LCTL,          KC_LGUI, KC_LALT,                   KC_SPC ,          TD(FND), KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, MO(1)
	),
   [1] = LAYOUT_all(
        ENCODER_CLICK, KC_F10 , KC_F11 , KC_NLCK, KC_GRV , KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, KC_NO  , 
              KC_MINS, KC_F7  , KC_F8  , KC_F9  , TG(2)  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_INS , KC_NO  , KC_PSCR, KC_NO  , KC_NO  , KC_NO  ,
              KC_EQL , KC_F4  , KC_F5  , KC_F6  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
              KC_NO  , KC_F1  , KC_F2  , KC_F3  , KC_NO  , KC_LPRN, KC_RPRN, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , 
              KC_NO  , KC_CALC, KC_CALC, KC_DEL , TGLCK  ,          KC_SLEP, KC_NO  ,                   KC_NO  ,          KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO
        ),
   [2] = LAYOUT_all(
        ENCODER_CLICK, KC_PSLS, KC_PAST, KC_BSPC, KC_GESC, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_BSPC,
              KC_PMNS, KC_P7  , KC_P8  , KC_P9  , KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
              KC_PPLS, KC_P4  , KC_P5  , KC_P6  , TCAPS  , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT , KC_BSPC,
	      KC_PENT, KC_P1  , KC_P2  , KC_P3  , KC_LSFT, KC_BSLS, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, KC_NUHS,
              KC_PENT, KC_P0  , KC_P0  , KC_PDOT, KC_LCTL,          KC_LGUI, KC_LALT,                   KC_SPC ,          TD(FND), KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, MO(1)
	),
   [3] = LAYOUT_all(
        ENCODER_CLICK, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,                   KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        )
};

// FINISH FN TAPDANCE DEFINITIONS -----------------------------------------------------------------
// Determine the tapdance state to return
// Determine the current tap dance state
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }
    else return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t fnd_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void fnd_finished(qk_tap_dance_state_t *state, void *user_data) {
    fnd_tap_state.state = cur_dance(state);
    switch (fnd_tap_state.state) {
        case TD_SINGLE_HOLD:
            layer_on(1);
            break;
        case TD_SINGLE_TAP:
            // Check to see if the layer is already set
            if (layer_state_is(2)) {
                // If already set, then switch it off
                layer_off(2);
            } else {
                // If not already set, then switch the layer on
                layer_on(2);
            }
            break;
	case TD_NONE: break;
	case TD_UNKNOWN: break;
    }
}

void fnd_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (fnd_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(1);
    }
    fnd_tap_state.state = TD_NONE;
}

// Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
    [FND] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, fnd_finished, fnd_reset, 275)
};
// ------------------------------------------------------------------------------------------------

bool is_alt_tab_active = false; // Flag to check if alt tab is active
uint32_t alt_tab_timer = 0;     // Time trigger for alt tab
uint16_t mapped_code = 0;
uint32_t held_keycode_timer = 0;

int current_layer = 0 ; // Updated in layer_state_set_user each time a layer change is made


void cycle_encoder_mode(bool forward){
	if (forward){ encoder_mode_count++ ; } // Shifts encoder mode forward
	else {
		encoder_mode_count-- ;
		if (encoder_mode_count == -1){ encoder_mode_count = NUM_ENCODER_MODES - 1; }
	} // Shifts encoder mode backward
	encoder_mode_count = encoder_mode_count%NUM_ENCODER_MODES ; // This makes sure encoder_mode_count keeps cycling between 0,1,...,NUM_ENCODER_MODES and doesnt eventually overflow
	set_indicator_colors( encoder_modes[ encoder_mode_count ].indicator_color ); // Set indicator color to the corresponding defined color
}

bool is_keyboard_locked = false ;

void encoder_update_user(uint8_t index, bool clockwise) {
	if (!is_keyboard_locked) {
		if (clockwise){
			mapped_code = encoder_modes[ encoder_mode_count ].clockwise_key[ current_layer ];
		} else {
			mapped_code = encoder_modes[ encoder_mode_count ].counterclockwise_key[ current_layer ];
		}
		switch (mapped_code) {
			case ALTTABS:
				if(!is_alt_tab_active) {
					is_alt_tab_active = true;
					register_code(KC_LALT);
				}
				alt_tab_timer = timer_read32();
				tap_code16(!clockwise ? KC_TAB : S(KC_TAB));
				break;
			case ENCMUP:
				cycle_encoder_mode(true);
				break;
			case ENCMDN:
				cycle_encoder_mode(false);
				break;
			default:
			{
				register_code(mapped_code);
				held_keycode_timer = timer_read32();
				while (timer_elapsed32(held_keycode_timer) < MEDIA_KEY_DELAY)
				; /* no-op */
				unregister_code(mapped_code);
				break;
			}
		}
	}
}

uint32_t held_click_timer = false;
bool is_click_held;
uint32_t encdbch_hold_timer;
bool is_encdbch_held;
void change_encoder_delay_behavior(void){
	if (encoder_click_delay == ENCODER_LOW_DELAY){
		encoder_click_delay = ENCODER_HIGH_DELAY;
	} else {
		encoder_click_delay = ENCODER_LOW_DELAY;
	}
}

bool automatic_encoder_mode_cycle = false; // This flag registers if the encoder mode was automatically cycled 
uint32_t blinking_timer;
#define BLINKING_TIME 500
bool are_leds_lit = false;
led_t led_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (!is_keyboard_locked){
		switch (keycode) {
			case ENCDBCH:
				/* This keycode controls the change of delay behavior of the encoder, that is, it allows the user to swap the delay behaviors (no-delay and delayed behavior) on-the-fly.
				   The way this works is, at the beggining of the code a macro BEHAVIOR_CHANGE_DELAY was defined. The idea is that if the ENCDBCH click is held for more than that macro, the behavior is swapped.
				   When the keycode is pressed, a timer encdbch is started; in the housekeeping_user function, which runs every end of matrix processing, the timer is sampled again and if the total held time was larger than BEHAVIOR_CHANGE_DELAY, the encoder behavior mode is swapped.
				*/
				if (record->event.pressed){
					encdbch_hold_timer = timer_read32();
					set_indicator_colors(WHITE);
					is_encdbch_held = true;	
				} else {
					is_encdbch_held = false;
					set_indicator_colors( encoder_modes[encoder_mode_count].indicator_color ); // Place indicator color back to the mode it was before
					if ( timer_elapsed32(encdbch_hold_timer) > BEHAVIOR_CHANGE_DELAY) change_encoder_delay_behavior();
				}
				return false;			
			case ENCODER_CLICK:
				if (record->event.pressed) { // What to do when the encoder is pressed
					is_click_held = true;
					held_click_timer = timer_read32();
				} else { // What to do when encoder is released
					is_click_held = false;
					if (timer_elapsed32(held_click_timer) < encoder_click_delay && !automatic_encoder_mode_cycle ){ // Checking if the time the encoder click was held was smaller than the delay defined and if an automatic mode change was not already performed. If it was, just register whatever it is the click does.
						switch ( encoder_modes[ encoder_mode_count ].clicked_key[ current_layer ] ){
							case ALTTABC:
								unregister_code(KC_LALT);
								is_alt_tab_active = false;
								break;
							default:
								register_code( encoder_modes[ encoder_mode_count ].clicked_key[ current_layer ]  );
								uint32_t held_keycode_timer = timer_read32();
								while (timer_elapsed32(held_keycode_timer) < MEDIA_KEY_DELAY);
								unregister_code( encoder_modes[ encoder_mode_count ].clicked_key[ current_layer ] );
								break;
						}
					} else { // If the encoder click was held for more time than the delay:
						if (!automatic_encoder_mode_cycle) cycle_encoder_mode(true);
					};
					automatic_encoder_mode_cycle = false;
				};
				return false; // Skip all further processing of this key
			case KC_LALT: // If this is not defined, if the encoder is activated in the alt-tab mode while the LALT key is pressed, the menu goes away.
				if (record->event.pressed){
					is_alt_tab_active = true;
				}
				return true;
			case ENCMUP:
				cycle_encoder_mode(true);
				return false;
			case ENCMDN:
				cycle_encoder_mode(false);
				return false;
			case TGLCK:
				if (!record->event.pressed){
					blinking_timer = timer_read32();
					held_keycode_timer = timer_read32();
					is_keyboard_locked = true;
					writePin(TOP_INDICATOR_PIN, 0);
					writePin(MID_INDICATOR_PIN, 0);
					writePin(BOT_INDICATOR_PIN, 0);
					while (timer_elapsed32(held_keycode_timer) < MEDIA_KEY_DELAY)  ;
					are_leds_lit = true;
				}
				return false;
			default:
				return true; // Process all other keycodes normally
		};
	} else {
		switch (keycode){
			case TGLCK:
				if (!record->event.pressed){
					is_keyboard_locked = false;
				}
				// Resetting top, mid and bottom indicators to state they were before the lock
				led_state = host_keyboard_led_state();
				writePin(TOP_INDICATOR_PIN, !led_state.num_lock);
				writePin(MID_INDICATOR_PIN, !led_state.caps_lock);
				writePin(BOT_INDICATOR_PIN, !IS_LAYER_ON(2));
				are_leds_lit = false;
				return false;
			default:
				return false;
		}
	}
};

// Setting up caps lock and num lock indicators
bool led_update_kb(led_t led_state) {
	bool res = led_update_user(led_state);
	if (!is_keyboard_locked){
		if(res) {
			writePin(TOP_INDICATOR_PIN, !led_state.num_lock);
			writePin(MID_INDICATOR_PIN, !led_state.caps_lock);
		}
	}
	return res;
}

layer_state_t layer_state_set_user(layer_state_t state) {
	current_layer = get_highest_layer(state);
	
	switch (current_layer) {
		case 2:
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
		if (timer_elapsed32(alt_tab_timer) > ALT_TAB_DELAY) {
			unregister_code(KC_LALT);
			is_alt_tab_active = false;
		}
	}
	if (is_encdbch_held && timer_elapsed32(encdbch_hold_timer) > BEHAVIOR_CHANGE_DELAY) set_indicator_colors(encoder_modes[encoder_mode_count].indicator_color) ;
	if (is_click_held && timer_elapsed32(held_click_timer) > ENCODER_HIGH_DELAY ){
		automatic_encoder_mode_cycle = true;
		held_click_timer = timer_read32();
		cycle_encoder_mode(true);
	}
	if (is_keyboard_locked){
		if ( timer_elapsed32(blinking_timer) > BLINKING_TIME ){
			writePin(TOP_INDICATOR_PIN, are_leds_lit = !are_leds_lit);
			writePin(MID_INDICATOR_PIN, are_leds_lit);
			writePin(BOT_INDICATOR_PIN, are_leds_lit);
			blinking_timer = timer_read32();
		}
	} else writePin(BOT_INDICATOR_PIN, !IS_LAYER_ON(2));
}

//void matrix_scan_user(void){
//	if (is_keyboard_locked){
//		if ( timer_elapsed32(blinking_timer) > BLINKING_TIME ){
//			writePin(TOP_INDICATOR_PIN, are_leds_lit = !are_leds_lit);
//			writePin(MID_INDICATOR_PIN, are_leds_lit);
//			writePin(BOT_INDICATOR_PIN, are_leds_lit);
//			blinking_timer = timer_read32();
//		}
//	}
//}
