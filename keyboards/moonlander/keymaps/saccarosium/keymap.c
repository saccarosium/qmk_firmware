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
    BASE,  // default layer
    FN,  // function keys
};

enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        KC_DOLLAR,KC_1,   KC_2,    KC_3,    KC_4,    KC_5,    _______,           _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
        KC_TAB,  KC_QUOTE,KC_COMM, KC_DOT,  KC_P,    KC_Y,    _______,           _______, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
        CTL_T(KC_ESC),KC_A,KC_O,   KC_E,    KC_U,    KC_I,    _______,           _______, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    CTL_T(KC_MINS),
        KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                                KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
        TT(FN),  _______, _______, KC_DOWN, KC_UP,            KC_LALT,           KC_RALT,          KC_LEFT, KC_RIGHT, _______, _______, TT(FN),
                                   KC_SPC,  LGUI_T(KC_ENT),   _______,           _______, KC_RGUI, KC_BSPC
    ),

    [FN] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______,           _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______,           _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,         _______,            _______,          _______, _______, _______, _______, _______,
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

const key_override_t _1   = ko_make_basic(MOD_MASK_SHIFT, KC_1,   KC_AMPR);
const key_override_t _2   = ko_make_basic(MOD_MASK_SHIFT, KC_2,   KC_LBRC);
const key_override_t _3   = ko_make_basic(MOD_MASK_SHIFT, KC_3,   KC_LCBR);
const key_override_t _4   = ko_make_basic(MOD_MASK_SHIFT, KC_4,   KC_LPRN);
const key_override_t _5   = ko_make_basic(MOD_MASK_SHIFT, KC_5,   KC_PLUS);
const key_override_t _6   = ko_make_basic(MOD_MASK_SHIFT, KC_6,   KC_EQL);
const key_override_t _7   = ko_make_basic(MOD_MASK_SHIFT, KC_7,   KC_RPRN);
const key_override_t _8   = ko_make_basic(MOD_MASK_SHIFT, KC_8,   KC_RCBR);
const key_override_t _9   = ko_make_basic(MOD_MASK_SHIFT, KC_9,   KC_RBRC);
const key_override_t _0   = ko_make_basic(MOD_MASK_SHIFT, KC_0,   KC_ASTR);
const key_override_t circ = ko_make_basic(MOD_MASK_SHIFT, KC_DOLLAR, KC_CIRC);
const key_override_t home = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT, KC_HOME);
const key_override_t end  = ko_make_basic(MOD_MASK_SHIFT, KC_RIGHT, KC_END);
const key_override_t at   = ko_make_basic(MOD_MASK_ALT,   KC_T, KC_AT);
const key_override_t percent   = ko_make_basic(MOD_MASK_ALT,   KC_P, KC_PERC);
const key_override_t bsls = ko_make_basic(MOD_MASK_ALT,   KC_SLSH, KC_BSLS);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &_1,
    &_2,
    &_3,
    &_4,
    &_5,
    &_6,
    &_7,
    &_8,
    &_9,
    &_0,
    &home,
    &end,
    &at,
    &bsls,
    &percent,
    &circ,

    NULL // Null terminate the array of overrides!
};
