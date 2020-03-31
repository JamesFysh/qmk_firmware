/* Copyright 2020 James Fysh
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
#include "jamesfysh.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,     KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
        KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,     KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_LSFT, KC_LMTZ, KC_X,    KC_C,    KC_V,    KC_B,     KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_MTSL, KC_RSFT,
                          KC_NO,   KC_NO,   MO_L3OX, KC_SPC,   KC_ENT,  MO_L4AX, KC_NO,   KC_NO,
                                            MO_SYMB, MO_SYMB,  MO_MVMT, MO_MVMT,
                                            KC_NO,   KC_NO,    KC_NO,   KC_NO
    ),
    [SYMB] = LAYOUT_endgame_wrapper(
       ___SYMB_L1___, ___SYMB_R1___,
       ___SYMB_L2___, ___SYMB_R2___,
       ___SYMB_L3___, ___SYMB_R3___),
    [MVMT] = LAYOUT_endgame_wrapper(
       ___MVMT_L1___, ___MVMT_R1___,
       ___MVMT_L2___, ___MVMT_R2___,
       ___MVMT_L3___, ___MVMT_R3___),
    [UNRC] = LAYOUT_endgame_wrapper(
       ___UNRC_L1___, ___UNRC_R1___,
       ___UNRC_L2___, ___UNRC_R2___,
       ___UNRC_L3___, ___UNRC_R3___),
    [LMTA] = LAYOUT_endgame_wrapper(
       ___LMTA_L1___, ___LMTA_R1___,
       ___LMTA_L2___, ___LMTA_R2___,
       ___LMTA_L3___, ___LMTA_R3___),
    [RMTA] = LAYOUT_endgame_wrapper(
       ___RMTA_L1___, ___RMTA_R1___,
       ___RMTA_L2___, ___RMTA_R2___,
       ___RMTA_L3___, ___RMTA_R3___),
    [L3OX] = LAYOUT_endgame_wrapper(
       ___L3OX_L1___, ___L3OX_R1___,
       ___L3OX_L2___, ___L3OX_R2___,
       ___L3OX_L3___, ___L3OX_R3___),
    [L4AX] = LAYOUT_endgame_wrapper(
       ___L4AX_L1___, ___L4AX_R1___,
       ___L4AX_L2___, ___L4AX_R2___,
       ___L4AX_L3___, ___L4AX_R3___),
    [L3OL] = LAYOUT_endgame_wrapper(
       ___L3OL_L1___, ___L3OL_R1___,
       ___L3OL_L2___, ___L3OL_R2___,
       ___L3OL_L3___, ___L3OL_R3___),
    [L4AL] = LAYOUT_endgame_wrapper(
       ___L4AL_L1___, ___L4AL_R1___,
       ___L4AL_L2___, ___L4AL_R2___,
       ___L4AL_L3___, ___L4AL_R3___)
};
