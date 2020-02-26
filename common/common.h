#pragma once
#include "russian.h"
#include "layers.h"

enum keycodes {
  COMMON_SAFE_RANGE = RUSSIAN_SAFE_RANGE
};

enum layers {
  _COMMON_SAFE_RANGE = _LAYERS_SAFE_RANGE
};

bool process_common_override(uint16_t keycode, keyrecord_t *record);

