#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x7161
#define PRODUCT_ID      0x6999
#define DEVICE_VER      0x0001
#define MANUFACTURER    Swiftrax
#define PRODUCT         Trifecta
#define DESCRIPTION     Alice like keyboard with arrow keys and support for rotary encoders

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

/* key matrix pins */

#define MATRIX_ROW_PINS { B0, B7, F7, C6, B6 }
#define MATRIX_COL_PINS { F0, F1, F4, F5, F6, C7, B5, B3, B2, B1, D5, D3, D2, D1, D0}


#define ENCODERS_PAD_A { D4, D6, D7 }
#define ENCODERS_PAD_B { B4, B4, B4 }
#define ENCODER_RESOLUTION 4

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

#define RGB_DI_PIN E6
#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 7
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/*EEPROM for via*/
#define DYNAMIC_KEYMAP_LAYER_COUNT 3