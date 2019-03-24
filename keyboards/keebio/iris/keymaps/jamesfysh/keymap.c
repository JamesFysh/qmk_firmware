#include QMK_KEYBOARD_H

// Layers
#define BASE 0  // Base layer
#define SYMB 1  // Symbols
#define MVMT 2  // Movement
#define UNRC 3  // Unreach
#define MDFR 4  // Modifiers
#define ANCL 5  // Ancillary

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL, KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_MINS, KC_BSPC, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO, KC_NO, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, MO(UNRC), KC_SPC, MO(SYMB), TT(MVMT), KC_ENT, MO(MDFR)),
	[SYMB] = LAYOUT(KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_TAB, KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_BSLS, KC_PSLS, KC_7, KC_8, KC_P9, KC_PAST, KC_F12, KC_BSPC, KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, KC_GRV, KC_MINS, KC_4, KC_5, KC_6, KC_EQL, KC_F13, KC_LSFT, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_CAPS, KC_NO, KC_NO, KC_0, KC_1, KC_2, KC_3, KC_SLSH, KC_F14, KC_NO, KC_TRNS, KC_TRNS, KC_SCLN, KC_TRNS, KC_NO),
	[MVMT] = LAYOUT(KC_ESC, KC_ACL0, KC_ACL1, KC_ACL2, KC_NO, KC_NO, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL, KC_TAB, TO(ANCL), KC_WH_U, KC_MS_U, KC_WH_D, LCTL(KC_ENT), KC__VOLUP, KC_TAB, KC_DEL, KC_INS, KC_NO, KC_MINS, KC_LCTL, KC_LALT, KC_MS_L, KC_MS_D, KC_MS_R, LALT(KC_ENT), KC_MUTE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_QUOT, KC_LSFT, KC_NO, KC_WBAK, KC_NO, KC_WFWD, LSFT(KC_NO), KC_NO, KC_NO, KC_VOLD, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_LSFT, TO(BASE), KC_BTN1, KC_BTN2, KC_TRNS, TO(BASE), KC_BTN3),
	[UNRC] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL, KC_TAB, KC_NO, KC_NO, KC_D, KC_NO, KC_NO, KC_NO, KC_NO, KC_H, KC_NO, KC_NO, KC_MINS, KC_BSPC, KC_Q, KC_Z, KC_G, KC_B, KC_NO, KC_NO, KC_K, KC_J, KC_SLSH, KC_SCLN, KC_QUOT, KC_LSFT, LSFT(KC_Q), LSFT(KC_Z), LSFT(KC_G), LSFT(KC_B), KC_NO, KC_NO, KC_NO, KC_NO, LSFT(KC_K), LSFT(KC_J), KC_QUES, KC_COLN, KC_LSFT, KC_TRNS, KC_SPC, KC_NO, KC_NO, KC_ENT, KC_NO),
	[MDFR] = LAYOUT(KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_TAB, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F12, KC_BSPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LGUI, KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_APP, MEH(KC_NO), HYPR(KC_NO), KC_LCTL, KC_LCTL, KC_LALT, KC_TRNS),
	[ANCL] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_SLEP, KC_NO, KC_NO, TO(MVMT), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LOCK, KC_PSCR, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(BASE), TO(BASE), KC_NO, KC_NO)
};

#define RED_PIN C6
#define GRN_PIN F5
#define BLU_PIN F4

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
            writePinHigh(RED_PIN);
            // Intentional fall-through, UNRC = red+blue
		case MDFR:
            writePinHigh(BLU_PIN);
			break;
        case ANCL:
            // Approx. Yellow
            writePinHigh(GRN_PIN);
            writePinHigh(RED_PIN);
            break;
		default:
			break;
	}
	return state;
};
