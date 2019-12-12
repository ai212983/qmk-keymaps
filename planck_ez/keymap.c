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
#include "common.h"
#include "russian.h"
#include "shift_override.h"
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _ADJUST = _COMMON_LAYERS
};

enum planck_keycodes {
  BACKLIT = RUSSIAN_SAFE_RANGE
};

/* ⌘ - GUI, ^ - Ctrl, ⌥ - Alt, ⇧ - Shift
 * Hyper - Ctrl + Shift + Alt + Gui
 * Meh - Ctrl + Shift + Alt
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
         

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |HprRgt|   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  \|  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |  /?  |  "'  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Meh  | Lang | ^/Del| ⌘/Bsp|LOWER |    Space    |RAISE |⌥/Ent |PrvTab|NxtTab|  ~`  |
 * `-----------------------------------------------------------------------------------'
 */

[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,          KC_Q,    KC_W,           KC_F,            KC_P,  KC_G,   KC_J,   KC_L,  KC_U,           KC_Y,    KC_SCLN, XXXXXXX,
    HYPR_T(KC_RGHT), KC_A,    KC_R,           KC_S,            KC_T,  KC_D,   KC_H,   KC_N,  KC_E,           KC_I,    KC_O,    KC_BSLS,
    KC_LSFT,         KC_Z,    KC_X,           KC_C,            KC_V,  KC_B,   KC_K,   KC_M,  KC_COMM,        KC_DOT,  KC_SLSH, MY_QUOT,
    KC_MEH,          T_LANG,  LCTL_T(KC_DEL), LGUI_T(KC_BSPC), LOWER, KC_SPC, KC_SPC, RAISE, RALT_T(KC_ENT), PRV_TAB, NXT_TAB, MY_TILD
),

/* Russian
 * ,-----------------------------------------------------------------------------------.
 * |   Ъ  |   Й  |   Ц  |   У  |   К  |   Е  |   Н  |   Г  |   Ш  |   Щ  |   З  |  Х   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Right |   Ф  |   Ы  |   В  |   А  |   П  |   Р  |   О  |   Л  |   Д  |   Ж  |  Э   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift |   Я  |   Ч  |   С  |   М  |   И  |   Т  |   Ь  |   Б  |   Ю  |  .,  |  "'  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Ë  | Lang |  Del |  Bsp |LOWER |    Space    |RAISE | Enter|PrvTab|NxtTab|  \/  |
 * `-----------------------------------------------------------------------------------'
 */
[_RUSSIAN] = LAYOUT_planck_grid(
    RU_HS,   RU_IY,  RU_C,   RU_U,    RU_K,  RU_E,   RU_N,   RU_G,    RU_SH,  RU_SC,   RU_Z,    RU_H,
    KC_RGHT, RU_F,   RU_Y,   RU_V,    RU_A,  RU_P,   RU_R,   RU_O,    RU_L,   RU_D,    RU_ZH,   RU_AE,
    KC_LSFT, RU_YA,  RU_CH,  RU_S,    RU_M,  RU_I,   RU_T,   RU_SS,   RU_B,   RU_YU,   RU_DOT,  MY_QUOT,
    RU_YO,   T_LANG, KC_DEL, KC_BSPC, LOWER, KC_SPC, KC_SPC, RAISE,   KC_ENT, PRV_TAB, NXT_TAB, RU_SLSH
),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |LOWER |    Space    |RAISE | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),


/* Lower, lockable - navigation and numpad
 * ,-----------------------------------------------------------------------------------.
 * |  =   |  +   | Home |  Up  | End  | PgUp |      |   %  |   7  |   8  |   9  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Hyper |      | Left | Down |Right | PgDn |   (  |   )  |   4  |   5  |   6  |  *   |
 * |------+------+------+------+------+------+------+------+------+------+-*----+------|
 * |Shift |      |      |      |   _  |   =  |      |   0  |   1  |   2  |   3  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Meh  |⌘(Gui)|^/Del | Bsp  |██████|    Space    |RAISE |⌥/Ent |   .  | Bspc |  +   |
 * `-----------------------------------------------------------------------------------'
 * Ctrl is shifted for better reachability by pinky
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_EQL,  KC_PLUS, KC_HOME,        KC_UP,   KC_END,  KC_PGUP, XXXXXXX, KC_PERC, KC_7,    KC_8,    KC_9,   KC_SLSH,
    KC_HYPR, XXXXXXX, KC_LEFT,        KC_DOWN, KC_RGHT, KC_PGDN, KC_LPRN, KC_RPRN, KC_4,    KC_5,    KC_6,   KC_ASTR,
    _______, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_0,    KC_1,    KC_2,    KC_3,   KC_MINS,
    _______, KC_LGUI, LCTL_T(KC_DEL), KC_BSPC, _______, _______, _______, _______, _______, KC_DOT, KC_BSPC, KC_PLUS
),

/* Raise - F keys, brackets
 * ,------------------------------------------------------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |  ^   |  &   |  *   |   [  |  ]   |       |
 * |------+------+------+------+------+------+------+------+------+------+------+-------|
 * | Hyper|  F1  |  F2  |  F3  |  F4  |  F5  |      |Player|      |   (  |  )   |       |
 * |------+------+------+------+------+------+------+------+------+------+------+-------|
 * | Shift|  F6  |  F7  |  F8  |  F9  |  F10 | PlPrv|PlyPse|PlNxt |   {  |  }   |       |
 * |------+------+------+------+------+------+------+------+------+------+------+-------|
 * | Meh  |      |^(Ctl)|⌘(Gui)|LOWER |             |██████|⌥(Alt)|PrvSpc|NxtSpc|MsnCtl |
 * `------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, XXXXXXX,
    KC_HYPR, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, PLAYER,  XXXXXXX, KC_LPRN, KC_RPRN, XXXXXXX,
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_MPRV, KC_MPLY, KC_MNXT, KC_LCBR, KC_RCBR, XXXXXXX,
    _______, XXXXXXX, KC_LCTL, KC_LGUI, _______, XXXXXXX, XXXXXXX, _______, KC_RALT, PRV_SPC, NXT_SPC, MSN_CTL
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_shift_override(keycode, record) ||
        !process_russian_override(keycode, record) ||
        !process_common_override(keycode, record))
    return true;

  switch (keycode) {
    
    case QWERTY:
      if (record->event.pressed) {
        set_persistent_layer(_QWERTY);
      }
      return false;

    case COLEMAK:
      if (record->event.pressed) {
        set_persistent_layer(_COLEMAK);
      }
      return false;

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
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
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

void matrix_init_user(void) {
//    set_unicode_input_mode(UC_LNX); // Linux
    set_unicode_input_mode(UC_OSX); // Mac OSX
//    set_unicode_input_mode(UC_WIN); // Windows (with registry key, see wiki)
    //set_unicode_input_mode(UC_WINC); // Windows (with WinCompose, see wiki)
};

// Runs constantly in the background, in a loop.
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
