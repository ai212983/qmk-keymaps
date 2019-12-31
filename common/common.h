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
  KC_VRSN,
  COMMON_SAFE_RANGE
};

enum common_layers {
    _COLEMAK,
    _QWERTY,
    _RUSSIAN,
    _LOWER,
    _RAISE,
    _PLOVER,
    _COMMON_LAYERS
};

#define LOWER LT(_LOWER, KC_BSPC)
#define RAISE LT(_RAISE, KC_SPC)

#define PLAYER  KC_F24
#define KC_LANG KC_F23
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
