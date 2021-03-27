// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

enum layer_names {
    _QW,
    _NAV,
    _NUM,
    _SYM,
    _FUN
};

#define NAV MO(_NAV)

// Left-hand home row mods
#define CTL_A LCTL_T(KC_A)
#define ALT_R LALT_T(KC_R)
#define GUI_S LGUI_T(KC_S)
#define SHFT_T LSFT_T(KC_T)

// Right-hand home row mods
#define SFT_N RSFT_T(KC_N)
#define GUI_E RGUI_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define CTL_O RCTL_T(KC_O)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT    ,
    CTL_A, ALT_R, GUI_S, SHFT_T, KC_G,                                KC_M, SFT_N, GUI_E, ALT_I, CTL_O,
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______,     _______, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH ,
    KC_ESC, _______, _______,  KC_ESC, LT(_NAV,KC_BSPC),  KC_TAB,  LT(_SYM,KC_ENT), LT(_NUM,KC_SPC),  LT(_FUN,KC_DEL), _______, _______, KC_ENT ),


  [_NAV] = LAYOUT( //NAVIGATION
    _______, _______, _______, _______, _______,                           KC_AGIN, KC_UNDO, KC_CUT, KC_COPY, KC_PSTE,
    KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_CAPS,                          KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______,
    KC_GRV, _______, KC_RALT, _______,  _______,  _______,     _______,  KC_INS, KC_HOME,KC_PGDN, KC_PGUP,  KC_END ,
    KC_ESC, _______, _______,  KC_ESC, KC_BSPC,  KC_TAB,    KC_ENT, KC_SPC,  KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),
  
  [_NUM] = LAYOUT( // NUMBER
    KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC,                        _______, _______, _______, _______, _______, 
    KC_SCLN, KC_4, KC_5, KC_6, KC_EQL,                          _______, KC_LSFT, KC_LGUI, KC_RALT, KC_RCTL,
    KC_GRV, KC_1, KC_2, KC_3,  KC_BSLS,  _______,     _______,  _______, _______, _______, _______, _______,
    KC_ESC, _______, _______,  KC_DOT, KC_0,  KC_MINS,    _______, _______, _______, _______, _______, _______),

  [_SYM] = LAYOUT( // SYMBOLS
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                        _______, _______, _______, _______, _______, 
    KC_COLN, KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,                          _______, KC_LSFT, KC_LGUI, KC_LALT, KC_RCTL,
    KC_TILD, KC_EXLM, KC_AT, KC_HASH,  KC_PIPE,  _______,       _______,  _______, _______, _______, KC_RALT, _______,
    KC_ESC, _______, _______,  KC_LPRN, KC_RPRN,  KC_UNDS,    _______, _______, _______, _______, _______, _______),

    [_FUN] = LAYOUT( // SYMBOLS
    KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,                        _______, _______, _______, _______, _______, 
    KC_F11, KC_F4, KC_F5, KC_F6, KC_PLUS,                          _______, KC_LSFT, KC_LGUI, KC_LALT, KC_RCTL,
    KC_F10, KC_F1, KC_F2, KC_F3,  KC_PIPE,  _______,       _______,  _______, _______, _______, KC_RALT, _______,
    KC_ESC, _______, _______,  KC_ESC, KC_BSPC,  KC_TAB,    _______, _______, _______, _______, _______, _______)
};
