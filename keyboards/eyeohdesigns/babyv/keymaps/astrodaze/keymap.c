/* Copyright 2020 Eye Oh! Designs
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    QWERTY,
    FUN,
    NUM,
    FKEY,
    GAME,
    NAV
};

// Left-hand home row mods
#define CTL_A LCTL_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define GUI_D LGUI_T(KC_D)
#define SFT_F LSFT_T(KC_F)

// Right-hand home row mods
#define SFT_J RSFT_T(KC_J)
#define GUI_K RGUI_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define CTL_SCLN RCTL_T(KC_SCLN)

#define SPC_FUN LT(FUN, KC_SPC)
#define BS_NUM LT(NUM, KC_BSPC)
#define ESC_NAV LT(NAV, KC_ESC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [QWERTY] = LAYOUT_1u(
        KC_TAB,  KC_Q,    KC_W,    KC_E,       KC_R,       KC_T,        KC_Y,    KC_U,       KC_I,       KC_O,     KC_P,     KC_BSPC,
        ESC_NAV,  CTL_A,   KC_S,    GUI_D,     SFT_F,       KC_G,        KC_H,    SFT_J,       GUI_K,     ALT_L,    CTL_SCLN,  KC_QUOT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,       KC_V,       KC_B,        KC_N,    KC_M,       KC_COMM,    KC_DOT,   KC_SLSH,  KC_RSPC,
        KC_ESC,                   KC_VOLD,   KC_BSPC,     BS_NUM,          SPC_FUN,  KC_ENT,   KC_VOLU,                        MO(NAV)
    ),
    [FUN] = LAYOUT_1u(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,          KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_DEL,
        KC_CAPS, KC_LPRN,  KC_RPRN,  KC_LCBR, KC_RCBR,  _______,        _______,  KC_UNDS,  KC_PLUS,    KC_LCBR,   KC_RCBR, KC_PIPE,
        KC_VOLD, KC_LBRC, KC_RBRC, RGB_SAI,    RGB_SAD,    KC_LBRC,     KC_RBRC, RGB_VAI,    RGB_VAD,    KC_DOT,   KC_BSLS,  KC_RSFT,
        RESET,                   RGB_MOD,    RGB_RMOD,    KC_TAB,      KC_SPC,  KC_TRNS,    RGB_TOG,                        KC_TRNS
    ),
    [NUM] = LAYOUT_1u(
        KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,       KC_8,       KC_9,      KC_0,      KC_DEL,
        KC_CAPS, _______,   _______,  KC_GRV,  KC_QUES,   KC_TILD,       _______, KC_MINS,    KC_EQL,     KC_LBRC, KC_RBRC,    KC_BSLS,
        KC_TRNS, _______, _______,   _______,  _______,   _______,         _______, _______,   _______,  _______,   _______,  KC_RSFT,
        KC_LCTL,                   KC_TRNS,    KC_TRNS,    KC_SPC,        KC_SPC,  KC_TRNS,    KC_TRNS,                        KC_TRNS
    ),
    [NAV] = LAYOUT_1u(
        KC_TILD,  KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,             _______, _______, _______,   _______,  _______,   _______,
        KC_CAPS, KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,                KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  KC_HOME,   KC_END,
        KC_TRNS, KC_F11, KC_F12,   _______,  _______,   _______,             _______, _______,   _______,  _______,   _______,  KC_RSFT,
        KC_LCTL,                   KC_TRNS,    KC_TRNS,    KC_SPC,        KC_SPC,  KC_TRNS,    KC_TRNS,                        TG(GAME)
    ),
    [GAME] = LAYOUT_1u(
        KC_TAB,  KC_Q,    KC_W,    KC_E,       KC_R,       KC_T,        KC_Y,    KC_U,       KC_I,       KC_O,     KC_P,     KC_BSPC,
        KC_LSFT,  KC_A,   KC_S,    KC_D,     KC_F,       KC_G,         KC_H,    SFT_J,       GUI_K,     ALT_L,    CTL_SCLN,  KC_QUOT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,       KC_V,       KC_B,        KC_N,    KC_M,       KC_COMM,    KC_DOT,   KC_SLSH,  KC_RSPC,
        KC_ESC,                   _______, KC_TAB,     KC_SPC,          SPC_FUN,  KC_ENT,   _______,                        TG(QWERTY)
    ),
};