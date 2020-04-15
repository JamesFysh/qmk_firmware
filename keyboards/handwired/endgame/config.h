#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0xDEAD
#define DEVICE_VER      0xBEEF
#define MANUFACTURER    Fysh
#define PRODUCT         JF Dactyl Manuform

/* key matrix size */
#define MATRIX_ROWS 7
#define MATRIX_COLS 8

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
*/
#define MATRIX_COL_PINS { B0, B1, B2 , B3, B4, B5, B6, B7 }
#define MATRIX_ROW_PINS { B15, B9, B10, B11, B12, A14, A13 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* Mod-Tap configuration */
#define TAPPING_TERM              200
#define IGNORE_MOD_TAP_INTERRUPT

/* RGB Lighting configuration */
#define USE_WS_INDICATOR_LED
#define RGB_DI_PIN A3
#define RGBLED_NUM 3
#define RGBLIGHT_ANIMATION
#define RGBLIGHT_LAYERS

/* Leader-key configuration */
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 250