/* Copyright 2020 Swiftrax
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#define _QWERTY 0
#include QMK_KEYBOARD_H
#define KC_BSLS KC_BSLASH
#define KC_DEL KC_DELETE
#define KC_PGDN KC_PGDOWN
#define KC_RGHT KC_RIGHT


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
		KC_F1, KC_F13, KC_ESC, 	KC_1, 	KC_2, 	KC_3, 	KC_4, 	KC_5, 	KC_6, 	KC_7, 	KC_8, 	KC_9, 	KC_0, 	 KC_MINS, 	KC_EQL, KC_GRV, KC_BSLASH, 
		KC_F2, KC_F14, KC_TAB, 	KC_Q, 	KC_W, 	KC_E, 	KC_R, 	KC_T, 	KC_Y, 	KC_U, 	KC_I, 	KC_O, 	KC_P, 	 KC_LBRC, 	KC_RBRC,KC_BSPC,KC_DELETE, 
		KC_F3, KC_F15, KC_LCTL, KC_A, 	KC_S, 	KC_D, 	KC_F, 	KC_G, 	KC_H, 	KC_J, 	KC_K, 	KC_L, 	KC_SCLN, KC_QUOT, 	KC_ENT, KC_LCAP,KC_PGUP, 
		KC_F4, KC_F16, KC_LSFT, KC_Z, 	KC_X, 	KC_C, 	KC_V, 	KC_B, 	KC_N, 	KC_M,   KC_COMM,KC_DOT, KC_SLSH, KC_NO, 	KC_UP, 			KC_PGDOWN, 
		KC_F5, KC_F17, KC_LCTL, KC_LALT, 				KC_SPC, 			KC_LALT, 	KC_RCTL, 				   KC_LEFT, KC_DOWN, KC_RIGHT), 

};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
};