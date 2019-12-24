#include "layout_helpers.h"

// Layers
#define BASE 0  // Base layer
#define SYMB 1  // Symbols
#define MVMT 2  // Movement
#define UNRC 3  // Unreach
#define LMTA 4  // Left Meta keys
#define RMTA 5  // Right Meta keys
#define L3OX 6  // L3 - OS shortcuts - OSX
#define L4AX 7  // L4 - App shortcuts - OSX
#define L3OL 8  // L3 - OS shortcuts - Linux
#define L4AL 9  // L4 - App shortcuts - Linux


// Shortened key names
#define MO_SYMB   MO(SYMB)
#define MO_MVMT   MO(MVMT)
#define MO_UNRC   MO(UNRC)
#define MO_LMTA   MO(LMTA)
#define MO_RMTA   MO(RMTA)
#define MO_L3OX   MO(L3OX)
#define MO_L4AX   MO(L4AX)

// For activating L/R Meta layers (layer-tap)
#define KC_LMTZ   LT(LMTA, KC_Z)
#define KC_MT11   LT(LMTA, KC_F11)
#define KC_MTSL   LT(RMTA, KC_SLSH)
#define KC_MTPR   LT(LMTA, KC_MPRV)

#define KC_RPS2   LCAG(KC_A)

enum custom_keycodes {
    KC_SWOS = SAFE_RANGE,
    KC_PROS,
};


// Since our quirky block definitions are basically a list of comma separated
// arguments, we need a wrapper in order for these definitions to be
// expanded before being used as arguments to the LAYOUT_xxx macro.
#define LAYOUT_gergo_wrapper(...)       LAYOUT_30_gergo(__VA_ARGS__)
#define LAYOUT_iris_wrapper(...)        LAYOUT_30_iris(__VA_ARGS__)

#define ___TRNS______ _______,  _______,  _______,  _______,  _______

#define ___SYMB_L1___ KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5
#define ___SYMB_L2___ KC_1,     KC_2,     KC_3,     KC_4,     KC_5
#define ___SYMB_L3___ KC_MT11,  KC_F12,   KC_LBRC,  KC_RBRC,  XXXXXXX
#define ___SYMB_R1___ KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10
#define ___SYMB_R2___ KC_6,     KC_7,     KC_8,     KC_9,     KC_0
#define ___SYMB_R3___ KC_GRV,   KC_MINS,  KC_EQL,   KC_BSLS,  KC_MTSL

#define ___MVMT_L1___ KC_MPLY,  KC_WH_U,  KC_UP,    KC_WH_D,  KC_PSCR
#define ___MVMT_L2___ KC_MNXT,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PAUS
#define ___MVMT_L3___ KC_MTPR,  KC_WBAK,  KC_WSTP,  KC_WFWD,  XXXXXXX
#define ___MVMT_R1___ KC_MUTE,  KC_MEH,   KC_DEL,   KC_INS,   KC_HYPR
#define ___MVMT_R2___ KC_VOLU,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END
#define ___MVMT_R3___ KC_VOLD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  MO_RMTA

#define ___UNRC_L1___ XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX
#define ___UNRC_L2___ KC_PIPE,  KC_LCBR,  KC_LBRC,  KC_LPRN, XXXXXXX
#define ___UNRC_L3___ XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX
#define ___UNRC_R1___ XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
#define ___UNRC_R2___ XXXXXXX,  KC_RPRN,  KC_RBRC,  KC_RCBR,  KC_COLN
#define ___UNRC_R3___ XXXXXXX,  KC_UNDS,  KC_PLUS,  KC_PIPE,  MO_RMTA

#define ___LMTA_L1___ ___TRNS______
#define ___LMTA_L2___ _______,  KC_LCTL,  KC_LGUI,  KC_LALT,  _______
#define ___LMTA_L3___ ___TRNS______
#define ___LMTA_R1___ ___TRNS______
#define ___LMTA_R2___ ___TRNS______
#define ___LMTA_R3___ ___TRNS______

#define ___RMTA_L1___ ___TRNS______
#define ___RMTA_L2___ ___TRNS______
#define ___RMTA_L3___ ___TRNS______
#define ___RMTA_R1___ ___TRNS______
#define ___RMTA_R2___ _______,  KC_RALT,  KC_RGUI,  KC_RCTL, _______
#define ___RMTA_R3___ ___TRNS______

#define ___L3OX_L1___ XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PROS, KC_SWOS
#define ___L3OX_L2___ XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_TAB,  XXXXXXX
#define ___L3OX_L3___ XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX
#define ___L3OX_R1___ XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX
#define ___L3OX_R2___ XXXXXXX,  KC_RGUI,  XXXXXXX,  XXXXXXX, XXXXXXX
#define ___L3OX_R3___ XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX

#define ___L4AX_L1___ XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX
#define ___L4AX_L2___ XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX
#define ___L4AX_L3___ XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX
#define ___L4AX_R1___ XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX
#define ___L4AX_R2___ XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX
#define ___L4AX_R3___ XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX

#define ___L3OL_L1___ _______,  _______,  _______,  _______, _______
#define ___L3OL_L2___ _______,  _______,  _______,  _______, _______
#define ___L3OL_L3___ _______,  _______,  _______,  _______, _______
#define ___L3OL_R1___ _______,  _______,  _______,  _______, _______
#define ___L3OL_R2___ _______,  KC_RALT,  _______,  _______, _______
#define ___L3OL_R3___ _______,  _______,  _______,  _______, _______

#define ___L4AL_L1___ _______,  _______,  _______,  _______, _______
#define ___L4AL_L2___ _______,  _______,  _______,  _______, _______
#define ___L4AL_L3___ _______,  _______,  _______,  _______, _______
#define ___L4AL_R1___ _______,  _______,  _______,  _______, _______
#define ___L4AL_R2___ _______,  _______,  _______,  _______, _______
#define ___L4AL_R3___ _______,  _______,  _______,  _______, _______
