#pragma once
#include QMK_KEYBOARD_H
#include "common.h"

void override_key(keyrecord_t* record, uint16_t normal, uint16_t shifted);
bool process_shift_override(uint16_t keycode, keyrecord_t *record);