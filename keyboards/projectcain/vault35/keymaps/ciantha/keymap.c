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

//set handedness for chordal hold
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_ciantha_11u_6_thumb_keys(
      ___CHORDAL_11u6t_stag___
    );

//actual keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ciantha_11u_6_thumb_keys(
    
    ___BASE_Q_ROW_11u___,
    ___BASE_A_ROW_10u___,
    ___BASE_Z_ROW_10u___,
    ___BASE_THUMB_6___
  ),

  [NUM] = LAYOUT_ciantha_11u_6_thumb_keys(

    ___NUM_Q_ROW_11u___,
    ___NUM_A_ROW_10u___,
    ___NUM_Z_ROW_10u___,
    ___NUM_THUMB_6___ 
  ),

  [NAV] = LAYOUT_ciantha_11u_6_thumb_keys(

    ___NAV_Q_ROW_11u___,
    ___NAV_A_ROW_10u___,
    ___NAV_Z_ROW_10u___,
    ___NAV_THUMB_6___
  ),

};

#include "encoder_map.h"
#include "tap_dances.c"

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    #ifdef TAP_DANCE_ENABLE
      case TD(CT_PRINT_RALT):
          return 200;
          #endif
      default:
          return TAPPING_TERM;
  }
}

//process record user, creating of custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  tap_dance_action_t *action;

  switch (keycode) {
    case KC_OE:
    if (record->event.pressed) {
      register_code(KC_RALT);
      tap_code(KC_O);
      unregister_code(KC_RALT);
    }
    break;
    case KC_AE:
    if (record->event.pressed) {
        register_code(KC_RALT);
        tap_code(KC_A);
        unregister_code(KC_RALT);
    } 
    break;
    case KC_AA:
    if (record->event.pressed) {
        register_code(KC_RALT);
        tap_code(KC_W);
        unregister_code(KC_RALT);
    } 
    break;
    #ifdef TAP_DANCE_ENABLE
    case TD(CT_PLS):  // list all tap dance keycodes with tap-hold configurations
    action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
    if (!record->event.pressed && action->state.count && !action->state.finished) {
        tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
        tap_code16(tap_hold->tap);
    }
    #endif
  }
  return true;
};

//include combos.def
#include "g/keymap_combo.h"
