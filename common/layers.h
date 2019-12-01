#pragma once
#include QMK_KEYBOARD_H

enum common_layers {
  _COLEMAK, 
  _LOWER,
  _RAISE,
  _QWERTY,
  _RUSSIAN,
  _PLOVER,
  _COMMON_LAYERS
};

void set_persistent_layer(uint16_t layer);
uint16_t get_active_layer(void);
void set_prev_layer(void);