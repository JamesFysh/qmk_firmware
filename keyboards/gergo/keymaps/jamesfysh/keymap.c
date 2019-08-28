/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

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

#define KC_LMTZ   LT(LMTA, KC_Z)
#define KC_MT11   LT(LMTA, KC_F11)
#define KC_MTSL   LT(RMTA, KC_SLSH)
#define KC_MTPR   LT(LMTA, KC_MPRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_gergo(
    KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                                                KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_NO,                             KC_NO,   KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_LMTZ, KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,   KC_NO,           KC_NO,   KC_NO,   KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_MTSL, KC_RSFT,
                                        KC_NO,   KC_SPC,  MO_SYMB, KC_NO,           KC_NO,   MO_MVMT, KC_ENT,  KC_NO
    ),
[SYMB] = LAYOUT_gergo(
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                               KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
    KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,                             KC_NO,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
    KC_TRNS, KC_MT11, KC_F12,  KC_LBRC, KC_RBRC, KC_NO,   KC_NO,   KC_NO,           KC_NO,   KC_NO,   KC_GRV,  KC_MINS, KC_EQL,  KC_BSLS, KC_MTSL, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
[MVMT] = LAYOUT_gergo(
    KC_TRNS, KC_MPLY, KC_WH_U, KC_UP,   KC_WH_D, KC_PSCR,                                             KC_MUTE, KC_MEH,  KC_DEL,  KC_INS,  KC_HYPR, KC_TRNS,
    KC_TRNS, KC_MNXT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PAUS, KC_TRNS,                           KC_TRNS, KC_VOLU, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS,
    KC_TRNS, KC_MTPR, KC_WBAK, KC_WSTP, KC_WFWD, KC_NO,   KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_VOLD, KC_NO,   KC_NO,   KC_NO,   MO_RMTA, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
[UNRC] = LAYOUT_gergo(
    KC_TRNS, RESET,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                               KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS, KC_PIPE, KC_LCBR, KC_LBRC, KC_LPRN, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_NO,   KC_RPRN, KC_RBRC, KC_RCBR, KC_COLN, KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_NO,   KC_UNDS, KC_PLUS, KC_PIPE, MO_RMTA, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
[LMTA] = LAYOUT_gergo(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_LCTL, KC_LGUI, KC_LALT, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
[RMTA] = LAYOUT_gergo(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_RALT, KC_RGUI, KC_RCTL, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};



// Turn on LED lighting according to layer
uint32_t layer_state_set_user(uint32_t state) {
	state = update_tri_layer_state(state, SYMB, MVMT, UNRC);
    return state;
};
