#include "layers.h"

uint16_t active_layer = _COLEMAK;
uint16_t prev_layer = _COLEMAK;

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