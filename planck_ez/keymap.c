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


/*
 * Less keypresses with more key travel is better than more keypress with less key travel?
 * (prv/next tab, \"'~ keys)
 *
 * One hand shortcuts are  better than two-hand? (mod + key on same hand vs mod on one and key on another, i.e. brackets on RAISE vs on LOWER)
 * */ 
#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _COLEMAK, 
  _LOWER,
  _RAISE,
  _QWERTY,
  _RUSSIAN,
  _PLOVER,
  _ADJUST,
  _NONE
};

enum planck_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  PLOVER,
  BACKLIT,
  EXT_PLV,
  MY_QUOT,
  MY_TILD,
  T_LANG
};

#define LOWER LT(_LOWER, KC_ESC)
#define RAISE LT(_RAISE, KC_ESC)

#define RU_IY KC_Q

#define PLAYER  KC_F24
#define KC_LANG KC_F23
#define PRV_SPC KC_F22
#define NXT_SPC KC_F21
#define PRV_TAB A(G(KC_LEFT))
#define NXT_TAB A(G(KC_RIGHT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
         

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  |  -_  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |HprRgt|   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  \|  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |  "'  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Meh  | Lang |GuiDel|AltBsp|LOWER |    Space    |RAISE |CtlEnt|PrvTab|NxtTab|  ~`  |
 * `-----------------------------------------------------------------------------------'
 */

[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,          KC_Q,    KC_W,           KC_F,            KC_P,  KC_G,   KC_J,   KC_L,  KC_U,           KC_Y,    KC_SCLN, KC_MINS,
    HYPR_T(KC_RGHT), KC_A,    KC_R,           KC_S,            KC_T,  KC_D,   KC_H,   KC_N,  KC_E,           KC_I,    KC_O,    KC_BSLS,
    KC_LSFT,         KC_Z,    KC_X,           KC_C,            KC_V,  KC_B,   KC_K,   KC_M,  KC_COMM,        KC_DOT,  KC_SLSH, MY_QUOT,
    KC_MEH,          T_LANG,  LGUI_T(KC_DEL), LALT_T(KC_BSPC), LOWER, KC_SPC, KC_SPC, RAISE, RCTL_T(KC_ENT), PRV_TAB, NXT_TAB, MY_TILD
),


// NOTE - mod keys with arrows are virtually inaccessible, maybe add some mod keys for the right hand
/* Lower, lockable 
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |      | Home |  Up  | End  | PgUp |      |   %  |   7  |   8  |   9  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Hyper |      | Left | Down |Right | PgDn |   (  |   )  |   4  |   5  |   6  |  *   |
 * |------+------+------+------+------+------+------+------+------+------+-*----+------|
 * |Shift |      |      |      |      |      |      |   0  |   1  |   2  |   3  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Meh  |      | LGui | LAlt |██████|    Space    |RAISE |CtlEnt|   .  | Bspc |  +   |
 * `-----------------------------------------------------------------------------------'
 */

[_LOWER] = LAYOUT_planck_grid(
    KC_TAB,  XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX, KC_PERC, KC_7,           KC_8,    KC_9,    KC_SLSH,
    KC_HYPR, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_LPRN, KC_RPRN, KC_4,           KC_5,    KC_6,    KC_ASTR, 
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX,
    KC_MEH,  XXXXXXX, KC_LGUI, KC_LALT, _______, KC_SPC,  KC_SPC,  _______, RCTL_T(KC_ENT), KC_DOT,  KC_BSPC, KC_PLUS
),

// volume makes no sense with hardware sound card
/* Raise - F keys, brackets 
 * ,------------------------------------------------------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   [  |   ]  |       |
 * |------+------+------+------+------+------+------+------+------+------+------+-------|
 * | Hyper|  F1  |  F2  |  F3  |  F4  |  F5  |      |Player|      |   (  |   )  |       |
 * |------+------+------+------+------+------+------+------+------+------+------+-------|
 * | Shift|  F6  |  F7  |  F8  |  F9  |  F10 | PlPrv|PlyPse|PlNxt |   {  |   }  |       |
 * |------+------+------+------+------+------+------+------+------+------+------+-------|
 * | Meh  |      | LGui | LAlt |LOWER |             |██████|RCtrl |PrvSpc|NxtSpc|       |
 * `------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, XXXXXXX,
    KC_HYPR, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, PLAYER,  XXXXXXX, KC_LPRN, KC_RPRN, XXXXXXX,
    KC_LSFT, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_MPRV, KC_MPLY, KC_MNXT, KC_LCBR, KC_RCBR, XXXXXXX,
    KC_MEH,  XXXXXXX, KC_LGUI, KC_LALT, _______, XXXXXXX, XXXXXXX, _______, KC_RCTL, PRV_SPC, NXT_SPC, XXXXXXX
),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Russian
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Й  |   Ц  |   У  |   К  |   Е  |   Н  |   Г  |   Ш  |   Щ  |   З  |  -_  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   Ф  |   Ы  |   В  |   А  |   П  |   Р  |   О  |   Л  |   Д  |   Ж  |  Э   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Я  |   Ч  |   С  |   М  |   И  |   Т  |   Ь  |   Б  |   Ю  |  .,  |  "'  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Meh  |   Ë  |GuiDel|AltBsp|LOWER |    Space    |RAISE |CtlEnt|PrvTab|NxtTab|  \/  |
 * `-----------------------------------------------------------------------------------'
 */
[_RUSSIAN] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_PLOVER] = LAYOUT_planck_grid(
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
),


/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Colemk|Qwerty|Plover|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, COLEMAK, QWERTY,   PLOVER,  _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void press_key_with_level_mods(uint16_t key) {
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

  // Press and release the key
  register_code(key & 0xFF);
  unregister_code(key & 0xFF);

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
  press_key_with_level_mods(target);
}

uint16_t stored_layer = _NONE;

void set_persistent_layer(uint16_t layer) {
    stored_layer = layer;
    set_single_persistent_default_layer(layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MY_TILD:
        if (record->event.pressed) {
            override_key(record, KC_TILD, KC_GRV);
        }
        return false;
        break;
    case MY_QUOT:
        if (record->event.pressed) {
          override_key(record, KC_DQUO, KC_QUOT);
        }
        return false;
        break;
    /*    
    case T_LANG:
        if (record->event.pressed) {
          register_code(KC_LANG);
          if (stored_layer == _RUSSIAN) {
            set_persistent_layer(stored_layer);
          } else {
            set_persistent_layer(_RUSSIAN);
          }
          unregister_code(KC_LANG);
        }
        return false;
        break;
   */ 
    case QWERTY:
      if (record->event.pressed) {
        set_persistent_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_persistent_layer(_COLEMAK);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
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

void matrix_scan_user(void) {
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

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
