#ifdef TAP_DANCE_ENABLE
//to set up tap hold tapdances
typedef struct {
  uint16_t tap;
  uint16_t hold;
  uint16_t held;
} tap_dance_tap_hold_t;


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

//all tap dances
tap_dance_action_t tap_dance_actions[] = {
    [CT_PLS] = ACTION_TAP_DANCE_TAP_HOLD(KC_PLUS, KC_EQL),
    [CT_PRINT_RALT] = ACTION_TAP_DANCE_FN(print_ralt)
  };
  #endif