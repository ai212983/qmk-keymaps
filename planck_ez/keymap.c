/* 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "common.h"
#include "russian.h"
#include "shift_override.h"
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_keycodes {
  GAMING = COMMON_SAFE_RANGE
};

enum planck_layers {
  _GAMING = _COMMON_SAFE_RANGE
};

/* ⌘ - GUI, ^ - Ctrl, ⌥ - Alt, ⇧ - Shift
 * Hyper - Ctrl + Shift + Alt + Gui
 * Meh - Ctrl + Shift + Alt
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Workman
 * ,-----------------------------------------------------------------------------------.
 * |      |   Q  |   D  |   R  |   W  |   B  |  J   |  F   |  U   |  P   |  ;   |  \|  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Hyper |   A  |   S  |   H  |   T  |   G  |  Y   |  N   |  E   |  O   |  I   |  "'  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RShift|   Z  |   X  |   M  |   C  |   V  |  K   |  L   |  ,   |  .   |  /?  |  ~`  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  ⌥   |      | ^/Del| ⌘/Esc|LWRBsp|   Meh/Tab   |RAISpc|⌥/Ent |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_WORKMAN] = LAYOUT_planck_grid(
  XXXXXXX, KC_Q,    KC_D,           KC_R,           KC_W,  KC_B,    KC_J,    KC_F,  KC_U,           KC_P,    KC_SCLN, KC_BSLS,
  KC_HYPR, KC_A,    KC_S,           KC_H,           KC_T,  KC_G,    KC_Y,    KC_N,  KC_E,           KC_O,    KC_I,    MY_QUOT,
  KC_RSFT, KC_Z,    KC_X,           KC_M,           KC_C,  KC_V,    KC_K,    KC_L,  KC_COMM,        KC_DOT,  KC_SLSH, MY_TILD,
  KC_RALT, XXXXXXX, LCTL_T(KC_DEL), LGUI_T(KC_ESC), LOWER, MEH_TAB, MEH_TAB, RAISE, RALT_T(KC_ENT), XXXXXXX, XXXXXXX, XXXXXXX
),

/* Russian
 * ,-----------------------------------------------------------------------------------.
 * |   Ц  |   Ч  |   А  |   К  |   Ы  |   М  |  В   |  Л   |  З   |  Ш   |  Й   |  Ф   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Ъ  |   П  |   И  |   О  |   Е  |   У  |  Р   |  Н   |  Т   |  С   |  Б   |  Х   |  - we do not need HYPER in Russian, it won't work anyway
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RShift|   Э  |   Ю  |   Ь  |   Я  |  .?  |  ,/  |  Г   |  Д   |  Ж   |  Щ   |  "'  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | ^/Del| ⌘/Esc|LWRBsp|   Meh/Tab   |RAISpc|⌥/Ent |  Ë   |  /?  |  \|  |
 * `-----------------------------------------------------------------------------------'
 */
[_RUSSIAN] = LAYOUT_planck_grid(
  RU_C,    RU_CH,   RU_A,    RU_K,    RU_Y,    RU_M,    RU_V,    RU_L,    RU_Z,    RU_SH,   RU_IY,   RU_F,
  RU_HS,   RU_P,    RU_I,    RU_O,    RU_E,    RU_U,    RU_R,    RU_N,    RU_T,    RU_S,    RU_B,    RU_H,
  _______, RU_AE,   RU_YU,   RU_SS,   RU_YA,   RU_DOT,  RU_COMM, RU_G,    RU_D,    RU_ZH,   RU_SC,   MY_QUOT,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, RU_YO,   KC_SLSH, KC_BSLS
),

/* Lower - navigation and numpad
 * ,-----------------------------------------------------------------------------------.
 * |      |      | Home |  Up  | End  | PgUp |   %  |   7  |   8  |   9  |   *  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Hyper |      | Left | Down |Right | PgDn |      |   4  |   5  |   6  |   -  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RShift|      |      |      |      |      |   0  |   1  |   2  |   3  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | ^/Del| ⌘/Esc|██████|   Meh/Tab   |RAISpc|⌥+Ent |   .  |  Bsp |  =   |
 * `-----------------------------------------------------------------------------------'
 * Ctrl is shifted for better reachability by pinky
 */
