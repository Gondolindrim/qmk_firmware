/*
 Copyright 2022 Álvaro "Gondolindrim" Volpato <alvaro.volpato@usp.br>

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

#include "delta.h"
#include "eeconfig.h"
#include "print.h"

led_config_t g_led_config = { {
//	{ 0        , 1          , 2          , 3          , 4          , 5          , 6          , 7          , 8          , 9          , 10         , 11         , 12         , NO_LED     , 13         , 14         , 15        },
//	{ 16       , 17         , 18         , 19         , 20         , 21         , 22         , 23         , 24         , 25         , 26         , 27         , 28         , 29         , 30         , 31         , 32        },
//	{ 33       , 34         , 35         , 36         , 37         , 38         , 39         , 40         , 41         , 42         , 43         , 44         , 45         , 46         , 47         , 48         , 49        },
//	{ 50       , 51         , 52         , 53         , 54         , 55         , 56         , 57         , 58         , 59         , 60         , 61         , 62         , NO_LED     , NO_LED     , NO_LED     , NO_LED    },
//	{ 63       , NO_LED     , 64         , 65         , 66         , 67         , 68         , 69         , 70         , 71         , 72         , 73         , 74         , NO_LED     , NO_LED     , 75         , NO_LED    },
//	{ 76       , 77         , 78         , NO_LED     , NO_LED     , NO_LED     , 79         , NO_LED     , NO_LED     , 80         , 81         , 82         , 83         , NO_LED     , 84         , 85         , 86        }
//
	{ 15       , 14         , 13         , 12         , 11         , 10         , 9          , 8          , 7          , 6          , 5          , 4          , 3          , NO_LED     , 2          , 1          , 0         },
	{ 16       , 17         , 18         , 19         , 20         , 21         , 22         , 23         , 24         , 25         , 26         , 27         , 28         , 29         , 30         , 31         , 32        },
	{ 49       , 48         , 47         , 46         , 45         , 44         , 43         , 42         , 41         , 40         , 39         , 38         , 37         , 36         , 35         , 34         , 33         },
	{ 50       , 51         , 52         , 53         , 54         , 55         , 56         , 57         , 58         , 59         , 60         , 61         , 62         , NO_LED     , NO_LED     , NO_LED     , NO_LED    },
	{ 75       , NO_LED     , 74         , 73         , 72         , 71         , 70         , 69         , 68         , 67         , 66         , 65         , 64         , NO_LED     , NO_LED     , 63         , NO_LED    },
	{ 76       , 77         , 78         , NO_LED     , NO_LED     , NO_LED     , 79         , NO_LED     , NO_LED     , 80         , 81         , 82         , 83         , NO_LED     , 84         , 85         , 86        }
},{
// "Fine-tuned" complex configuration
	{ 210,   0}, { 196,   0}, { 182,   0}, { 168,   0}, { 154,   0}, { 140,   0}, { 140,   0}, { 126,   0}, { 112,   0}, {  98,   0}, {  84,   0}, {  70,   0}, {  56,   0},              {  28,   0}, {  14,   0}, {   0,   0},
	{   0,  45}, {  14,  45}, {  28,  45}, {  42,  45}, {  56,  45}, {  70,  45}, {  84,  45}, {  98,  45}, { 112,  45}, { 126,  45}, { 140,  45}, { 154,  45}, { 168,  45}, { 182,  45}, { 196,  45}, { 210,  45}, { 224,  45},
	{ 224,  90}, { 210,  90}, { 196,  90}, { 182,  90}, { 168,  90}, { 154,  90}, { 140,  90}, { 126,  90}, { 112,  90}, {  98,  90}, {  84,  90}, {  70,  90}, {  56,  90}, {  42,  90}, {  28,  90}, {  14,  90}, {   0,  90},
	{   0, 135}, {  14, 135}, {  28, 135}, {  42, 135}, {  56, 135}, {  70, 135}, {  84, 135}, {  98, 135}, { 112, 135}, { 126, 135}, { 140, 135}, { 154, 135}, { 168, 135},
	{ 192, 180},              { 168, 180}, { 154, 180}, { 140, 180}, { 126, 180}, { 112, 180}, {  98, 180}, {  84, 180}, {  70, 180}, {  56, 180}, {  42, 180}, {  28, 180},                           {  14, 180},
	{   0, 225}, {  14, 225}, {  28, 225},                                        {  84, 225},                           { 126, 225}, { 140, 225}, { 154, 225}, { 168, 225},              { 196,  45}, { 210,  45}, { 224,  90}
// "Stock" simple configuration
//	{ 224,   0}, { 210,   0}, { 196,   0}, { 182,   0}, { 168,   0}, { 154,   0}, { 140,   0}, { 126,   0}, { 112,   0}, {  98,   0}, {  84,   0}, {  70,   0}, {  56,   0},              {  28,   0}, {  14,   0}, {   0,   0},
//	{   0,  45}, {  14,  45}, {  28,  45}, {  42,  45}, {  56,  45}, {  70,  45}, {  84,  45}, {  98,  45}, { 112,  45}, { 126,  45}, { 140,  45}, { 154,  45}, { 168,  45}, { 182,  45}, { 196,  45}, { 210,  45}, { 224,  45},
//	{ 224,  90}, { 210,  90}, { 196,  90}, { 182,  90}, { 168,  90}, { 154,  90}, { 140,  90}, { 126,  90}, { 112,  90}, {  98,  90}, {  84,  90}, {  70,  90}, {  56,  90}, {  42,  90}, {  28,  90}, {  14,  90}, {   0,  90},
//	{   0, 135}, {  14, 135}, {  28, 135}, {  42, 135}, {  56, 135}, {  70, 135}, {  84, 135}, {  98, 135}, { 112, 135}, { 126, 135}, { 140, 135}, { 154, 135}, { 168, 135},
//	{ 224, 180},              { 196, 180}, { 182, 180}, { 168, 180}, { 154, 180}, { 140, 180}, { 126, 180}, { 112, 180}, {  98, 180}, {  84, 180}, {  70, 180}, {  56, 180},                           {  14, 180},
//	{   0, 225}, {  14, 225}, {  28, 225},                                        {  84, 225},                           { 126, 225}, { 140, 225}, { 154, 225}, { 168, 225},              { 196,  45}, { 210,  45}, { 224,  90}
}, {
	1          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          ,              4          , 4          , 4          ,
	4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 
	4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          ,
	4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 1          ,
	1                       , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 4          , 1                                    , 1          ,
	1          , 1          , 1          ,                                        4          ,                           1          , 1          , 1          , 1                       , 1          , 1          , 1          
} };


// PERSISTENT MEMORY (PMEM) CONFIGURATION ----------------------------------------------------------
// Declaring a type indicator_config that stores color and enabled state
typedef struct _indicator_config_t {
// H, S, V store the color values; func stores the function (caps lock, scroll, num, layer indication); index stores the RGB LED index; and enabled stores the enabled state
        uint8_t h;
        uint8_t s;
        uint8_t v;
        uint8_t func ;
        uint8_t index ;
        bool enabled;    
} indicator_config ;

// Number of properties of the "indicator" struct
#define INDICATOR_PROPERTY_NUMBER 5

/* List of functions:
    0x0000 CAPS LOCK
    0x0001 NUM LOCK
    0x0002 SCROLL LOCK
    0x0003 LAYER 0
    0x0004 LAYER 1
    0x0005 LAYER 2
    0x0006 LAYER 3
*/

