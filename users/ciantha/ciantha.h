#include "quantum.h"
// hrm
#define HRM_Z RGUI_T(KC_Z)
#define HRM_S LALT_T(KC_S)
#define HRM_D LSFT_T(KC_D)
#define HRM_F LCTL_T(KC_F)
#define HRM_J RCTL_T(KC_J)
#define HRM_K RSFT_T(KC_K)
#define HRM_L LALT_T(KC_L)
#define HRM_DOT LGUI_T(KC_DOT)
// text manip
#define COPY C(KC_C)
#define PASTE C(KC_V)
#define CUT C(KC_X)
#define UNDO C(KC_Z)
// layer keys
#define LT_A LT(NAV, KC_A)
#define LT_BSPC LT(NUM, KC_BSPC)

// layer names
enum layers { BASE, NUM, NAV, META };

// custom keycode names
enum custom_keycodes {
    KC_OE = SAFE_RANGE,
    KC_AE,
    KC_AA,
};

// tap dance names
enum tap_dances { CT_PLS, CT_PRINT_RALT };

// portable keymaps
// chordal hold
#define ___CHORDAL_11u6t_stag___ 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', '*', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', '*', '*', '*', '*', '*', '*'
#define ___CHORDAL_11u4t_stag___ 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', '*', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', '*', '*', '*', '*'
#define ___CHORDAL_10_25u6t_stag___ 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', '*', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', '*', '*', '*', '*', '*', '*'
#define ___CHORDAL_SCANDIVAN___ 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', '*', '*', '*', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', '*', '*', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*' 

// base
#define ___BASE_ORACLE_9_keys___ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4
#define ___BASE_Q_ROW_11u___ KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NO
#define ___BASE_Q_ROW_10u___ KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P
#define ___BASE_A_ROW_10u___ LT_A, HRM_S, HRM_D, HRM_F, KC_G, KC_H, HRM_J, HRM_K, HRM_L, KC_OE
#define ___BASE_Z_ROW_10u___ HRM_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, HRM_DOT, KC_NO
#define ___BASE_Z_ROW_9u___ HRM_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, HRM_DOT
#define ___BASE_Z_ROW_extra_b___ HRM_Z, KC_X, KC_C, KC_V, KC_B, KC_B, KC_N, KC_M, KC_COMM, HRM_DOT
#define ___BASE_THUMB_6___ KC_LCTL, KC_LALT, LT_BSPC, KC_SPACE, TD(CT_PRINT_RALT), KC_LGUI
#define ___BASE_THUMB_4___ KC_LALT, LT_BSPC, KC_SPACE, TD(CT_PRINT_RALT)

// num
#define ___NUM_ORACLE_9_keys___ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F5, KC_F6, KC_F7, KC_F8
#define ___NUM_Q_ROW_11u___ KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_GRV, KC_BSLS, KC_NO
#define ___NUM_Q_ROW_10u___ KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_GRV, KC_BSLS
#define ___NUM_A_ROW_10u___ KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0
#define ___NUM_Z_ROW_10u___ KC_MINS, KC_UNDS, KC_LT, KC_LPRN, KC_LCBR, KC_RCBR, KC_RPRN, KC_GT, TD(CT_PLS), KC_NO
#define ___NUM_Z_ROW_9u___ KC_MINS, KC_UNDS, KC_LT, KC_LPRN, KC_LCBR, KC_RCBR, KC_RPRN, KC_GT, TD(CT_PLS)
#define ___NUM_Z_ROW_extra_b___ KC_MINS, KC_UNDS, KC_LT, KC_LPRN, KC_LCBR, KC_TRNS, KC_RCBR, KC_RPRN, KC_GT, TD(CT_PLS)
#define ___NUM_THUMB_6___ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define ___NUM_THUMB_4___ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

// nav
#define ___NAV_ORACLE_9_keys___ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_F9, KC_F10, KC_F11, KC_F12
#define ___NAV_Q_ROW_11u___ KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT
#define ___NAV_Q_ROW_10u___ KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT
#define ___NAV_A_ROW_10u___ KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define ___NAV_Z_ROW_10u___ KC_TRNS, CUT, COPY, PASTE, UNDO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, UG_TOGG
#define ___NAV_Z_ROW_9u___ KC_TRNS, CUT, COPY, PASTE, UNDO, KC_TRNS, KC_TRNS, KC_TRNS, UG_TOGG
#define ___NAV_Z_ROW_extra_b___ KC_TRNS, CUT, COPY, PASTE, UNDO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, UG_TOGG
#define ___NAV_THUMB_6___ KC_TRNS, KC_CAPS, KC_LBRC, KC_RBRC, KC_NUM, KC_TRNS
#define ___NAV_THUMB_4___ KC_CAPS, KC_LBRC, KC_RBRC, KC_NUM