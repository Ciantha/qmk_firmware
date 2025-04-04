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

//shorter names for home rows and layers
#define HRM_Z RGUI_T(KC_Z)
#define HRM_S LALT_T(KC_S)
#define HRM_D LSFT_T(KC_D)
#define HRM_F LCTL_T(KC_F)
#define HRM_J RCTL_T(KC_J)
#define HRM_K RSFT_T(KC_K)
#define HRM_L LALT_T(KC_L)
#define HRM_DOT LGUI_T(KC_DOT)
#define LT_A LT(NAV, KC_A)
#define LT_BSPC LT(NUM, KC_BSPC)
#define COPY C(KC_C)
#define PASTE C(KC_V)
#define CUT C(KC_X)
#define UNDO C(KC_Z)

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
    LAYOUT_split_4space(
        'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',  
          'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 
            'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 
                       '*', '*', '*',  '*', '*', '*'
    );

//actual keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_4space(

    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_NO,
    LT_A,    HRM_S,   HRM_D,   HRM_F,   KC_G,    KC_H,    HRM_J,   HRM_K,   HRM_L,    KC_OE,
    HRM_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, HRM_DOT,  KC_NO,
           KC_LCTL,  KC_LALT, LT_BSPC,         KC_SPACE,  TD(CT_PRINT_RALT),  KC_LGUI
  ),

  [NUM] = LAYOUT_split_4space(

    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_GRV,          KC_BSLS, KC_NO,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,            KC_0, 
    KC_MINS, KC_UNDS, KC_LT,   KC_LPRN, KC_LCBR, KC_RCBR, KC_RPRN, KC_GT,   TD(CT_PLS), KC_NO,
                 KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS
  ),

  [NAV] = LAYOUT_split_4space(

    KC_TRNS,  KC_TRNS,  KC_UP,    KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  QK_BOOT,
    KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RIGHT,  KC_END,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,     
    KC_TRNS,  CUT,      COPY,     PASTE,     UNDO,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  UG_TOGG,
                KC_TRNS,     KC_CAPS,   KC_LBRC,      KC_RBRC,        KC_NUM,    KC_TRNS
  ),

};

//encoder map, not that I tend to build with those
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
      [BASE] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
      [NUM]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
      [NAV]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif

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


//key overrides
const key_override_t semi_colon_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN);
const key_override_t colon_key_override = ko_make_basic(MOD_MASK_SHIFT, HRM_DOT, KC_COLN);


//all key overrides
const key_override_t *key_overrides[] = {
	&semi_colon_key_override,
  &colon_key_override
};

//include combos.def
#include "g/keymap_combo.h"
