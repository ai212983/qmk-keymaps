#include "common.h"

bool process_common_override(uint16_t keycode, keyrecord_t *record) {
  return process_shift_override(keycode, record) && 
         process_russian_override(keycode, record) &&
         process_base_override(keycode, record);
}
