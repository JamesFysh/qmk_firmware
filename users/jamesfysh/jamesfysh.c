#include QMK_KEYBOARD_H
#include "jamesfysh.h"


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
            case KC_KBVS:
                SEND_STRING("v0.0.4");
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
