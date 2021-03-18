/* Copyright 2019 gtips
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
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _SYM
};

enum tap_dances {
  TD_QUO_RPRN,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_QUO_RPRN] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_RPRN), //TAP FOR QUOTE, DT FOR RIGHT PRN
};

// Layer names
#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define SYM    MO(_SYM)

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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung39(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    KC_LSPO,  CTL_A,    ALT_S,    GUI_D,    SFT_F,      KC_G,              KC_H,     SFT_J,    GUI_K,    ALT_L,    CTL_SCLN,   TD(TD_QUO_RPRN),
    MT(MOD_LCTL, KC_LBRC),  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  RSFT_T(KC_ENT),
                                                       LT(RAISE, KC_BSPC),    LT(SYM, KC_SPC),   LT(LOWER, KC_ENT)
  ),
  
  [_LOWER] = LAYOUT_reviung39(
    KC_GESC,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,    KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL,
    KC_CAPS,  KC_RBRC,  KC_LBRC,  KC_RCBR,  KC_LCBR,   KC_PIPE,            KC_LEFT,  KC_LEFT,  KC_UP,    KC_RGHT,  KC_GRV,   KC_BSLS,
    KC_LCBR,  _______,   KC_LGUI,  KC_LALT,  _______,   _______,            KC_HOME,  KC_END,   KC_PGUP,  KC_PGDN,  KC_PSCR,  KC_ENT,
                                                       ADJUST,  SYM,   _______
  ),
  
  [_RAISE] = LAYOUT_reviung39(
    KC_TILD,  KC_1,     KC_2,     KC_3,     KC_4,      KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
    KC_CAPS,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_QUES,   KC_BSLS,            KC_LEFT,    KC_DOWN,    KC_UP,    KC_RGHT,    KC_F5,    KC_F6,
    _______,  KC_ESC,   KC_RGUI,  KC_RALT,  KC_CAPS,   KC_QUOT,            KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
                                                       _______,  SYM,  ADJUST
  ),
  
  [_ADJUST] = LAYOUT_reviung39(
    RESET,   RGB_SAI, RGB_HUI,  RGB_MOD,  XXXXXXX,   RGB_TOG,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, XXXXXXX,   XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            RESET,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                                       _______,  XXXXXXX,  _______
  ),

  [_SYM] = LAYOUT_reviung39(
    RESET,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            KC_LBRC,  KC_RBRC,  XXXXXXX,  KC_UNDS,  KC_PLUS,  XXXXXXX,
    XXXXXXX,   KC_LBRC, KC_RBRC,  KC_LBRC, KC_RBRC,   XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MINS,  KC_EQL,  XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                                       _______,  XXXXXXX,  _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
