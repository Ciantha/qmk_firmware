#include QMK_KEYBOARD_H
enum layers {
  _DEFAULT,
  _LOWER,
  _RAISE,
  _FN
};

enum custom_keycodes {
    PRKL = SAFE_RANGE,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FN MO(_FN)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Default
 * ,-------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |     P    
 * |-------------------------------------------------------------------------|
 * |    A   |   S  |   D  |   F  |   G  |   H  |   J  |   K  |       L       | 
 * |-------------------------------------------------------------------------|
 * |     Z     |   X  |   C  |   V  |   B  |   N  |   M  |       ,    |  .   | 
 * |-------------------------------------------------------------------------|
 *        |   ctrl  |   alt  |   bspc  |   space  |   mo2  |   gui  |         
 *        |---------------------------------------------------------'
 */
[_DEFAULT] = LAYOUT_all(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,  KC_H,    KC_J,    KC_K,    KC_L,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,
    KC_LCTL, KC_LALT, KC_BSPC, KC_SPC,  FN,    KC_LGUI
),

/* Default
 * ,-------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |     P    
 * |-------------------------------------------------------------------------|
 * |    A   |   S  |   D  |   F  |   G  |   H  |   J  |   K  |       L       | 
 * |-------------------------------------------------------------------------|
 * |     Z     |   X  |   C  |   V  |   B  |   N  |   M  |       ,    |  .   | 
 * |-------------------------------------------------------------------------|
 *        |   ctrl  |   alt  |   bspc  |   space  |   mo2  |   gui  |         
 *        |---------------------------------------------------------'
 */
[_LOWER] = LAYOUT_all(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,  KC_H,    KC_J,    KC_K,    KC_L,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,
    KC_LCTL, KC_LALT, KC_BSPC, KC_SPC,  FN,    KC_LGUI
),

/* Default
 * ,-------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |     P    
 * |-------------------------------------------------------------------------|
 * |    A   |   S  |   D  |   F  |   G  |   H  |   J  |   K  |       L       | 
 * |-------------------------------------------------------------------------|
 * |     Z     |   X  |   C  |   V  |   B  |   N  |   M  |       ,    |  .   | 
 * |-------------------------------------------------------------------------|
 *        |   ctrl  |   alt  |   bspc  |   space  |   mo2  |   gui  |         
 *        |---------------------------------------------------------'
 */
[_RAISE] = LAYOUT_all(
   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,  KC_H,    KC_J,    KC_K,    KC_L,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,
    KC_LCTL, KC_LALT, KC_BSPC, KC_SPC,  FN,    KC_LGUI
),

 /* Default
 * ,-------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |     P    
 * |-------------------------------------------------------------------------|
 * |    A   |   S  |   D  |   F  |   G  |   H  |   J  |   K  |       L       | 
 * |-------------------------------------------------------------------------|
 * |     Z     |   X  |   C  |   V  |   B  |   N  |   M  |       ,    |  .   | 
 * |-------------------------------------------------------------------------|
 *        |   ctrl  |   alt  |   bspc  |   space  |   mo2  |   gui  |         
 *        |---------------------------------------------------------'
 */
[_FN] = LAYOUT_all(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,  KC_H,    KC_J,    KC_K,    KC_L,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,
    KC_LCTL, KC_LALT, KC_BSPC, KC_SPC,  FN,    KC_LGUI
),


};

