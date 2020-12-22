/* Copyright 2019 Evy Dekkers
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

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _MA 0 //Main layer
#define _LO 1 //Low
#define _HI 2 //High

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | knob |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ESC  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_MA] = LAYOUT_ortho_4x12(
  KC_MUTE,  KC_Q,    KC_W,    KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
  MT(MOD_LSFT, KC_TAB),   KC_A,    KC_S,    KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,    KC_X,    KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  MT(MOD_LSFT, KC_ENT),
  KC_GESC,  KC_RCTL, KC_RALT, KC_LGUI,  MO(_LO),  KC_SPC,   KC_SPC,   MO(_HI),  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT),


[_LO] = LAYOUT_ortho_4x12(
  RESET,    KC_1,       KC_2,    KC_3,       KC_4,       KC_5,    KC_6,    KC_MINS,    KC_8,    KC_MINS,   KC_PLUS,   KC_DEL,
  KC_CAPS,  KC_4,      KC_5,      KC_6,      _______,    _______,     KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_EQL,  KC_BSLS,
  KC_CAPS,  KC_7,      KC_8,  KC_9,  LCTL(KC_V),  _______,  _______,  KC_QUOT,  KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_ENT,
  KC_GRV,  _______,   KC_0,     _______,     _______,     _______,  _______,  _______,  KC_MNXT,  KC_VOLD,  KC_VOLU,  KC_MPLY),

[_HI] = LAYOUT_ortho_4x12(
  RESET,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,   KC_DEL,
  KC_CAPS,  LCTL(KC_A),  LCTL(KC_S),  _______,     LCTL(KC_F),  _______,  _______,  KC_LBRC,  KC_RBRC,  _______, _______,  KC_HOME,
  KC_CAPS,  LCTL(KC_Z),  LCTL(KC_X),  LCTL(KC_C),  LCTL(KC_V),  _______,  _______,  _______,  KC_VOLD,  KC_VOLU,  KC_MPLY,   KC_END,
  KC_GRV,  _______,     _______,     _______,     _______,     _______,  _______,  _______,  _______,  _______,  _______,   _______),

};

//#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}
//#endif