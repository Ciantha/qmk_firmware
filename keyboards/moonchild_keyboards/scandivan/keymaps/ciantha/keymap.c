#include QMK_KEYBOARD_H
#include "ciantha.h"
#include "key_overrides.h"


// layout macro
#define LAYOUT_ciantha_10_75u_6_thumb_keys_8_marcro_keys(...) LAYOUT(__VA_ARGS__)

//set handedness for chordal hold
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
     LAYOUT_ciantha_10_75u_6_thumb_keys_8_marcro_keys(
          ___CHORDAL_SCANDIVAN___
    );

//actual keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ciantha_10_75u_6_thumb_keys_8_marcro_keys(
    
    ___BASE_Q_ROW_10u___, KC_F1, KC_F5,
    ___BASE_A_ROW_10u___, KC_F2, KC_F6,
    ___BASE_Z_ROW_9u___, KC_F3, KC_F7,
    ___BASE_THUMB_6___, KC_F4, KC_F8
  ),

  [NUM] = LAYOUT_ciantha_10_75u_6_thumb_keys_8_marcro_keys(

    ___NUM_Q_ROW_10u___, KC_F9, KC_TRNS,
    ___NUM_A_ROW_10u___, KC_F10, KC_TRNS,
    ___NUM_Z_ROW_9u___, KC_F11, KC_TRNS,
    ___NUM_THUMB_6___ , KC_F12, KC_TRNS
  ),

  [NAV] = LAYOUT_ciantha_10_75u_6_thumb_keys_8_marcro_keys(

    ___NAV_Q_ROW_10u___, KC_TRNS, KC_TRNS,
    ___NAV_A_ROW_10u___, KC_TRNS, KC_TRNS,
    ___NAV_Z_ROW_9u___, KC_TRNS, KC_TRNS,
    ___NAV_THUMB_6___, KC_TRNS, KC_TRNS
  ),

};

#include "encoder_map.h"
#include "tap_dances.c"
#include "process_record_user.c"

//include combos.def
#include "g/keymap_combo.h"