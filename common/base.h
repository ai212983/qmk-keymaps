#pragma once
#include QMK_KEYBOARD_H

#ifdef TAPPING_TERM
#undef TAPPING_TERM
#endif // TAPPING_TERM
#define TAPPING_TERM 50

enum {
  KC_VRSN = SAFE_RANGE,
  BASE_SAFE_RANGE
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

bool process_base_override(uint16_t keycode, keyrecord_t *record);
