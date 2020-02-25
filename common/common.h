#pragma once
#include QMK_KEYBOARD_H

#ifdef TAPPING_TERM
#undef TAPPING_TERM
#endif // TAPPING_TERM
#define TAPPING_TERM 50

enum common_keycodes {
  WORKMAN = SAFE_RANGE,
  QWERTY,
  RUSSIAN,
  PLOVER,
  EXT_PLV,
  MY_QUOT,
  MY_TILD,
  KC_VRSN,
  COMMON_SAFE_RANGE
};

enum common_layers {
    _WORKMAN,
    _QWERTY,
    _RUSSIAN,
    _LOWER,
    _RAISE,
    _ADJUST,
    _PLOVER,
    _COMMON_LAYERS
};

#define LOWER LT(_LOWER, KC_BSPC)
#define RAISE LT(_RAISE, KC_SPC)
#define MEH_TAB MEH_T(KC_TAB)

#define APP_SWT KC_F20
#define APP_LNC KC_F16
#define MSN_CTL KC_F17
#define PRV_SPC KC_F18
#define NXT_SPC KC_F19
#define PRV_TAB A(G(KC_LEFT))
#define NXT_TAB A(G(KC_RIGHT))

bool process_common_override(uint16_t keycode, keyrecord_t *record);
void set_persistent_layer(uint16_t layer);
uint16_t get_active_layer(void);
void set_prev_layer(void);


// Tap Dance

enum {
  TD_DOT_ELLIPSIS = 0,
  TD_MINS_DASH,
  TD_S_SS,
  TD_O_OE,
  TD_A_AE,
  TD_U_UE
};

#define TD_DOT TD(TD_DOT_ELLIPSIS)
#define TD_MINS TD(TD_MINS_DASH)

