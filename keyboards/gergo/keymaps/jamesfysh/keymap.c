/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H
#include "jamesfysh.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_gergo(
    KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                                                KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_NO,                             KC_NO,   KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_LMTZ, KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,   KC_NO,           KC_NO,   KC_NO,   KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_MTSL, KC_RSFT,
                                        MO_L3OX, KC_SPC,  MO_SYMB, KC_NO,           KC_NO,   MO_MVMT, KC_ENT,  MO_L4AX),
[SYMB] = LAYOUT_gergo_wrapper(
    ___SYMB_L1___, ___SYMB_R1___,
    ___SYMB_L2___, ___SYMB_R2___,
    ___SYMB_L3___, ___SYMB_R3___),
[MVMT] = LAYOUT_gergo_wrapper(
    ___MVMT_L1___, ___MVMT_R1___,
    ___MVMT_L2___, ___MVMT_R2___,
    ___MVMT_L3___, ___MVMT_R3___),
[UNRC] = LAYOUT_gergo_wrapper(
    ___UNRC_L1___, ___UNRC_R1___,
    ___UNRC_L2___, ___UNRC_R2___,
    ___UNRC_L3___, ___UNRC_R3___),
[LMTA] = LAYOUT_gergo_wrapper(
    ___LMTA_L1___, ___LMTA_R1___,
    ___LMTA_L2___, ___LMTA_R2___,
    ___LMTA_L3___, ___LMTA_R3___),
[RMTA] = LAYOUT_gergo_wrapper(
    ___RMTA_L1___, ___RMTA_R1___,
    ___RMTA_L2___, ___RMTA_R2___,
    ___RMTA_L3___, ___RMTA_R3___),
[L3OX] = LAYOUT_gergo_wrapper(
    ___L3OX_L1___, ___L3OX_R1___,
    ___L3OX_L2___, ___L3OX_R2___,
    ___L3OX_L3___, ___L3OX_R3___),
[L4AX] = LAYOUT_gergo_wrapper(
    ___L4AX_L1___, ___L4AX_R1___,
    ___L4AX_L2___, ___L4AX_R2___,
    ___L4AX_L3___, ___L4AX_R3___),
[L3OL] = LAYOUT_gergo_wrapper(
    ___L3OL_L1___, ___L3OL_R1___,
    ___L3OL_L2___, ___L3OL_R2___,
    ___L3OL_L3___, ___L3OL_R3___),
[L4AL] = LAYOUT_gergo_wrapper(
    ___L4AL_L1___, ___L4AL_R1___,
    ___L4AL_L2___, ___L4AL_R2___,
    ___L4AL_L3___, ___L4AL_R3___)
};


#define RED_PIN D6
#define GRN_PIN D5
#define BLU_PIN D4

bool is_osx;

// Initialize LED lighting
void keyboard_pre_init_user(void) {
    setPinOutput(RED_PIN);
    setPinOutput(GRN_PIN);
    setPinOutput(BLU_PIN);
    is_osx = true;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
      switch (keycode) {
        case KC_SWOS:
            if (is_osx) {
                SEND_STRING("-> LIN");
                is_osx = false;
            } else {
                SEND_STRING("-> OSX");
                is_osx = true;
            }
          break;
        case KC_PROS:
            if (is_osx) {
                SEND_STRING("OSX");
            } else {
                SEND_STRING("LIN");
            }
          break;
      }
  }
  return true;
};


uint32_t layer_state_set_user(uint32_t state) {
    // Turn off all LED lighting
    writePinLow(RED_PIN);
    writePinLow(GRN_PIN);
    writePinLow(BLU_PIN);

    // Determine tri-state for UNRC
	state = update_tri_layer_state(state, SYMB, MVMT, UNRC);

    // Turn on lighting to indicate active layer
    if (state & 1<<UNRC) {
        writePinHigh(BLU_PIN);
    } else {
        if (state & 1<<SYMB) { writePinHigh(RED_PIN); }
        if (state & 1<<MVMT) { writePinHigh(GRN_PIN); }
    }

    // Activate Linux layers rather than OSX layers, if in linux mode
    state &= ~(1 << L3OL | 1 << L4AL);
    if (state & 1<<L3OX) {
        if (!is_osx) {
            state |= 1 << L3OL;
        }
        writePinHigh(RED_PIN);
        writePinHigh(BLU_PIN);

    }
    if (state & 1<<L4AX) {
        if (!is_osx) {
            state |= 1 << L4AL;
        }
        writePinHigh(GRN_PIN);
        writePinHigh(BLU_PIN);
    }
    return state;
};