// Declaring a keyboard_indicators type that stores the indicators states
#define INDICATOR_NUMBER 4

typedef struct _keyboard_indicators_t {
    indicator_config ind1 ;
    indicator_config ind2 ;
    indicator_config ind3 ;
    indicator_config ind4 ;
} keyboard_indicators ;

_Static_assert(sizeof(keyboard_indicators) == EECONFIG_KB_DATA_SIZE, "Mismatch in keyboard indicators stored data");

// Declaring a new variable indicators of the type keyboard_indicators
keyboard_indicators indicators;
uint8_t* pIndicators = (uint8_t*)&indicators ; // Gets a pointer to the first indicator

// This function returns the pointer to an indicator given an index
indicator_config* get_indicator_p (int index) {
    return (indicator_config*) (pIndicators + index) ;
}

// Initializing persistent memory configuration: default values are declared and stored in PMEM
void eeconfig_init_kb(void) {
    // Default values: all indicators start at white, 150 (roughly 60%) brightness value. Indicators 1 and 2 are active by default. Indicators 3 and 4 are disabled.
    // INDICATOR 1: CAPS LOCK
    indicators.ind1.h = 0;
    indicators.ind1.s = 0;
    indicators.ind1.v = 150;
    indicators.ind1.func = 0;
    indicators.ind1.index = 50;
    indicators.ind1.enabled = true;

    // INDICATOR 2: SCROLL LOCK
    indicators.ind2.h = 0;
    indicators.ind2.s = 0;
    indicators.ind2.v = 150;
    indicators.ind2.func = 1;
    indicators.ind2.index = 1;
    indicators.ind2.enabled = true;

    // INDICATOR 3: LAYER 1
    indicators.ind3.h = 0;
    indicators.ind3.s = 0;
    indicators.ind3.v = 150;
    indicators.ind3.func = 4;
    indicators.ind3.index = 81;
    indicators.ind3.enabled = false;

    // INDICATOR 4: LAYER 2
    indicators.ind4.h = 0;
    indicators.ind4.s = 0;
    indicators.ind4.v = 150;
    indicators.ind4.func = 5;
    indicators.ind4.index = 0;
    indicators.ind4.enabled = false;

    // Write default value to EEPROM now
    eeconfig_update_kb_datablock(&indicators);
}

