/* Copyright 2018 Carlos Filoteo
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

enum layer_names {
  _DEFAULT,
  _NUM,
  _SYM,
  _OTHER, 
  _GAME 
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

#define NUM MO(_NUM)
#define SYM_ENT LT(_SYM, KC_ENT)
#define NUM_BS LT(_NUM, KC_BSPC)
#define SPC_OTHER LT(_OTHER, KC_SPC)




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base Layer
   * ,-------------------------------------------------------------------------.
   * | Esc |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |Bspace |
   * |-------------------------------------------------------------------------+
   * |Tab/L3|  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |   '  |
   * |-------------------------------------------------------------------------+
   * | Shift |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |Sh/En|
   * |-------------------------------------------------------------------------+
   * | Ctrl| Alt | Gui | App |  L2  |   Space   |  L1  | Left| Down|  Up |Right|
   * `-------------------------------------------------------------------------'
   */

[_DEFAULT] = LAYOUT(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  LT(_OTHER,KC_ESC), KC_A,    KC_S,    KC_D,    SFT_F,    KC_G,    KC_H,    SFT_J,  GUI_K,    ALT_L,  CTL_SCLN, KC_QUOT,
  KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
  KC_ESC, KC_LCTL, KC_LALT, KC_LGUI,  NUM_BS,     SPC_OTHER,    SYM_ENT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

  /* FN Layer 1
   * ,-------------------------------------------------------------------------.
   * | ` ~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  | Delete|
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     |  -  |  =  |  [  |  ]  |  \   |
   * |-------------------------------------------------------------------------+
   * |       | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |Capsl|      |          |       | Home| PgDn| PgUp| End |
   * `-------------------------------------------------------------------------'
   */

[_NUM] = LAYOUT( 
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_CAPS, RGB_TOG, RGB_MOD, RGB_VAI, KC_QUES, _______, _______, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
  _______, _______,  _______,  _______,  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,
  RESET, _______, _______, _______, _______,     _______,      _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

  /* FN Layer 2
   * ,-------------------------------------------------------------------------.
   * |   ~  |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  |Delete|
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     |  _  |  +  |  { |  }  |   |   |
   * |-------------------------------------------------------------------------+
   * |       | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |Capsl|      |          |       | Home| PgDn| PgUp| End |
   * `-------------------------------------------------------------------------'
   */

[_SYM] = LAYOUT( 
  KC_TILDE,  KC_EXLM,  KC_AT,  KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  KC_CAPS, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  _______, KC_LBRC, KC_RBRC, _______, _______, _______, _______, _______, _______, _______,_______,  KC_HOME,
  RESET, _______, _______, _______, _______,     _______,      _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

  /* FN Layer 2
   * ,-------------------------------------------------------------------------.
   * | Esc | Calc|Webhm| Mail| Comp|     |     |     |     |     |PrtSc|       |
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     |     |     |     |     |      |
   * |-------------------------------------------------------------------------+
   * |       |    |     |     |     |     |     |     |     |     |     |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |     |      |          |       |MousL|MousD|MousU|MousR|
   * `-------------------------------------------------------------------------'
   */

[_OTHER] = LAYOUT( /* Tab */
  KC_ESC,  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _______, _______, _______, _______, KC_PSCR, _______,
  _______, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_BSLS,
  _______, KC_F11, KC_F12, _______, _______, _______, _______, _______, _______, _______, RGB_MOD, RGB_TOG,
  _______, _______, _______, _______, _______,     _______,      _______, _______, _______,  TO(_GAME)
),

[_GAME] = LAYOUT(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    SFT_J,  GUI_K,    ALT_L,  CTL_SCLN, KC_QUOT,
  KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
  KC_ESC, KC_LALT, KC_LGUI, KC_LGUI,  NUM_BS,      KC_SPC,    SYM_ENT,  KC_LEFT, KC_DOWN, KC_UP,   TO(_DEFAULT)
),
};
