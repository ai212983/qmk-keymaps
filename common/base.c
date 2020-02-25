#include QMK_KEYBOARD_H
#include "base.h"
#include "version.h"

bool process_base_override(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) {
    return true;
  }

  switch (keycode) {
    case KC_VRSN:
      SEND_STRING("QMK: " QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Keyset: " KEYSET_VERSION "/" KEYSET_DATETIME);
      return false;
    }
    return true;
}
