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