#define LAYOUT_30_gergo(                                \
    L01,L02,L03,L04,L05,      R00,R01,R02,R03,R04,      \
    L11,L12,L13,L14,L15,      R11,R12,R13,R14,R15,      \
    L21,L22,L23,L24,L25,      R21,R22,R23,R24,R25       \
    )                                                   \
    {                                                   \
        { KC_NO,      KC_TRNS,    KC_TRNS,   KC_TRNS }, \
        { L05,        L15,        L25,       KC_TRNS }, \
        { L04,        L14,        L24,       KC_TRNS }, \
        { L03,        L13,        L23,       KC_TRNS }, \
        { L02,        L12,        L22,       KC_TRNS }, \
        { L01,        L11,        L21,       KC_NO   }, \
        { KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_NO   }, \
                                                        \
        { KC_NO,      KC_TRNS,    KC_TRNS,   KC_TRNS }, \
        { R00,        R11,        R21,       KC_TRNS }, \
        { R01,        R12,        R22,       KC_TRNS }, \
        { R02,        R13,        R23,       KC_TRNS }, \
        { R03,        R14,        R24,       KC_TRNS }, \
        { R04,        R15,        R25,       KC_NO   }, \
        { KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_NO   }  \
}

#define LAYOUT_30_iris( \
    L11, L12, L13, L14, L15,      R10, R11, R12, R13, R14,              \
    L21, L22, L23, L24, L25,      R20, R21, R22, R23, R24,              \
    L31, L32, L33, L34, L35,      R30, R31, R32, R33, R34               \
    )                                                                   \
    {                                                                   \
        { KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO    }, \
        { KC_TRNS,  L11,      L12,      L13,      L14,      L15      }, \
        { KC_TRNS,  L21,      L22,      L23,      L24,      L25      }, \
        { KC_TRNS,  L31,      L32,      L33,      L34,      L35      }, \
        { KC_NO,    KC_NO,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS  }, \
                                                                        \
        { KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO    }, \
        { KC_TRNS,  R14,      R13,      R12,      R11,      R10      }, \
        { KC_TRNS,  R24,      R23,      R22,      R21,      R20      }, \
        { KC_TRNS,  R34,      R33,      R32,      R31,      R30      }, \
        { KC_NO,    KC_NO,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS  }  \
    }

#define LAYOUT_30_endgame(\
    L01, L02, L03, L04, L05,     R00, R01, R02, R03, R04, \
    L11, L12, L13, L14, L15,     R10, R11, R12, R13, R14, \
    L21, L22, L23, L24, L25,     R20, R21, R22, R23, R24 \
) \
{ \
    { R00, R01, R02, R03, R04, KC_TRNS, KC_TRNS, KC_TRNS }, \
    { R10, R11, R12, R13, R14, KC_TRNS, KC_TRNS, KC_TRNS }, \
    { R20, R21, R22, R23, R24, KC_TRNS, KC_TRNS, KC_TRNS }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }, \
    { KC_TRNS, L21, L22, L23, L24, L25, KC_TRNS, KC_TRNS }, \
    { KC_TRNS, L11, L12, L13, L14, L15, KC_TRNS, KC_TRNS }, \
    { KC_TRNS, L01, L02, L03, L04, L05, KC_TRNS, KC_TRNS }, \
}
