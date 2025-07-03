/* Copyright 2021 projectcain
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "ciantha.h"
#include "key_overrides.h"


// layout macro
#define LAYOUT_ciantha_11u_4_thumb_keys(...) LAYOUT_split_2space(__VA_ARGS__)

//set handedness for chordal hold
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_ciantha_11u_4_thumb_keys(
      ___CHORDAL_11u4t_stag___
    );

//actual keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ciantha_11u_4_thumb_keys(
    
    ___BASE_Q_ROW_11u___,
    ___BASE_A_ROW_10u___,
    ___BASE_Z_ROW_10u___,
    ___BASE_THUMB_4___
  ),

  [NUM] = LAYOUT_ciantha_11u_4_thumb_keys(

    ___NUM_Q_ROW_11u___,
    ___NUM_A_ROW_10u___,
    ___NUM_Z_ROW_10u___,
    ___NUM_THUMB_4___ 
  ),

  [NAV] = LAYOUT_ciantha_11u_4_thumb_keys(

    ___NAV_Q_ROW_11u___,
    ___NAV_A_ROW_10u___,
    ___NAV_Z_ROW_10u___,
    ___NAV_THUMB_4___
  ),

};

#include "encoder_map.h"
#include "tap_dances.c"
#include "process_record_user.c"

//include combos.def
#include "g/keymap_combo.h"
