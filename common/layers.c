#include "layers.h"

bool process_layers_override(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) {
    return true;
  }
  
  switch (keycode) {
    case QWERTY:
      set_persistent_layer(_QWERTY);
      return false;

    case RUSSIAN:
      set_persistent_layer(_RUSSIAN);
      return false;

    case WORKMAN:
      set_persistent_layer(_WORKMAN);
      return false;
  }
  
  return true;
}

uint16_t active_layer = _WORKMAN;
uint16_t prev_layer = _WORKMAN;

void set_persistent_layer(uint16_t layer) {
  prev_layer = active_layer;
  set_single_persistent_default_layer(layer);
  active_layer = layer;
}

uint16_t get_active_layer() {
  return active_layer;
}

void set_prev_layer() {
  set_persistent_layer(prev_layer);
}