// At the keyboard start, retrieves PMEM stored configs
void keyboard_post_init_kb(void) {
    debug_enable = true;
    debug_matrix = true;
    eeconfig_read_kb_datablock(&indicators);
    rgb_matrix_indicators_kb();
}

bool set_indicator(indicator_config indicator) {
    if (!indicator.enabled) return false;
    switch (indicator.func)
    {
        case 0: // If indicator is set as caps lock
        {
            if (host_keyboard_led_state().caps_lock) return true;
        }
        case 1: // If indicator is set as num lock
        {
            if (host_keyboard_led_state().num_lock) return true;
        }
        case 2: // If indicator is set as scroll lock
        {
            if (host_keyboard_led_state().scroll_lock) return true;
        }
        case 3: // If indicator is set as layer 0
        case 4:
        case 5:
        case 6:
        {
            if ( IS_LAYER_ON( (int)(indicator.func) - 3  ) ) return true;
        }
        default:
        {
            return false;
        }
    }
    return false;
}

HSV return_indicator_hsv (indicator_config indicator){
    return (HSV){indicator.h, indicator.s, indicator.v};
}

// INDICATOR CALLBACK ------------------------------------------------------------------------------
bool rgb_matrix_indicators_kb(void) {
    // First decides if action is needed. If a user code is defined, or the indicator is disabled, then does not act.
    if (!rgb_matrix_indicators_user()) return false;

    RGB rgb_current_indicator ;
    indicator_config* current_indicator_p ;
    int index ;

    for (index = 0 ; index < INDICATOR_NUMBER - 1 ; index++) {
        current_indicator_p = get_indicator_p(index) ;
        rgb_current_indicator = hsv_to_rgb(return_indicator_hsv( *(current_indicator_p) ));
        if (set_indicator( *(current_indicator_p)) ) rgb_matrix_set_color( current_indicator_p -> index, rgb_current_indicator.r, rgb_current_indicator.g, rgb_current_indicator.b);
        else rgb_matrix_set_color(current_indicator_p -> index, 0, 0, 0);
    }
 //   if (indicators.caps.enabled) {
 //       // The rgb_matrix_set_color function needs an RGB code to work, so first the indicator color is cast to an HSV value and then translated to RGB
 //       HSV hsv_caps_indicator_color = {indicators.caps.h, indicators.caps.s, indicators.caps.v};
 //       RGB rgb_caps_indicator_color = hsv_to_rgb(hsv_caps_indicator_color);
 //       if (host_keyboard_led_state().caps_lock) rgb_matrix_set_color(CAPS_INDICATOR_INDEX, rgb_caps_indicator_color.r, rgb_caps_indicator_color.g, rgb_caps_indicator_color.b);
 //       else rgb_matrix_set_color(CAPS_INDICATOR_INDEX, 0, 0, 0);
 //   } 
 //
 //   if (indicators.scroll.enabled) {
 //       HSV hsv_scroll_indicator_color = {indicators.scroll.h, indicators.scroll.s, indicators.scroll.v};
 //       RGB rgb_scroll_indicator_color = hsv_to_rgb(hsv_scroll_indicator_color);
 //       if (host_keyboard_led_state().scroll_lock) rgb_matrix_set_color(SCRL_INDICATOR_INDEX, rgb_scroll_indicator_color.r, rgb_scroll_indicator_color.g, rgb_scroll_indicator_color.b);
 //       else rgb_matrix_set_color(SCRL_INDICATOR_INDEX, 0, 0, 0);
 //   }
 //
 //   if (indicators.layer1.enabled) {
 //       HSV hsv_layer1_indicator_color = {indicators.layer1.h, indicators.layer1.s, indicators.layer1.v};
 //       RGB rgb_layer1_indicator_color = hsv_to_rgb(hsv_layer1_indicator_color);
 //       if (IS_LAYER_ON(1)) rgb_matrix_set_color(LAY1_INDICATOR_INDEX, rgb_layer1_indicator_color.r, rgb_layer1_indicator_color.g, rgb_layer1_indicator_color.b);
 //       else rgb_matrix_set_color(LAY1_INDICATOR_INDEX, 0, 0, 0);
 //   }
    return true;
}

