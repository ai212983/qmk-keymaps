#include QMK_KEYBOARD_H
#include "common.h"
#include "version.h"

bool process_common_override(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_VRSN:
            if (record->event.pressed) {
                SEND_STRING ("QMK: " QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Keyset: " KEYSET_VERSION "/" KEYSET_DATETIME);
            }
            return false;
    }
    return true;
}

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
