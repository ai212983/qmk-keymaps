#pragma once
#include "base.h"

enum {
  WORKMAN = BASE_SAFE_RANGE,
  RUSSIAN,
  GAMING,
  LAYERS_SAFE_RANGE
};

enum {
    _WORKMAN,
    _RUSSIAN,
    _LOWER,
    _RAISE,
    _ADJUST,
    _GAMING,
    _LAYERS_SAFE_RANGE
};

bool process_layers_override(uint16_t keycode, keyrecord_t *record);
void set_persistent_layer(uint16_t layer);
uint16_t get_active_layer(void);
void set_prev_layer(void);
