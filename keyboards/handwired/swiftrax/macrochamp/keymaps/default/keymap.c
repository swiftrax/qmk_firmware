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
	KC_SLSH,	KC_W,  		KC_V,  	  KC_DEL,  TEXT1,
	KC_BSPC,  	KC_B,  		KC_E,  	  KC_Z,    TEXT2,
	KC_LSFT,  	KC_L,  		KC_G,  	  KC_D,
	KC_LCTL,  	KC_LALT,	KC_SPC,   KC_H,    TEXT3),
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
