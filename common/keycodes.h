#pragma once
#include QMK_KEYBOARD_H

enum common_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  PLOVER,
  EXT_PLV,
  MY_QUOT,
  MY_TILD,
  T_LANG,
  COMMON_SAFE_RANGE
};

#define LOWER LT(_LOWER, KC_ESC)
#define RAISE LT(_RAISE, KC_ESC)

#define PLAYER  KC_F24
#define KC_LANG KC_F23
#define PRV_SPC KC_F22
#define NXT_SPC KC_F21
#define PRV_TAB A(G(KC_LEFT))
#define NXT_TAB A(G(KC_RIGHT))
