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
 * |      |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  |  \|  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Hyper |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "'  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |  /?  |  ~`  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Lang | ^/Del| ⌘/Esc|LWRBsp|   Meh/Tab   |RAISpc|⌥/Ent |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_COLEMAK] = LAYOUT_planck_grid(
    XXXXXXX, KC_Q,   KC_W,           KC_F,           KC_P,  KC_G,    KC_J,    KC_L,  KC_U,           KC_Y,    KC_SCLN, KC_BSLS,
    KC_HYPR, KC_A,   KC_R,           KC_S,           KC_T,  KC_D,    KC_H,    KC_N,  KC_E,           KC_I,    KC_O,    MY_QUOT,
    KC_LSFT, KC_Z,   KC_X,           KC_C,           KC_V,  KC_B,    KC_K,    KC_M,  KC_COMM,        KC_DOT,  KC_SLSH, MY_TILD,
    XXXXXXX, T_LANG, LCTL_T(KC_DEL), LGUI_T(KC_ESC), LOWER, MEH_TAB, MEH_TAB, RAISE, RALT_T(KC_ENT), XXXXXXX, XXXXXXX, XXXXXXX
),

/* Russian
 * ,-----------------------------------------------------------------------------------.
 * |   Ъ  |   Й  |   Ц  |   У  |   К  |   Е  |   Н  |   Г  |   Ш  |   Щ  |   З  |  Х   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Hyper |   Ф  |   Ы  |   В  |   А  |   П  |   Р  |   О  |   Л  |   Д  |   Ж  |  Э   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LShift|   Я  |   Ч  |   С  |   М  |   И  |   Т  |   Ь  |   Б  |   Ю  |  .,  |  "'  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Ë  |      | ^/Del| ⌘/Esc|LWRBsp|   Meh/Tab   |RAISpc|⌥/Ent |      |      |  \/  |
 * `-----------------------------------------------------------------------------------'
 */
[_RUSSIAN] = LAYOUT_planck_grid(
    RU_HS,   RU_IY,   RU_C,    RU_U,    RU_K,    RU_E,    RU_N,    RU_G,    RU_SH,   RU_SC,   RU_Z,    RU_H,
    _______, RU_F,    RU_Y,    RU_V,    RU_A,    RU_P,    RU_R,    RU_O,    RU_L,    RU_D,    RU_ZH,   RU_AE,
    _______, RU_YA,   RU_CH,   RU_S,    RU_M,    RU_I,    RU_T,    RU_SS,   RU_B,    RU_YU,   RU_DOT,  MY_QUOT,
    RU_YO,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RU_SLSH
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
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),


/* Lower - navigation and numpad
 * ,-----------------------------------------------------------------------------------.
 * |      |      | Home |  Up  | End  | PgUp |   %  |   7  |   8  |   9  |   *  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Hyper |      | Left | Down |Right | PgDn |      |   4  |   5  |   6  |   -  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LShift|      |      |      |      |      |   0  |   1  |   2  |   3  |   +  |      |
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

/* Raise - symbols layer
 * ,-----------------------------------------------------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |  ^   |   [  |  ]   |PrvSpc|NxtSpc|AppLnc|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Hyper|      |      |   +  |   -  |   =  |  *   |   (  |  )   |PrvTab|NxtTab|AppSwt|  
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LShift|      |      |      |   _  |      |  &   |   {  |  }   |      |      |MsnCtl|
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
 * |Versn | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Colemk|Qwerty|Plover|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    KC_VRSN, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
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
