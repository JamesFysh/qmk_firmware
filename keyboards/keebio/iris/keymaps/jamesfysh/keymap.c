#include QMK_KEYBOARD_H
#include "jamesfysh.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT(
	    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
        KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                      KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_LSFT, KC_LMTZ, KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, XXXXXXX, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_MTSL, KC_RSFT,
                                   MO_L3OX, KC_SPC,  MO_SYMB,                   MO_MVMT, KC_ENT,  MO_L4AX
  ), [SYMB] = LAYOUT_iris_wrapper(
        ___SYMB_L1___, ___SYMB_R1___,
        ___SYMB_L2___, ___SYMB_R2___,
        ___SYMB_L3___, ___SYMB_R3___
  ), [MVMT] = LAYOUT_iris_wrapper(
        ___MVMT_L1___, ___MVMT_R1___,
        ___MVMT_L2___, ___MVMT_R2___,
        ___MVMT_L3___, ___MVMT_R3___
  ), [UNRC] = LAYOUT_iris_wrapper(
        ___UNRC_L1___, ___UNRC_R1___,
        ___UNRC_L2___, ___UNRC_R2___,
        ___UNRC_L3___, ___UNRC_R3___
  ), [LMTA] = LAYOUT_iris_wrapper(
        ___LMTA_L1___, ___LMTA_R1___,
        ___LMTA_L2___, ___LMTA_R2___,
        ___LMTA_L3___, ___LMTA_R3___
 ), [RMTA] = LAYOUT_iris_wrapper(
        ___RMTA_L1___, ___RMTA_R1___,
        ___RMTA_L2___, ___RMTA_R2___,
        ___RMTA_L3___, ___RMTA_R3___
 ), [L3OX] = LAYOUT_iris_wrapper(
       ___RMTA_L1___, ___RMTA_R1___,
       ___RMTA_L2___, ___RMTA_R2___,
       ___RMTA_L3___, ___RMTA_R3___
 ), [L4AX] = LAYOUT_iris_wrapper(
       ___RMTA_L1___, ___RMTA_R1___,
       ___RMTA_L2___, ___RMTA_R2___,
       ___RMTA_L3___, ___RMTA_R3___
 ), [L3OL] = LAYOUT_iris_wrapper(
       ___RMTA_L1___, ___RMTA_R1___,
       ___RMTA_L2___, ___RMTA_R2___,
       ___RMTA_L3___, ___RMTA_R3___
 ), [L4AL] = LAYOUT_iris_wrapper(
       ___RMTA_L1___, ___RMTA_R1___,
       ___RMTA_L2___, ___RMTA_R2___,
       ___RMTA_L3___, ___RMTA_R3___
 )
};

#define RED_PIN F4
#define GRN_PIN F5
#define BLU_PIN C6

// Initialize LED lighting
void keyboard_pre_init_user(void) {
    setPinOutput(RED_PIN);
    setPinOutput(GRN_PIN);
    setPinOutput(BLU_PIN);
    writePinLow(RED_PIN);
    writePinLow(GRN_PIN);
    writePinLow(BLU_PIN);
};

// Turn on LED lighting according to layer
uint32_t layer_state_set_user(uint32_t state) {
    writePinLow(RED_PIN);
    writePinLow(GRN_PIN);
    writePinLow(BLU_PIN);
	state = update_tri_layer_state(state, SYMB, MVMT, UNRC);
    if (state & 1<<UNRC) {
        writePinHigh(BLU_PIN);
    } else {
        if (state & 1<<SYMB) { writePinHigh(RED_PIN); }
        if (state & 1<<MVMT) { writePinHigh(GRN_PIN); }
    }
    return state;
};
