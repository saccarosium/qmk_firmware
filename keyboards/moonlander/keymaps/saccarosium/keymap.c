/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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

#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BAS,  // default layer
    HIG, // symbols layer
    LOW,  // extended layer
};

enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BAS] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        KC_TAB,  KC_QUOTE,KC_COMM, KC_DOT,  KC_P,    KC_Y,    _______,           _______, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
        KC_ESC,  KC_A,    KC_O,    ALT_T(KC_E),GUI_T(KC_U), KC_I,_______,        _______, KC_D,    GUI_T(KC_H),RALT_T(KC_T),  KC_N,    KC_S,    KC_MINS,
        KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                                KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                    KC_SPC, LT(HIG,KC_ENTER), _______,           _______, TT(LOW), CTL_T(KC_BSPC)
    ),

    [HIG] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,           _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______,           _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______,
        _______, KC_F1,   KC_VOLD, KC_MUTE, KC_VOLU, _______,                             _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_F12,  _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [LOW] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, KC_EXLM, KC_RCBR, KC_RBRC, KC_RPRN, KC_GRV,  _______,           _______, KC_PERC, KC_TILD, KC_PIPE, KC_HASH, KC_DLR,  _______,
        _______, KC_AT,   KC_LCBR, KC_LBRC, KC_LPRN, KC_AMPR, _______,           _______, KC_CIRC, KC_EQL,  KC_PLUS, KC_ASTR, KC_BSLS, _______,
        _______, _______, _______, KC_DOWN, KC_UP,   _______,                             _______, KC_RGHT, KC_LEFT, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
}
