
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
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,        KC_PGUP,          \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,      KC_PGUP,    \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,               KC_PGUP,      \
    KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,    MO(_MEDIA),  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,                     \
    KC_LCTL, KC_LGUI,  KC_LALT,         KC_SPC,                         KC_BSPC,           KC_RGUI, KC_RCTL,  MO(_FN),        KC_LEFT, KC_DOWN, KC_RGHT           \
  ),

  [_FN] = LAYOUT(
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______,                   KC_PGUP,              \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     KC_PGUP,      \
    _______, RGB_MOD,  RGB_HUI, RGB_SAI,  RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______,            KC_PGUP,       \
    _______, RGB_TOG, RGB_HUD, RGB_SAD,  RGB_VAD, _______, _______, _______, _______, _______, _______, _______,  _______,          KC_PGUP,                   \
    _______, _______, _______,          _______, _______,          _______,          _______,          _______,           KC_HOME, KC_PGDN, KC_END           \
  ),

  [_MEDIA] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,  KC_PGUP,\
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    KC_PGUP,        \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY,               KC_PGUP,    \
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,          KC_VOLU,                   \
    _______, _______, _______,          _______, _______,          _______,          _______,          _______, KC_MPRV, KC_VOLD, KC_MNXT           \
  )
};

void matrix_init_user(void) {
  // set CapsLock LED to output and off (active low)
  setPinOutput(F5);
  writePinHigh(F5);
  // set NumLock LED to output and off (active low)
  setPinOutput(F6);
  writePinHigh(F6);
  // set ScrollLock LED to output and off (active low)
  setPinOutput(F7);
  writePinHigh(F7);
}

// write to above indicators in a binary fashion based on current layer
layer_state_t layer_state_set_user(layer_state_t state)
{
    writePin(F5, (state & 0x1));
    writePin(F6, (state & 0x2));
    writePin(F7, (state & 0x4));
    return state;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
     } else if (index == 2) { /* Third encoder */
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
}

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for
    [TD_SCAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};
