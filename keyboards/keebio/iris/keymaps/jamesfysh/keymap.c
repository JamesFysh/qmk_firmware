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

//#define KC_MHSC   MT(MOD_MEH, KC_SCLN)
#define KC_MEHZ   MT(MOD_MEH, KC_Z)
#define KC_HYSL   MT(MOD_HYPR, KC_SLSH)
#define KC_CTLZ   LCTL(KC_Z)
#define KC_CTLX   LCTL(KC_X)
#define KC_CTLC   LCTL(KC_C)
#define KC_CTLV   LCTL(KC_V)

#define KC_SFTA   SFT_T(KC_A)
#define KC_CTLR   CTL_T(KC_R)
#define KC_GUIS   GUI_T(KC_S)
#define KC_ALTT   ALT_T(KC_T)

#define KC_ALTN   ALT_T(KC_N)
#define KC_GUIE   GUI_T(KC_E)
#define KC_CTLI   CTL_T(KC_I)
#define KC_SFTO   SFT_T(KC_O)

#define KC_SFT1   SFT_T(KC_1)
#define KC_CTL2   CTL_T(KC_2)
#define KC_GUI3   GUI_T(KC_3)
#define KC_ALT4   ALT_T(KC_4)

#define KC_ALT7   ALT_T(KC_7)
#define KC_GUI8   GUI_T(KC_8)
#define KC_CTL9   CTL_T(KC_9)
#define KC_SFT0   SFT_T(KC_0)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT(
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,                          KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,    KC_G,                           KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_ESC,
        KC_BSPC,  KC_SFTA,  KC_CTLR,  KC_GUIS,  KC_ALTT, KC_D,                           KC_H,     KC_ALTN,  KC_GUIE,  KC_CTLI,  KC_SFTO,  KC_QUOT,
        KC_LSPO,  KC_MEHZ,  KC_X,     KC_C,     KC_V,    KC_B,     KC_LALT,  KC_RALT,    KC_K,     KC_M,     KC_COMM,  KC_DOT,   KC_HYSL,  KC_RSPC,
                                            KC_LCTL,  KC_SPC,   MO_SYMB,       MO_MVMT,    KC_ENT,   KC_RCTL
  ),
	[SYMB] = LAYOUT(
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,                          KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        KC_TAB,   KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,                          KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
        KC_BSPC,  KC_SFT1,  KC_CTL2,  KC_GUI3,  KC_ALT4, KC_5,                           KC_6,     KC_ALT7,  KC_GUI8,  KC_CTL9,  KC_SFT0,  KC_F12,
        KC_LSPO,  KC_LGUI,  KC_COLN,  KC_LBRC,  KC_RBRC, TO(3),    KC_NO,    KC_RALT,    KC_GRV,   KC_MINS,  KC_EQL,   KC_BSLS,  KC_SLSH,  KC_RSPC,
                                            KC_NO,    KC_NO,    KC_TRNS,       MO_UNRC,    KC_ENT,   KC_RCTL
  ),
	[MVMT] = LAYOUT(
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,                          KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        KC_TAB,   KC_MPLY,  KC_WH_U,  KC_MS_U,  KC_WH_D, KC_PSCR,                        KC_MUTE,  KC_TAB,   KC_DEL,   KC_INS,   KC_NO,    KC_ESC,
        KC_BSPC,  KC_MNXT,  KC_MS_L,  KC_MS_D,  KC_MS_R, KC_PAUS,                        KC_VOLU,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_QUOT,
        KC_LSPO,  KC_MPRV,  KC_WBAK,  KC_LCTL,  KC_WFWD, TO(3),    KC_LALT,  KC_NO,      KC_VOLD,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_RSPC,
                                            KC_LCTL,  KC_BTN1,  KC_BTN2,         KC_TRNS,  KC_NO,    KC_NO
  ),
	[UNRC] = LAYOUT(
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,                          KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        KC_TAB,   RESET,    KC_NO,    KC_D,     KC_NO,   KC_NO,                          KC_NO,    KC_NO,    KC_H,     KC_NO,    KC_NO,    KC_ESC,
        KC_BSPC,  KC_Q,     KC_Z,     KC_G,     KC_B,    KC_NO,                          KC_NO,    KC_K,     KC_J,     KC_SLSH,  KC_SCLN,  KC_QUOT,
        KC_LSPO,  KC_CTLZ,  KC_CTLX,  KC_CTLC,  KC_CTLV, KC_NO,    TO(1),    TO(2),      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_RSPC,
                                            KC_NO,    KC_NO,    TO(0),           KC_TRNS,  KC_NO,    KC_NO
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
