#include "shift_override.h"

void handle_key_with_level_mods(uint16_t key, bool is_pressed) {
  const uint8_t interesting_mods = MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT) | MOD_BIT(KC_RALT);

  // Save the state
  const uint8_t real_mods = get_mods();
  const uint8_t weak_mods = get_weak_mods();
  const uint8_t macro_mods = get_macro_mods();

  uint8_t target_mods = (key >> 8) & (QK_MODS_MAX >> 8);
  // The 5th bit indicates that it's a right hand mod,
  // which needs some fixup
  if (target_mods & 0x10) {
    target_mods &= 0xF;
    target_mods <<= 4;
  }

  // Clear the mods that we are potentially going to modify,
  del_mods(interesting_mods);
  del_weak_mods(interesting_mods);
  del_macro_mods(interesting_mods);

  // Enable the mods that we need
  add_mods(target_mods & interesting_mods);
  if (is_pressed) {
      unregister_code16(key & 0xFF); // ErgoDox EZ won't work without this
      register_code16(key & 0xFF);
  } else {
      unregister_code16(key & 0xFF);
  }

  // Restore the previous state
  set_mods(real_mods);
  set_weak_mods(weak_mods);
  set_macro_mods(macro_mods);

  send_keyboard_report();
}

void override_key(keyrecord_t* record, uint16_t normal, uint16_t shifted) {
  const uint8_t shift = MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT);
  bool shift_pressed = keyboard_report->mods & shift;
  const uint16_t target = shift_pressed ? shifted : normal;
  uint8_t keycode = target & 0xFF;
  if (keycode == KC_NO) {
    return;
  }
  handle_key_with_level_mods(target, record->event.pressed);
}

bool process_shift_override(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MY_TILD:
        override_key(record, KC_TILD, KC_GRV);
        return false;
    case MY_QUOT:
        override_key(record, KC_DQUO, KC_QUOT);
        return false;
  }
  return true;
}
