/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H
#include "ciantha.h"
#include "key_overrides.h"

// layout macro
#define LAYOUT_ciantha_10_5u_8_thumb_keys(...) LAYOUT_regular(__VA_ARGS__)

//set handedness for chordal hold
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_ciantha_10_5u_8_thumb_keys(
      'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R',
      '*', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R',
      'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R',
      '*', '*', '*', '*', '*', '*', '*', '*'
    );

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ciantha_10_5u_8_thumb_keys(
	      ___BASE_Q_ROW_10u___,
        ___BASE_A_ROW_10u___,
        ___BASE_Z_ROW_9u___,
        KC_TRNS, ___BASE_THUMB_6___, KC_TRNS
	      ),

  [NUM] = LAYOUT_ciantha_10_5u_8_thumb_keys(
	      ___NUM_Q_ROW_10u___,
        ___NUM_A_ROW_10u___,
        ___NUM_Z_ROW_9u___,
        KC_TRNS, ___NUM_THUMB_6___, KC_TRNS
	      ),

  [NAV] = LAYOUT_ciantha_10_5u_8_thumb_keys(
	      ___NAV_Q_ROW_10u___,
        ___NAV_A_ROW_10u___,
        ___NAV_Z_ROW_9u___,
        KC_TRNS, ___NAV_THUMB_6___, KC_TRNS
	      ),
};

#include "encoder_map.h"
#include "tap_dances.c"
#include "process_record_user.c"

//include combos.def
#include "g/keymap_combo.h"