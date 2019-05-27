#include QMK_KEYBOARD_H

// Layers
#define BASE 0  // Base layer
#define SYMB 1  // Symbols
#define MVMT 2  // Movement
#define UNRC 3  // Unreach
#define LMTA 4  // Left Meta keys
#define RMTA 5  // Right Meta keys

// Shortened key names
#define MO_SYMB   MO(SYMB)
#define MO_MVMT   MO(MVMT)
#define MO_UNRC   MO(UNRC)
#define MO_RMTA   MO(RMTA)
#define TO_BASE   TO(0)
#define TO_SYMB   TO(1)
#define TO_MVMT   TO(2)
#define TO_UNRC   TO(3)

#define KC_LMTZ   LT(LMTA, KC_Z)
#define KC_MT11   LT(LMTA, KC_F11)
#define KC_MTSL   LT(RMTA, KC_SLSH)
#define KC_MTPR   LT(LMTA, KC_MPRV)

// unreach layer keys
#define KC_CTLZ   LCTL(KC_Z)
#define KC_CTLX   LCTL(KC_X)
#define KC_CTLC   LCTL(KC_C)
#define KC_CTLV   LCTL(KC_V)
#define KC_CTLB   LCTL(KC_B)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
////////|/////////|/////////|/////////|/////////|////////|///////////////////////////////|/////////|/////////|/////////|/////////|/////////|/////////
        KC_ESC,   KC_Q,     KC_W,     KC_F,     KC_P,    KC_G,                           KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_BSPC,//
        KC_TAB,   KC_A,     KC_R,     KC_S,     KC_T,    KC_D,                           KC_H,     KC_N,     KC_E,     KC_I,     KC_O,     KC_QUOT,//
        KC_LSFT,  KC_LMTZ,  KC_X,     KC_C,     KC_V,    KC_B,    TO_UNRC,   TO_SYMB,    KC_K,     KC_M,     KC_COMM,  KC_DOT,   KC_MTSL,  KC_RSFT,//
                                            KC_NO,    KC_SPC,   MO_SYMB,        MO_MVMT,   KC_ENT,   KC_NO                                         //
////////////////////////////////////////////|/////////|/////////|///////////////|//////////|/////////|///////////////////////////////////////////////
  ), [SYMB] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
////////|/////////|/////////|/////////|/////////|////////|///////////////////////////////|/////////|/////////|/////////|/////////|/////////|/////////
        KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,                          KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_TRNS,//
        KC_TRNS,  KC_1,     KC_2,     KC_3,     KC_4,    KC_5,                           KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_TRNS,//
        KC_TRNS,  KC_MT11,  KC_F12,   KC_LBRC,  KC_RBRC, KC_NO,    TO_BASE,  TO_MVMT,    KC_GRV,   KC_MINS,  KC_EQL,   KC_BSLS,  KC_MTSL,  KC_TRNS,//
                                            KC_TRNS,  KC_TRNS,  KC_NO,          MO_UNRC,   KC_TRNS,  KC_TRNS                                       //
////////////////////////////////////////////|/////////|/////////|///////////////|//////////|/////////|///////////////////////////////////////////////
  ), [MVMT] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
////////|/////////|/////////|/////////|/////////|////////|///////////////////////////////|/////////|/////////|/////////|/////////|/////////|/////////
        KC_TRNS,  KC_MPLY,  KC_WH_U,  KC_UP,    KC_WH_D, KC_PSCR,                        KC_MUTE,  KC_MEH,   KC_DEL,   KC_INS,   KC_HYPR,  KC_TRNS,//
        KC_TRNS,  KC_MNXT,  KC_LEFT,  KC_DOWN,  KC_RGHT, KC_PAUS,                        KC_VOLU,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_TRNS,//
        KC_TRNS,  KC_MTPR,  KC_WBAK,  KC_WSTP,  KC_WFWD, KC_NO,    TO_SYMB,  TO_UNRC,    KC_VOLD,  KC_NO,    KC_NO,    KC_NO,    MO_RMTA,  KC_TRNS,//
                                            KC_TRNS,  KC_TRNS,  MO_UNRC,        KC_NO,     KC_TRNS,  KC_TRNS                                       //
////////////////////////////////////////////|/////////|/////////|///////////////|//////////|/////////|///////////////////////////////////////////////
  ), [UNRC] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
////////|/////////|/////////|/////////|/////////|////////|///////////////////////////////|/////////|/////////|/////////|/////////|/////////|/////////
        KC_TRNS,  RESET,    KC_NO,    KC_NO,    KC_NO,   KC_NO,                          KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_SLEP,  KC_TRNS,//
        KC_TRNS,  KC_PIPE,  KC_LCBR,  KC_LBRC,  KC_LPRN, KC_NO,                          KC_NO,    KC_RPRN,  KC_RBRC,  KC_RCBR,  KC_COLN,  KC_TRNS,//
        KC_TRNS,  KC_CTLZ,  KC_CTLX,  KC_CTLC,  KC_CTLV, KC_CTLB,  TO_MVMT,  TO_BASE,    KC_NO,    KC_UNDS,  KC_PLUS,  KC_PIPE,  MO_RMTA,  KC_TRNS,//
                                            KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,   KC_TRNS,  KC_TRNS                                       //
////////////////////////////////////////////|/////////|/////////|///////////////|//////////|/////////|///////////////////////////////////////////////
  ), [LMTA] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
////////|/////////|/////////|/////////|/////////|////////|///////////////////////////////|/////////|/////////|/////////|/////////|/////////|/////////
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,                        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,//
        KC_TRNS,  KC_TRNS,  KC_LCTL,  KC_LGUI,  KC_LALT, KC_TRNS,                        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,//
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,//
                                            KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,   KC_TRNS,  KC_TRNS                                       //
////////////////////////////////////////////|/////////|/////////|///////////////|//////////|/////////|///////////////////////////////////////////////
  ), [RMTA] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
////////|/////////|/////////|/////////|/////////|////////|///////////////////////////////|/////////|/////////|/////////|/////////|/////////|/////////
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,                        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,//
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,                        KC_TRNS,  KC_RALT,  KC_RGUI,  KC_RCTL,  KC_TRNS,  KC_TRNS,//
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,//
                                            KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,   KC_TRNS,  KC_TRNS                                       //
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
    if (state & 1<<SYMB) { writePinHigh(RED_PIN); }
    if (state & 1<<MVMT) { writePinHigh(GRN_PIN); }
    if (state & 1<<UNRC) { writePinHigh(BLU_PIN); }
	return state;
};