[_LOWER] = LAYOUT_planck_grid(
  _______, XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_PERC, KC_7,    KC_8,         KC_9,   KC_ASTR, KC_SLSH,
  _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX, KC_4,    KC_5,         KC_6,   KC_MINS, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_0,    KC_1,    KC_2,         KC_3,   KC_PLUS, XXXXXXX,
  _______, _______, _______, _______, _______, _______, _______, _______, RALT(KC_ENT), KC_DOT, KC_BSPC, KC_EQL
),

/* Raise - symbols
 * ,-----------------------------------------------------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |  ^   |   [  |  ]   |PrvSpc|NxtSpc|AppLnc|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Hyper|      |      |   +  |   -  |   =  |  *   |   (  |  )   |PrvTab|NxtTab|AppSwt|  
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RShift|      |      |      |   _  |      |  &   |   {  |  }   |      |      |MsnCtl|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | ^/Del| ⌘/Esc|LWRBsp|   Meh/Tab   |██████|⌥/Ent |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, PRV_SPC, NXT_SPC, APP_LNC,
  _______, XXXXXXX, XXXXXXX, KC_PLUS, KC_MINS, KC_EQL,  KC_ASTR, KC_LPRN, KC_RPRN, PRV_TAB, NXT_TAB, APP_SWT,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, XXXXXXX, KC_AMPR, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, MSN_CTL,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),


/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |Versn | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|      |Wrkman|Rssian|Qwerty|Gaming|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
  KC_VRSN, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  _______, WORKMAN, RUSSIAN, GAMING,   _______, _______, _______,
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* Gaming
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |      |      |  Esc |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   2  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |      |      | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LShift|   3  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |      |      | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCtrl|   4  |   5  |   6  | Space|             |      |      |      |      |WRKMAN|
 * `-----------------------------------------------------------------------------------'
 */
[_GAMING] = LAYOUT_planck_grid(
  KC_GRV,  KC_1, KC_Q, KC_W, KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    XXXXXXX, XXXXXXX, KC_ESC,
  KC_TAB,  KC_2, KC_A, KC_S, KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    XXXXXXX, XXXXXXX, KC_BSPC,
  KC_LSFT, KC_3, KC_Z, KC_X, KC_C,   KC_V,    KC_B,    KC_N,    KC_M,    XXXXXXX, XXXXXXX, KC_ENT,
  KC_LCTL, KC_4, KC_5, KC_6, KC_SPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, WORKMAN
)

};

// ----- Helpers

void indicate_layer(uint8_t layer) {
  uint8_t left = 0;
  uint8_t right = 0;
  
  switch (layer) {
    case _RUSSIAN: 
      right = 50;
      break;

    case _GAMING:
      left = 25;
      right = 25;
      break;

    default:
      break;
  }
  planck_ez_left_led_level(left);
  planck_ez_right_led_level(right);
}

// ----- Overridden defaults

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void matrix_init_user(void) {
  set_unicode_input_mode(UC_OSX); // Mac OSX, supported values are UC_LNX, UC_WIN, UC_WINC, etc. See wiki for details
}

void matrix_scan_user(void) {
  indicate_layer(get_active_layer());
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
      if (muse_counter) {
        stop_all_notes();
        muse_counter = 0;
      }
    }
  #endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_common_override(keycode, record)) {
    return false;
  }

  switch (keycode) {
    case GAMING:
      set_persistent_layer(_GAMING);
      return false;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
          #ifdef AUDIO_ENABLE
            static bool play_sound = false;
          #endif
          if (active) {
            #ifdef AUDIO_ENABLE
              if (play_sound) { PLAY_SONG(plover_song); }
            #endif
            layer_on(_ADJUST);
          } else {
            #ifdef AUDIO_ENABLE
              if (play_sound) { PLAY_SONG(plover_gb_song); }
            #endif
            layer_off(_ADJUST);
          }
          #ifdef AUDIO_ENABLE
            play_sound = true;
          #endif
          break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
