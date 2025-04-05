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

//layer names
enum layers{
  BASE,
  NUM,
  NAV,
  META
};

//custom keycode names
enum custom_keycodes {
  KC_OE = SAFE_RANGE,
  KC_AE,
  KC_AA,
};

//tap dance names
enum tap_dances{
  CT_PLS,
  CT_PRINT_RALT
};

//to set up tap hold tapdances
typedef struct {
  uint16_t tap;
  uint16_t hold;
  uint16_t held;
} tap_dance_tap_hold_t;



//set handedness for chordal hold
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_ciantha_11u_6_thumb_keys(
        'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',  
          'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 
            'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 
                       '*', '*', '*',  '*', '*', '*'
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

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
  tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

  if (state->pressed) {
      if (state->count == 1
#ifndef PERMISSIVE_HOLD
          && !state->interrupted
#endif
      ) {
          register_code16(tap_hold->hold);
          tap_hold->held = tap_hold->hold;
      } else {
          register_code16(tap_hold->tap);
          tap_hold->held = tap_hold->tap;
      }
  }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
  tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

  if (tap_hold->held) {
      unregister_code16(tap_hold->held);
      tap_hold->held = 0;
  }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
  { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

void print_ralt(tap_dance_state_t *state, void *user_data) {
  if (state->count ==1) {
      tap_code(KC_PSCR);
  } else if (state->count ==2) {
    set_oneshot_mods(MOD_BIT(KC_RALT));
  } else {
    clear_oneshot_mods();
  }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case TD(CT_PRINT_RALT):
          return 200;
      default:
          return TAPPING_TERM;
  }
}

//all tap dances
tap_dance_action_t tap_dance_actions[] = {
  [CT_PLS] = ACTION_TAP_DANCE_TAP_HOLD(KC_PLUS, KC_EQL),
  [CT_PRINT_RALT] = ACTION_TAP_DANCE_FN(print_ralt)
};

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
    case TD(CT_PLS):  // list all tap dance keycodes with tap-hold configurations
    action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
    if (!record->event.pressed && action->state.count && !action->state.finished) {
        tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
        tap_code16(tap_hold->tap);
    }
  }
  return true;
};

//include combos.def
#include "g/keymap_combo.h"
