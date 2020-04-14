#include QMK_KEYBOARD_H
#include "jamesfysh.h"


bool is_osx;

// Initialize LED lighting
void keyboard_pre_init_user(void) {
    #ifdef USE_INDICATOR_LED
        setPinOutput(RED_PIN);
        setPinOutput(GRN_PIN);
        setPinOutput(BLU_PIN);
    #endif
    is_osx = true;
};

void keyboard_post_init_user(void) {
    #ifdef USE_INDICATOR_LED
        writePinLow(RED_PIN);
        writePinLow(GRN_PIN);
        writePinLow(BLU_PIN);
    #endif

    #ifdef USE_WS_INDICATOR_LED
        rgblight_setrgb(0, 0, 0);
    #endif
}


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
                SEND_STRING("v1.2.0");
                break;
            case KC_EMAL:
                SEND_STRING("james.fysh@gmail.com");
                break;
            case KC_WREM:
                SEND_STRING("james.fysh@alliancesoftware.com.au");
                break;
        }
    }
    return true;
};


uint32_t layer_state_set_user(uint32_t state) {
    // Determine tri-state for UNRC
	state = update_tri_layer_state(state, SYMB, MVMT, UNRC);

    // Activate Linux layers rather than OSX layers, if in linux mode
    state &= ~(1 << L3OL | 1 << L4AL);
    if (state & 1<<L3OX && !is_osx) {
        state |= 1 << L3OL;
    }
    if (state & 1<<L4AX && !is_osx) {
        state |= 1 << L4AL;
    }

    #ifdef USE_INDICATOR_LED
        // Turn off all LED lighting
        writePinLow(RED_PIN);
        writePinLow(GRN_PIN);
        writePinLow(BLU_PIN);

        // Turn on lighting to indicate active layer
        if (state & 1<<UNRC) {
            writePinHigh(BLU_PIN);
        } else {
            if (state & 1<<SYMB) { writePinHigh(RED_PIN); }
            if (state & 1<<MVMT) { writePinHigh(GRN_PIN); }
        }
        if (state & 1<<L3OX) {
            writePinHigh(RED_PIN);
            writePinHigh(BLU_PIN);
        }
        if (state & 1<<L4AX) {
            writePinHigh(GRN_PIN);
            writePinHigh(BLU_PIN);
        }
    #endif

    #ifdef USE_WS_INDICATOR_LED
        uint8_t r = 0, g = 0, b = 0;
        if (state) {
            if (state & 1<<UNRC) { b = 255; }
            else if (state & 1<<SYMB) { r = 255; }
            else if (state & 1<<MVMT) { g = 255; }
            if (state & 1<<L3OX) { r = 255; b = 255; }
            if (state & 1<<L4AX) { g = 255; b = 255; }
        }
        rgblight_setrgb(r, g, b);
    #endif
    return state;
};

LEADER_EXTERNS();
void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();
        // Replace the sequences below with your own sequences.
        SEQ_ONE_KEY(KC_T) {
            // When I press KC_LEAD and then T, this sends CTRL + SHIFT + T
            SEND_STRING("^T");
        }
        // Note: This is not an array, you don't need to put any commas
        // or semicolons between sequences.
        SEQ_TWO_KEYS(KC_N, KC_T) {
            // When I press KC_LEAD and then N followed by T, this sends CTRL + T
            SEND_STRING("^t");
        }
    }
}
