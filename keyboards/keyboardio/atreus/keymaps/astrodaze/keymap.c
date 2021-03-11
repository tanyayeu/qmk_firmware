// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

enum layer_names {
    _QW,
    _NUM,
    _FUN,
    _SYMBOL
};

//tap dances
enum tap_dances {
  TD_GUI_CAPS,
  TD_Q_TAB,
  TD_A_TAB
};

// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_GUI_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_CAPS),   // tap once for shift, twice for caps
  [TD_Q_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_TAB), //TAP FOR Q, DT FOR TAB
  [TD_A_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_TAB), //TAP FOR A, DT FOR TAB
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    TD(TD_Q_TAB),    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    ,
    TD(TD_A_TAB),    KC_S,    KC_D,    KC_F,    KC_G,                                  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN ,
    LSFT_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,    KC_GRV,            KC_BSLS, KC_N,    KC_M,    KC_COMM, KC_DOT,  RSFT_T(KC_SLSH),
    KC_ESC, KC_TAB, KC_RALT,  LT(_NUM, KC_BSPC),TD(TD_GUI_CAPS),  KC_LCPO,   KC_RCPC, LT(_SYMBOL,KC_SPC),  LT(_FUN,KC_ENT), KC_MINS, KC_QUOT, KC_ENT ),

  /*
   *  !       @     up     {    }        ||     pgup    7     8     9    *
   *  #     left   down  right  $        ||     pgdn    4     5     6    +
   *  [       ]      (     )    &        ||       `     1     2     3    \
   * lower  insert super shift bksp ctrl || alt space   fn    .     0    =
   */
  [_NUM] = LAYOUT( /* [> RAISE <] */
    KC_1, KC_2,   KC_3,   KC_4,  KC_5,                            KC_6, KC_7,    KC_8,   KC_9, KC_0,
    KC_LPRN, KC_LEFT, KC_DOWN, KC_QUES, KC_RPRN,                  KC_LEFT, KC_DOWN,  KC_UP, KC_RGHT, KC_QUOT,
    KC_LBRC, KC_RBRC, KC_HASH, KC_LCBR, KC_RCBR, KC_CIRC, KC_AMPR,KC_ASTR, KC_1,    KC_2,   KC_3, KC_PLUS,
    KC_TILD, KC_INS,  KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT,KC_SPC,  KC_TRNS, KC_DOT, KC_0, KC_EQL ),
  /*
   * insert home   up  end   pgup       ||      up     F7    F8    F9   F10
   *  del   left  down right pgdn       ||     down    F4    F5    F6   F11
   *       volup             reset      ||             F1    F2    F3   F12
   *       voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause
   */
  [_FUN] = LAYOUT( /* [> LOWER <] */
    KC_LPRN,  KC_RPRN, KC_LT,   KC_GT,  _______,                   KC_UP,   KC_F7,   KC_F8,   KC_MINS,   KC_EQL  ,
    KC_LBRC,  KC_RBRC, KC_LCBR, KC_RCBR, _______,                   KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_DQUO  ,
    KC_NO,   KC_VOLU, KC_NO,   KC_NO,   RESET,   _______, _______, KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
    KC_NO,   KC_VOLD, KC_LGUI, KC_DEL, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  _______, KC_PSCR, KC_SLCK, KC_PAUS ),

  [_SYMBOL] = LAYOUT( /* [> LOWER <] */
    KC_EXLM,  KC_AT, KC_HASH,   KC_DLR,  KC_PERC,                   KC_CIRC,   KC_AMPR,   KC_ASTR,   KC_UNDS,   KC_PLUS ,
    KC_LBRC,  KC_RBRC, KC_LCBR, KC_RCBR, KC_DQUO,                   _______, KC_F4,   KC_F5,   KC_MINS,   KC_EQL  ,
    KC_NO,   KC_VOLU, KC_NO,   KC_NO,   RESET,   _______, _______, KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
    KC_NO,   KC_VOLD, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  _______, KC_PSCR, KC_SLCK, KC_PAUS )
};