// VIA CONFIGURATION -------------------------------------------------------------------------------
enum via_indicator_color {
    id_ind1_enabled = 1,
    id_ind1_brightness = 2,
    id_ind1_color = 3,
    id_ind1_func = 4,
    id_ind1_index = 5,
//
    id_ind2_enabled = 6,
    id_ind2_brightness = 7,
    id_ind2_color = 8,
    id_ind2_func = 9,
    id_ind2_index = 10,
//
    id_ind3_enabled = 11,
    id_ind3_brightness = 12,
    id_ind3_color = 13,
    id_ind3_func = 14,
    id_ind3_index = 15,
//
    id_ind4_enabled = 16,
    id_ind4_brightness = 17,
    id_ind4_color = 18,
    id_ind4_func = 19,
    id_ind4_index = 20
};

int indi_index;
int data_index;
void indicator_config_set_value( uint8_t *data )
{
    // data = [ value_id, value_data ]
    uint8_t *value_id;
    value_id = &(data[0]);
    uint8_t *value_data = &(data[1]);

    /* Suppose that the brightness value of indicator 3 is being changed; then

       index = (12-1)/5 = 2, which indeed relates to indicator 3 (ind1 is 0, ind2 is 1 etc)
       data_index = (12 - index*INDICATOR_PROPERTY_NUMBER) = 12 - 2*5 = 2, which indeed relates to a brightness setting (0 is for enabled, 1 for brightness, 2 for color and 3 for func)

       Therefore, the basic idea is that index is about which indicator the set_value is about, and data_index about what indicator property it is
    */
    indi_index = ( (int)(*value_id) - 1) / (int)INDICATOR_PROPERTY_NUMBER;
    data_index = (int)(*value_id) - indi_index*(int)INDICATOR_PROPERTY_NUMBER;
    uprintf("\nConfig seting %d: ", data_index);
    indicator_config* current_indicator_p = get_indicator_p(indi_index);
    switch ( data_index )
    {
        case 1 :
        {
                current_indicator_p -> enabled = value_data[0];
                uprintf("Indicator %d enabled to: %d", indi_index, value_data[0]);
                break;
        }
        case 2 :
        {
                current_indicator_p -> v = value_data[0];
                uprintf("Indicator %d brightness set to: %d", indi_index, value_data[0]);
                break;
        }
        case 3:
        {
                current_indicator_p -> h = value_data[0];
                current_indicator_p -> s = value_data[1];
                uprintf("Indicator %d color set to: %d,%d", indi_index, value_data[0], value_data[1]);
                break;
        }
        case 4:
        {
                current_indicator_p -> func = value_data[0];
                uprintf("Indicator %d function set to: %d", indi_index, value_data[0]);
                break;
        }
        case 5:
        {
                current_indicator_p -> index = value_data[0];
                uprintf("Indicator %d index set to: %d", indi_index, value_data[0]);
                break;
        }
    }
    uprintf("\n");
}


void indicator_config_get_value( uint8_t *data )
{
    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);

    indi_index = ( (int)(*value_id) - 1) / (int)INDICATOR_PROPERTY_NUMBER;
    data_index = (int)(*value_id) - indi_index* (int)INDICATOR_PROPERTY_NUMBER;
    uprintf("\nConfig received: %d ", data_index);
    indicator_config* current_indicator_p = get_indicator_p(indi_index);
    switch ( data_index )
    {
        case 1:
        {
            value_data[0] =  current_indicator_p -> enabled;
            break;
        }
        case 2:
        {

            value_data[0] = current_indicator_p -> v;
            break;
        }
        case 3:
        {

            value_data[0] = current_indicator_p -> h;
            value_data[1] = current_indicator_p -> s;
            break;
        }
        case 4:
        {

            value_data[0] = current_indicator_p -> func;
            break;
        }
        case 5:
        {

            value_data[0] = current_indicator_p -> index;
            break;
        }
    }
    uprintf("\n");
}

void indicator_config_save(void)
{
    eeconfig_update_kb_datablock(&indicators);
}

void via_custom_value_command_kb(uint8_t *data, uint8_t length) {
    // data = [ command_id, channel_id, value_id, value_data ]
    uint8_t *command_id        = &(data[0]);
    uint8_t *channel_id        = &(data[1]);
    uint8_t *value_id_and_data = &(data[2]);

    if ( *channel_id == id_custom_channel ) {
        switch ( *command_id )
        {
            case id_custom_set_value:
            {
                indicator_config_set_value(value_id_and_data);
                break;
            }
            case id_custom_get_value:
            {
                indicator_config_get_value(value_id_and_data);
                break;
            }
            case id_custom_save:
            {
                indicator_config_save();
                break;
            }
            default:
            {
                // Unhandled message.
                *command_id = id_unhandled;
                break;
            }
        }
        return;
    }

    *command_id = id_unhandled;
}
