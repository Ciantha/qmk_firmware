#ifdef KEY_OVERRIDE_ENABLE
//key overrides
const key_override_t semi_colon_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN);
const key_override_t colon_key_override = ko_make_basic(MOD_MASK_SHIFT, HRM_DOT, KC_COLN);


//all key overrides
const key_override_t *key_overrides[] = {
    &semi_colon_key_override,
    &colon_key_override
};
#endif