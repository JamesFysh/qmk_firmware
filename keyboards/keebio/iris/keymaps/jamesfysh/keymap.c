#include QMK_KEYBOARD_H

// Layers
#define BASE 0  // Base layer
#define SYMB 1  // Symbols
#define MVMT 2  // Movement
#define UNRC 3  // Unreach

// Shortened key names
#define MO_SYMB   MO(1)
#define MO_MVMT   MO(2)
#define MO_UNRC   MO(3)
#define TO_BASE   TO(0)


// base layer mod-taps
#define KC_MEHZ   MT(MOD_MEH, KC_Z)
#define KC_HYSL   MT(MOD_HYPR, KC_SLSH)
#define KC_CTLR   CTL_T(KC_R)
#define KC_GUIS   GUI_T(KC_S)
#define KC_ALTT   ALT_T(KC_T)
#define KC_ALTN   ALT_T(KC_N)
#define KC_GUIE   GUI_T(KC_E)
#define KC_CTLI   CTL_T(KC_I)

// symbol layer mod-taps
#define KC_CTL2   CTL_T(KC_2)
#define KC_GUI3   GUI_T(KC_3)
#define KC_ALT4   ALT_T(KC_4)
#define KC_ALT7   ALT_T(KC_7)
#define KC_GUI8   GUI_T(KC_8)
#define KC_CTL9   CTL_T(KC_9)

// movement layer mod-taps
#define KC_ALHM   ALT_T(KC_HOME)
#define KC_GUPD   GUI_T(KC_PGDN)
#define KC_CTPU   CTL_T(KC_PGUP)

// unreach layer keys
#define KC_CTLZ   LCTL(KC_Z)
#define KC_CTLX   LCTL(KC_X)
#define KC_CTLC   LCTL(KC_C)
#define KC_CTLV   LCTL(KC_V)
#define KC_CTLB   LCTL(KC_B)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT(
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,                          KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
////////|/////////|/////////|/////////|/////////|////////|///////////////////////////////|/////////|/////////|/////////|/////////|/////////|/////////
        KC_ESC,   KC_Q,     KC_W,     KC_F,     KC_P,    KC_G,                           KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_BSPC,//
        KC_TAB,   KC_A,     KC_CTLR,  KC_GUIS,  KC_ALTT, KC_D,                           KC_H,     KC_ALTN,  KC_GUIE,  KC_CTLI,  KC_O,     KC_QUOT,//
        KC_LSFT,  KC_MEHZ,  KC_X,     KC_C,     KC_V,    KC_B,     KC_NO,    KC_NO,      KC_K,     KC_M,     KC_COMM,  KC_DOT,   KC_HYSL,  KC_RSFT,//
                                            KC_NO,    KC_SPC,   MO_SYMB,        MO_MVMT,   KC_ENT,   KC_NO                                         //
////////////////////////////////////////////|/////////|/////////|///////////////|//////////|/////////|///////////////////////////////////////////////
  ),
	[SYMB] = LAYOUT(
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,                          KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
////////|/////////|/////////|/////////|/////////|////////|///////////////////////////////|/////////|/////////|/////////|/////////|/////////|/////////
        KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,                          KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_TRNS,//
        KC_TRNS,  KC_1,     KC_CTL2,  KC_GUI3,  KC_ALT4, KC_5,                           KC_6,     KC_ALT7,  KC_GUI8,  KC_CTL9,  KC_0,     KC_TRNS,//
        KC_TRNS,  KC_F11,   KC_F12,   KC_LBRC,  KC_RBRC, KC_NO,    KC_NO,    KC_NO,      KC_GRV,   KC_MINS,  KC_EQL,   KC_BSLS,  KC_SLSH,  KC_TRNS,//
                                            KC_NO,    KC_TRNS,  KC_NO,          MO_UNRC,   KC_TRNS,  KC_NO                                         //
////////////////////////////////////////////|/////////|/////////|///////////////|//////////|/////////|///////////////////////////////////////////////
  ),
	[MVMT] = LAYOUT(
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,                          KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
////////|/////////|/////////|/////////|/////////|////////|///////////////////////////////|/////////|/////////|/////////|/////////|/////////|/////////
        KC_TRNS,  KC_MPLY,  KC_WH_U,  KC_UP,    KC_WH_D, KC_PSCR,                        KC_MUTE,  MOD_MEH,  KC_DEL,   KC_INS,   MOD_HYPR, KC_TRNS,//
        KC_TRNS,  KC_MNXT,  KC_LEFT,  KC_DOWN,  KC_RGHT, KC_PAUS,                        KC_VOLU,  KC_ALHM,  KC_GUPD,  KC_CTPU,  KC_END,   KC_TRNS,//
        KC_TRNS,  KC_MPRV,  KC_WBAK,  KC_NO,    KC_WFWD, KC_NO,    KC_NO,    KC_NO,      KC_VOLD,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_TRNS,//
                                            KC_NO,    KC_TRNS,  MO_UNRC,        KC_NO,     KC_TRNS,  KC_NO                                         //
////////////////////////////////////////////|/////////|/////////|///////////////|//////////|/////////|///////////////////////////////////////////////
  ),
	[UNRC] = LAYOUT(
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,                          KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
////////|/////////|/////////|/////////|/////////|////////|///////////////////////////////|/////////|/////////|/////////|/////////|/////////|/////////
        KC_TRNS,  RESET,    KC_NO,    KC_D,     KC_NO,   KC_NO,                          KC_NO,    KC_NO,    KC_H,     KC_NO,    KC_NO,    KC_TRNS,//
        KC_TRNS,  KC_Q,     KC_Z,     KC_G,     KC_B,    KC_NO,                          KC_NO,    KC_K,     KC_J,     KC_SLSH,  KC_SCLN,  KC_TRNS,//
        KC_TRNS,  KC_CTLZ,  KC_CTLX,  KC_CTLC,  KC_CTLV, KC_NO,    KC_NO,    KC_NO,      KC_NO,    KC_LPRN,  KC_RPRN,  KC_COLN,  KC_NO,    KC_TRNS,//
                                            KC_NO,    KC_TRNS,  KC_TRNS,        KC_TRNS,   KC_TRNS,  KC_NO                                         //
////////////////////////////////////////////|/////////|/////////|///////////////|//////////|/////////|///////////////////////////////////////////////
  )
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
