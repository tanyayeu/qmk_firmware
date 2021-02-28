/* Copyright 2017 Wunder
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
    _QW,
    _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | |      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | SHIFT  | A      | S      | D      | F      | G      | HOME   | DEL    | PG UP  | H      | J      | K      | L      | ;      | "      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | CTRL   | Z      | X      | C      | V      | B      | END    | UP     | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * | LCTRL  | LGUI   | LALT   | FN     | SPACE  | SPACE  | LEFT   | DOWN   | RIGHT  | SPACE  | SPACE  | FN     | RALT   | RGUI   | RCTRL  |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_GRV,  KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_P7,  KC_P8, KC_P9, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_LSPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_P4,  KC_P5,  KC_P6,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LCPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_P1,  KC_P2,   KC_P3, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPS,
        KC_LCTL, KC_LGUI, KC_LALT, MO(_FN), KC_SPC,  KC_SPC,  KC_LEFT, KC_P0, KC_RGHT, KC_SPC,  KC_SPC,  MO(_FN), KC_RALT, KC_RGUI, KC_RCTL
    ),

    /* FUNCTION
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | ~      | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | DEL    |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | SELECT | CALC   | MYCOMP | MAIL   | RGB HD | RGB HI | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | HOME   |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | RESET  | P6     | +      |        | RESET  |        |        |  END   |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |        | ENTER  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        | RGB TG | FN     | RGB RMD| RGB MD | P0     |        | P.     | PENT   | PENT   | FN     |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_FN] = LAYOUT_ortho_5x15( /* FUNCTION */
        KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NLCK, KC_SLSH, KC_ASTR, KC_F6,   KC_F7,   KC_F8,   KC_MINS, KC_F11,  KC_DEL,
        KC_MSEL, KC_CALC, KC_MYCM, KC_MAIL, RGB_HUD, RGB_HUI, KC_P7,   KC_P8,   KC_P9,   KC_LBRC, KC_RBRC, _______, KC_UNDS, KC_SLCK, KC_HOME,
        KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, RGB_SAD, RGB_SAI, KC_P4,   RESET,   KC_P6,   KC_PLUS, _______, RESET,   _______, _______, KC_END,
        KC_VOLD, KC_MUTE, KC_VOLU, KC_APP,  RGB_VAD, RGB_VAI, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, _______, _______, _______, KC_ENT,
        _______, _______, RGB_TOG, MO(_FN), RGB_RMOD,RGB_MOD, KC_P0,   _______, KC_PDOT, KC_PENT, KC_PENT, MO(_FN), _______, _______, _______
    )
};
