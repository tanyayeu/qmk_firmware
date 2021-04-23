// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

enum layer_names {
    _QW,
    _NUM,
    _FUN,
    _SYMBOL,
    _OTHER
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
//tap dances
enum tap_dances {
  TD_GUI_CAPS,
  TD_Q_TAB,
  TD_A_TAB,
  TD_Z_PRN,
  TD_LBRC_LCBR,
};

// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_GUI_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_CAPS),   // tap once for shift, twice for caps
  [TD_Q_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_TAB), //TAP FOR Q, DT FOR TAB
  [TD_A_TAB] = ACTION_TAP_DANCE_DOUBLE(CTL_A, KC_CAPS), //TAP FOR A, DT FOR TAB,
  [TD_Z_PRN] = ACTION_TAP_DANCE_DOUBLE(KC_Z, KC_LPRN),
  [TD_LBRC_LCBR] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    ,
    CTL_A,    ALT_S,    GUI_D, SFT_F,    KC_G,                                        KC_H,    SFT_J,   GUI_K,   ALT_L,   CTL_SCLN,
    LT(_OTHER, KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,    KC_GRV,                        KC_BSLS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    KC_ESC, KC_RALT, KC_LGUI,  LT(_FUN,KC_BSPC), LT(_NUM,KC_BSPC),  LT(_FUN,KC_TAB),     LT(_SYMBOL,KC_ENT), LT(_SYMBOL,KC_SPC),  LT(_FUN,KC_ENT), _______, KC_DEL, KC_ENT ),

  [_NUM] = LAYOUT( 
    KC_1, KC_2,   KC_3,   KC_4,  KC_5,                            KC_6, KC_7,    KC_8,   KC_9, KC_0,
    KC_LPRN, KC_RPRN, KC_TILD, KC_QUES, KC_GRV,                  KC_LEFT, KC_DOWN,  KC_UP, KC_RGHT, KC_QUOT,
    KC_LCBR, KC_RCBR, _______, _______, _______, _______,     _______,_______, _______,    _______,   _______, _______,
    KC_TILD, _______,  _______, _______, _______, KC_GRV,     KC_TILD, KC_SPC,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ),

  [_FUN] = LAYOUT( 
    _______,  _______, _______,   _______,  _______,                   KC_LBRC,   KC_RBRC,   _______,   KC_UNDS,   KC_EQL ,
    KC_CAPS,  _______, _______, KC_QUES, _______,                   _______, _______,   _______,   _______,   KC_DQUO  ,
    _______,   _______, _______,   _______,   _______,          _______, _______, _______,   _______,   _______,   _______,   _______  ,
    _______,  _______, _______, _______, _______, _______,      _______, _______,  KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY ),

  [_SYMBOL] = LAYOUT( 
    KC_EXLM,  KC_AT, KC_HASH,   KC_DLR,  KC_PERC,                                     KC_CIRC,   KC_AMPR,   KC_ASTR,   KC_UNDS,   KC_PLUS ,
    KC_CAPS,  _______, _______, _______, _______,                          _______, _______,   _______,   KC_BSLS,   KC_PIPE  ,
    _______,   _______, _______,   _______,   _______,   _______,          _______, _______,   _______,   _______,   _______,   _______  ,
    KC_TRNS,     _______, _______, _______, _______, _______,                 _______, _______,  _______, _______, _______, _______ ),


    [_OTHER] = LAYOUT( 
    _______,  _______, _______,   _______,  _______,                                     KC_LBRC,   KC_RBRC,   _______,   KC_UNDS,   KC_PIPE ,
    _______,  _______, _______, _______, _______,                                       _______, _______,   _______,   KC_MINS,   KC_BSLS  ,
    _______,   _______, _______,   _______,   _______,   _______,              _______, _______,   _______,   _______,   _______,   _______  ,
    _______,     _______, _______, _______, _______, _______,                 _______, _______,  _______, _______, _______, _______ )
};  
