#include QMK_KEYBOARD_H

// Layers
#define BASE 0  // Base layer
#define SYMB 1  // Symbols
#define MVMT 2  // Movement
#define UNRC 3  // Unreach


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_ESC, KC_BSPC, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_QUOT, KC_LSPO, MT(MOD_MEH, KC_Z), KC_X, KC_C, KC_V, KC_B, KC_LALT, KC_RALT, KC_K, KC_M, KC_COMM, KC_DOT, MT(MOD_HYPR, KC_SLSH), KC_RSPC, KC_LCTL, KC_SPC, MO(1), MO(2), KC_ENT, KC_RCTL),
	[1] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TAB, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_BSPC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_F12, KC_LSPO, KC_LGUI, KC_COLN, KC_LBRC, KC_RBRC, TO(3), KC_TRNS, KC_RALT, KC_GRV, KC_MINS, KC_EQL, KC_BSLS, KC_SLSH, KC_RSPC, KC_NO, KC_NO, KC_TRNS, MO(3), KC_ENT, KC_RCTL),
	[2] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TAB, KC_MPLY, KC_WH_U, KC_MS_U, KC_WH_D, KC_PSCR, KC_NO, KC_TAB, KC_DEL, KC_INS, KC_NO, KC_ESC, KC_BSPC, KC_MNXT, KC_MS_L, KC_MS_D, KC_MS_R, KC_PAUS, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_QUOT, KC_LSPO, KC_MPRV, KC_WBAK, KC_LCTL, KC_WFWD, TO(3), KC_TRNS, KC_TRNS, KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_RSPC, KC_LCTL, KC_BTN1, KC_BTN2, KC_TRNS, KC_NO, KC_NO),
	[3] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TAB, RESET, KC_NO, KC_D, KC_NO, KC_NO, KC_NO, KC_NO, KC_H, KC_NO, KC_NO, KC_ESC, KC_BSPC, KC_Q, KC_Z, KC_G, KC_B, KC_NO, KC_NO, KC_K, KC_J, KC_SLSH, KC_SCLN, KC_QUOT, KC_LSPO, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_NO, TO(1), TO(2), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_RSPC, KC_NO, KC_NO, TO(0), KC_TRNS, KC_NO, KC_NO)
};

#define RED_PIN F4
#define GRN_PIN F5
#define BLU_PIN C6

// Initialize LED lighting
void keyboard_post_init_user(void) {
    setPinOutput(RED_PIN);
    setPinOutput(GRN_PIN);
    setPinOutput(BLU_PIN);
};

// Turn on LED lighting according to layer
uint32_t layer_state_set_user(uint32_t state) {
    writePinLow(RED_PIN);
    writePinLow(GRN_PIN);
    writePinLow(BLU_PIN);
	switch (biton32(state)) {
		case SYMB:
            writePinHigh(RED_PIN);
			break;
		case MVMT:
            writePinHigh(GRN_PIN);
			break;
		case UNRC:
            writePinHigh(BLU_PIN);
			break;
		default:
			break;
	}
	return state;
};
