#include QMK_KEYBOARD_H
#include "ciantha.h"
#include "key_overrides.h"


// layout macro
#define LAYOUT_ciantha_10_25u_6_thumb_keys(...) LAYOUT_split_space_hhkb(__VA_ARGS__)

//set handedness for chordal hold
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_ciantha_10_25u_6_thumb_keys(
      ___CHORDAL_10_25u6t_stag___
    );

//actual keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ciantha_10_25u_6_thumb_keys(
    
    ___BASE_Q_ROW_10u___,
    ___BASE_A_ROW_10u___,
    ___BASE_Z_ROW_9u___,
    ___BASE_THUMB_6___
  ),

  [NUM] = LAYOUT_ciantha_10_25u_6_thumb_keys(

    ___NUM_Q_ROW_10u___,
    ___NUM_A_ROW_10u___,
    ___NUM_Z_ROW_9u___,
    ___NUM_THUMB_6___ 
  ),

  [NAV] = LAYOUT_ciantha_10_25u_6_thumb_keys(

    ___NAV_Q_ROW_10u___,
    ___NAV_A_ROW_10u___,
    ___NAV_Z_ROW_9u___,
    ___NAV_THUMB_6___
  ),

};

#include "encoder_map.h"
#include "tap_dances.c"
#include "process_record_user.c"

//include combos.def
#include "g/keymap_combo.h"