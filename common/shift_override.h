#pragma once
#include "layers.h"

enum {
  MY_QUOT = LAYERS_SAFE_RANGE,
  MY_TILD,
  SHIFT_SAFE_RANGE
};

void override_key(keyrecord_t* record, uint16_t normal, uint16_t shifted);
bool process_shift_override(uint16_t keycode, keyrecord_t *record);
