#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x7161
#define PRODUCT_ID      0x6352
#define DEVICE_VER      0x0001
#define MANUFACTURER    github.com/swiftrax
#define PRODUCT         Macro Champ
#define DESCRIPTION     Macro Pad

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 5

/* key matrix pins */
#define MATRIX_ROW_PINS { F4, B1, D4, B5}
#define MATRIX_COL_PINS { B3, C6, D7, E6, B2 }
#define UNUSED_PINS

#define ENCODERS_PAD_A { F6, F6, F6 }
#define ENCODERS_PAD_B { F7, B6, B4 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */

#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 3
#endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS


#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 0
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#endif

#endif