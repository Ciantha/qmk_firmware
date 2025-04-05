//encoder map, not that I tend to build with those
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
      [BASE] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
      [NUM]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
      [NAV]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif