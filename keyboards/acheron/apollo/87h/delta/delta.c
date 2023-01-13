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
        uint8_t h;
        uint8_t s;
        uint8_t v;
        bool enabled;    
} indicator_config ;

// Declaring a keyboard_indicators type that stores the indicators states
typedef struct _keyboard_indicators_t {
    indicator_config caps ;
    indicator_config scroll ;
    indicator_config layer1;
} keyboard_indicators ;

_Static_assert(sizeof(keyboard_indicators) == EECONFIG_KB_DATA_SIZE, "Mismatch in keyboard indicators stored data");

// Declaring a new variable indicators of the type keyboard_indicators
keyboard_indicators indicators;

// Initializing persistent memory configuration: default values are declared and stored in PMEM
void eeconfig_init_kb(void) {
    // Default values
    indicators.caps.h = 0;
    indicators.caps.s = 0;
    indicators.caps.v = 255;
    indicators.caps.enabled = true;

    indicators.scroll.h = 0;
    indicators.scroll.s = 0;
    indicators.scroll.v = 255;
    indicators.scroll.enabled = true;

    indicators.layer1.h = 0;
    indicators.layer1.s = 0;
    indicators.layer1.v = 255;
    indicators.layer1.enabled = true;

    // Write default value to EEPROM now
    eeconfig_update_kb_datablock(&indicators);
}

// At the keyboard start, retrieves PMEM stored configs
void keyboard_post_init_kb(void) {
    eeconfig_read_kb_datablock(&indicators);
    rgb_matrix_indicators_kb();
}

// INDICATOR CALLBACK ------------------------------------------------------------------------------
bool rgb_matrix_indicators_kb(void) {
    // First decides if action is needed. If a user code is defined, or the indicator is disabled, then does not act.
    if (!rgb_matrix_indicators_user()) {
        return false;
    }

    if (indicators.caps.enabled) {
        // The rgb_matrix_set_color function needs an RGB code to work, so first the indicator color is cast to an HSV value and then translated to RGB
        HSV hsv_caps_indicator_color = {indicators.caps.h, indicators.caps.s, indicators.caps.v};
        RGB rgb_caps_indicator_color = hsv_to_rgb(hsv_caps_indicator_color);
        if (host_keyboard_led_state().caps_lock) rgb_matrix_set_color(CAPS_INDICATOR_INDEX, rgb_caps_indicator_color.r, rgb_caps_indicator_color.g, rgb_caps_indicator_color.b);
        else rgb_matrix_set_color(CAPS_INDICATOR_INDEX, 0, 0, 0);
    } 

    if (indicators.scroll.enabled) {
        HSV hsv_scroll_indicator_color = {indicators.scroll.h, indicators.scroll.s, indicators.scroll.v};
        RGB rgb_scroll_indicator_color = hsv_to_rgb(hsv_scroll_indicator_color);
        if (host_keyboard_led_state().scroll_lock) rgb_matrix_set_color(SCRL_INDICATOR_INDEX, rgb_scroll_indicator_color.r, rgb_scroll_indicator_color.g, rgb_scroll_indicator_color.b);
        else rgb_matrix_set_color(SCRL_INDICATOR_INDEX, 0, 0, 0);
    }

    if (indicators.layer1.enabled) {
        HSV hsv_layer1_indicator_color = {indicators.layer1.h, indicators.layer1.s, indicators.layer1.v};
        RGB rgb_layer1_indicator_color = hsv_to_rgb(hsv_layer1_indicator_color);
        if (IS_LAYER_ON(1)) rgb_matrix_set_color(LAY1_INDICATOR_INDEX, rgb_layer1_indicator_color.r, rgb_layer1_indicator_color.g, rgb_layer1_indicator_color.b);
        else rgb_matrix_set_color(LAY1_INDICATOR_INDEX, 0, 0, 0);
    }
    return true;
}

// VIA CONFIGURATION -------------------------------------------------------------------------------
enum via_indicator_color {
    id_caps_indicator_enabled = 1,
    id_caps_indicator_brightness = 2,
    id_caps_indicator_color = 3,
//
    id_scroll_indicator_enabled = 4,
    id_scroll_indicator_brightness = 5,
    id_scroll_indicator_color = 6,
//
    id_layer1_indicator_enabled = 7,
    id_layer1_indicator_brightness = 8,
    id_layer1_indicator_color = 9,
};

void indicator_config_set_value( uint8_t *data )
{
    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);

    switch ( *value_id )
    {
        case id_caps_indicator_enabled:
        {
                indicators.caps.enabled = value_data[0];
                break;
        }
        case id_caps_indicator_brightness:
        {
                indicators.caps.v = value_data[0];
                break;
        }
        case id_caps_indicator_color:
        {
                indicators.caps.h = value_data[0];
                indicators.caps.s = value_data[1];
                break;
        }
//
        case id_scroll_indicator_enabled:
        {
                indicators.scroll.enabled = value_data[0];
                break;
        }
        case id_scroll_indicator_brightness:
        {
                indicators.scroll.v = value_data[0];
                break;
        }
        case id_scroll_indicator_color:
        {
                indicators.scroll.h = value_data[0];
                indicators.scroll.s = value_data[1];
                break;
        }
//
        case id_layer1_indicator_enabled:
        {
                indicators.layer1.enabled = value_data[0];
                break;
        }
        case id_layer1_indicator_brightness:
        {
                indicators.layer1.v = value_data[0];
                break;
        }
        case id_layer1_indicator_color:
        {
                indicators.layer1.h = value_data[0];
                indicators.layer1.s = value_data[1];
                break;
        }
    }
}

void indicator_config_get_value( uint8_t *data )
{
    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);

    switch ( *value_id )
    {
        case id_caps_indicator_enabled:
        {
            value_data[0] = indicators.caps.enabled;
            break;
        }
        case id_caps_indicator_brightness:
        {
            value_data[0] = indicators.caps.v;
            break;
        }
        case id_caps_indicator_color:
        {
            value_data[0] = indicators.caps.h;
            value_data[1] = indicators.caps.s;
            break;
        }
//
        case id_scroll_indicator_enabled:
        {
            value_data[0] = indicators.scroll.enabled;
            break;
        }
        case id_scroll_indicator_brightness:
        {
            value_data[0] = indicators.scroll.v;
            break;
        }
        case id_scroll_indicator_color:
        {
            value_data[0] = indicators.scroll.h;
            value_data[1] = indicators.scroll.s;
            break;
        }
//
        case id_layer1_indicator_enabled:
        {
            value_data[0] = indicators.layer1.enabled;
            break;
        }
        case id_layer1_indicator_brightness:
        {
            value_data[0] = indicators.layer1.v;
            break;
        }
        case id_layer1_indicator_color:
        {
            value_data[0] = indicators.layer1.h;
            value_data[1] = indicators.layer1.s;
            break;
        }
    }
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
