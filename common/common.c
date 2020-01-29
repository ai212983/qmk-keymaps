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

// Tap Dance

void dance_dot_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_DOT);
  } else {
    send_unicode_hex_string ("2026");
  }
}

void dance_dot_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_DOT);
  }
}

void dance_mins_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_MINS);
  } else if (state->count == 2) {
    send_unicode_hex_string ("2014"); // em dash (longer)
  } else {
    send_unicode_hex_string ("2013"); // en dash (shorter)
  }
}

void dance_mins_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_MINS);
  }
}
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_DOT_ELLIPSIS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_dot_finished, dance_dot_reset),
  [TD_MINS_DASH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_mins_finished, dance_mins_reset)
};
