/* Copyright 2015-2017 Jack Humbert
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


enum planck_layers {
  _QWERTY,
  _NUM,
  _SYM,
  _OTHER,
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
/*
enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,n
  DVORAK,
  BACKLIT,
  EXT_PLV
}*/


#define NUM_BSPC LT(_NUM,KC_BSPC)
#define SYM_SPC LT(_SYM,KC_SPC)
#define TAB_OTHER LT(_OTHER,KC_TAB)
#define OTHER MO(_OTHER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MUTE,             KC_MUTE,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    SFT_F,    KC_G,    KC_VOLD,            KC_VOLU,    KC_H,    SFT_J,   GUI_K,   ALT_L,   CTL_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,             _______,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    KC_ESC, KC_LCTL, KC_LGUI, OTHER, NUM_BSPC,   TAB_OTHER,             KC_ENT,  SYM_SPC,   KC_ENT, KC_DOWN, KC_UP,   KC_DEL
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_SYM] = LAYOUT_planck_grid(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  _______, _______, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN,
    KC_LPRN,  KC_RPRN,  KC_LCBR, KC_RCBR,   _______, _______, _______,   KC_MINS,    KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    KC_LBRC, KC_RBRC,   _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,
    RESET, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,   KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_NUM] = LAYOUT_planck_grid(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,    _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_CAPS, _______, KC_GRV, KC_QUES, KC_TILD, _______, _______, KC_LEFT, KC_DOWN,  KC_UP, KC_RGHT, KC_QUOT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),



[_OTHER] = LAYOUT_planck_grid(
    KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5, _______, _______,  _______, _______, _______, KC_UNDS,  KC_EQL,
    KC_F11, KC_F12, _______, _______, _______, _______, _______, _______, _______,  _______, KC_MINS, KC_HOME,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, KC_END,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

/*ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { 
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}
#endif
*/


void encoder_update_user(uint8_t index, bool clockwise) {
    switch(index) {
      case 0:
        clockwise ? tap_code(KC_AUDIO_VOL_DOWN) : tap_code(KC_AUDIO_VOL_UP);
        break; 
      case 1:
        clockwise ? tap_code(KC_PGUP) : tap_code(KC_PGDOWN);
        break;       
      case 2:
        clockwise ? tap_code(KC_AUDIO_VOL_DOWN) : tap_code(KC_AUDIO_VOL_UP);
        break; 
    }
}
