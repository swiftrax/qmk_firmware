#include QMK_KEYBOARD_H

enum custom_keycodes { //KEYCODES
	TEXT1 = SAFE_RANGE,
	TEXT2,
	TEXT3,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case TEXT1:
        if (record->event.pressed) {
            SEND_STRING("HI!");
        } else {
        }
        break;

    case TEXT2:
        if (record->event.pressed) {
            SEND_STRING("How are you?");
        } else {
        }
        break;

    case TEXT3:
        if (record->event.pressed) {
           SEND_STRING("<3");
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
	KC_F13,	    KC_F14,   	KC_F15,   KC_F16,  TEXT1,
	KC_F18,  	KC_F19,  	KC_F20,   KC_F21,  TEXT2,
	KC_F22,  	KC_F23,  	KC_F24,   KC_MUTE,
	KC_VOLD,  	KC_MPRV,	KC_MNXT,  KC_VOLU,    TEXT3),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { //Top Encoder
        if (clockwise) {
            tap_code(KC_RBRC); //BRUSH SIZE INCREASE
        } else {
            tap_code(KC_LBRC); //BRUSH SIZE DECREASE
        }
    }
    else if (index == 1) { //Middle Encoder
        if (clockwise) {
            tap_code16(C(KC_EQL)); //CTRL +
        } else {
            tap_code16(C(KC_MINS)); //CTRL -
        }
    }
    else if (index == 2) { //Bottom Encoder
        if (clockwise) {
            tap_code16(A(KC_WH_U)); //ALT WHEEL UP
        } else {
            tap_code16(A(KC_WH_D)); //ALT WHEEL DOWN
        }
    }
}
