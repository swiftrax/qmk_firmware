
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN,
    _MEDIA };

// Tap Dance Declarations
enum {
    TD_SCAPS = 0
};

#define SCAPS_LG TD(TD_SCAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_DEL,   KC_DEL,      \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,     KC_END,    \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                 KC_HOME, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        MO(_MEDIA),   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,        KC_UP,           \
    KC_LCTL, KC_LGUI,  KC_LALT,         KC_SPC,                         KC_SPC,           KC_RGUI, KC_RCTL,  MO(_FN),        KC_LEFT, KC_DOWN, KC_RGHT    \
  ),

  [_FN] = LAYOUT(
     KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,  _______,     _______,      \
    _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,               _______,     \
    _______, RGB_MOD, RGB_HUI, RGB_SAI,  RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______,                         _______,    \
    _______, RGB_TOG, RGB_HUD, RGB_SAD,  RGB_VAD, _______, _______, _______, _______, _______, _______, _______,  _______,                   KC_PGUP,         \
    _______, _______, _______,           _______, _______,          _______,          _______,          _______,                    KC_HOME, KC_PGDN, KC_END  \
  ),

  [_MEDIA] = LAYOUT(
     KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,  _______,     _______,      \
    _______, _______, _______, _______,    RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______,               _______,     \
    _______, RGB_MOD, RGB_HUI, RGB_SAI,  RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______,                         _______,    \
    _______, RGB_TOG, RGB_HUD, RGB_SAD,  RGB_VAD, _______, _______, _______, _______, _______, _______, _______,  _______,                   KC_PGUP,         \
    _______, _______, _______,           _______, _______,          _______,          _______,          _______,                    KC_HOME, KC_PGDN, KC_END  \
  )
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code16(KC_MNXT);
        } else {
            tap_code16(KC_MPRV);
        }
     } else if (index == 2) { /* Third encoder */
        if (clockwise) {
            tap_code(KC_RGHT);
        } else {
            tap_code(KC_LEFT);
        }
    }
}

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for
    [TD_SCAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};
