/* Copyright 2020 ademey "MsMustard"
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

/* Ortho layout with 2x 2u spacebars
 * Default ortho layout.
 * make terrazzo:othro
 */
#include QMK_KEYBOARD_H

enum layers {
	_QWERTY,
	_RAISE,
	_LOWER,
	_NAV,
	_FN
};

#define CTL_A LCTL_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define GUI_D LGUI_T(KC_D)
#define SFT_F LSFT_T(KC_F)
#define CTL_Z LCTL_T(KC_Z)

// Right-hand home row mods
#define SFT_J RSFT_T(KC_J)
#define GUI_K RGUI_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define CTL_SCLN RCTL_T(KC_SCLN)
#define CTL_Z LCTL_T(KC_Z)

#define LOWERSP LT(_LOWER, KC_BSPC)
#define RAISESP LT(_RAISE, KC_SPC)
#define NAVENT LT(_NAV,KC_ENT)
#define NAVTAB LT(_NAV, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_ortho(
		KC_MUTE, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  _______,  _______,   KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,
	    TZ_NXT,  KC_A,    KC_S,    KC_D,    SFT_F,    KC_G, _______,  _______,   KC_H,    SFT_J,   GUI_K,   ALT_L,   CTL_SCLN,
	    TZ_PRV,  CTL_Z,    KC_X,    KC_C,    KC_V,    KC_B,  _______,  _______,   KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, 
	    TZ_NXT,           KC_ESC,  KC_LGUI, LOWERSP,  LT(_NAV,KC_TAB),    NAVENT,   RAISESP, MO(_FN), KC_DEL
  ),

  [_RAISE] = LAYOUT_ortho(
      _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_EQL,
	    _______, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, KC_EQL,  _______, KC_BSLS, KC_PIPE,
	    _______, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, 
	    _______,          _______, _______, _______,      _______,     _______,     _______, _______, _______
  ),

  [_LOWER] = LAYOUT_ortho(
      _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,    _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
	    _______, KC_CAPS, XXXXXXX, KC_TILD, KC_QUES, KC_GRV, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_MINS,  KC_QUOT,
	    _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, 
	    _______,          _______, _______, _______,      _______,          _______,     KC_VOLD, KC_VOLU, KC_MPLY
  ),

  [_NAV] = LAYOUT_ortho(
      _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_UNDS, _______,
	    _______, KC_MPRV, KC_MNXT, KC_MPLY, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_HOME,
	    _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______, KC_END, 
	    TZ_OFF,          RESET, _______, _______,      _______,          _______,     _______, _______,  _______
  ),

  [_FN] = LAYOUT_ortho(
		  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
		  _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11,  KC_F12,  _______, _______, 
		  _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, CG_TOGG, 
		  _______,          RESET,   _______, _______,      _______,          _______,     _______, _______, _______
  )
};
/*
void encoder_update_user(uint8_t index, bool clockwise) {
    terrazzo_scroll_pixel(clockwise);
    switch(get_highest_layer(layer_state)) {
        case _NAV:
            // Change volume when on nav layer
            clockwise ? tap_code(KC_AUDIO_VOL_UP) : tap_code(KC_AUDIO_VOL_DOWN);
            break;
        default:
            // Default encoder behavior of Page Up and Down
            clockwise ? tap_code(KC_PGDN) : tap_code(KC_PGUP);
            break;
    }   
}*/
void encoder_update_user(uint8_t index, bool clockwise) {
    terrazzo_scroll_pixel(clockwise);
    switch(index) {
      case 0:
        clockwise ? tap_code(KC_AUDIO_VOL_UP) : tap_code(KC_AUDIO_VOL_DOWN);
        break; 
      case 1:
        clockwise ? tap_code(KC_PGDN) : tap_code(KC_PGUP);
        break;       
      case 2:
        clockwise ? tap_code(KC_AUDIO_VOL_UP) : tap_code(KC_AUDIO_VOL_DOWN);
        break; 
    }
}
