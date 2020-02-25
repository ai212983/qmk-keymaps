#include "common.h"
#include "russian.h"
#include "shift_override.h"
#include "raw_hid.h"

extern keymap_config_t keymap_config;

enum ergodox_keycodes {
  RGB_SLD = RUSSIAN_SAFE_RANGE,
  EPRM
};

/* ⌘ - GUI, ^ - Ctrl, ⌥ - Alt, ⇧ - Shift
 * Hyper - Ctrl + Shift + Alt + Gui
 * Meh - Ctrl + Shift + Alt
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Workman
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Version|   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   -_   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   D  |   R  |   W  |   B  |      |           |      |   J  |   F  |   U  |   P  |   :  |   \|   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Hyper  |   A  |   S  |   H  |   T  |   G  |------|           |------|   Y  |   N  |   E  |   O  |   I  |   "'   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   M  |   C  |   V  |      |           |      |   K  |   L  |   ,  |   .  |  /?  |   ~`   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | LAlt |       |      |      |      |
 *                                 | ⌘/Esc|LwrBsp|------|       |------|RaiSpc|⌥/Ent |
 *                                 |      |      | ^/Del|       |MehTab|      |      |
 *                                 `--------------------'       `--------------------'
 */
[_WORKMAN] = LAYOUT_ergodox(
  // left hand
  KC_VRSN, KC_1,    KC_2,    KC_3,    KC_4,    KC_5, XXXXXXX,
  XXXXXXX, KC_Q,    KC_D,    KC_R,    KC_W,    KC_B, XXXXXXX,
  KC_HYPR, KC_A,    KC_S,    KC_H,    KC_T,    KC_G,
  KC_LSFT, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                
                                                    XXXXXXX, XXXXXXX,
                                                             KC_LALT,
                                    LGUI_T(KC_ESC), LOWER,   LCTL_T(KC_DEL),
  // right hand
  XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  XXXXXXX, KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_BSLS,
           KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    MY_QUOT,
  XXXXXXX, KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, MY_TILD,
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,
  XXXXXXX,
  MEH_TAB, RAISE, RALT_T(KC_ENT)
),

/* Russian quazioptimal, see https://habr.com/ru/post/210826/
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |    Ц   |   Ч  |   А  |   К  |   Ы  |   М  |      |           |      |  В   |  Л   |  З   |  Ш   |  Й   |   Ф    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    Ъ   |   П  |   И  |   О  |   Е  |   У  |------|           |------|  Р   |  Н   |  Т   |  С   |  Б   |   Х    | - HYPER is unusable in russian anyway
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Э  |   Ю  |   Ь  |   Я  |  .?  |      |           |      |  ,/  |  Г   |  Д   |  Ж   |  Щ   |   "'   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |   Ë  |      |      |      |                                       |      |      |      |      |  \|  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | ⌘/Esc|LwrBsp|------|       |------|RaiSpc|⌥/Ent |
 *                                 |      |      | ^/Del|       |MehTab|      |      |
 *                                 `--------------------'       `--------------------'
 */
[_RUSSIAN] = LAYOUT_ergodox(
  // left hand
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  RU_C,    RU_CH,   RU_A,    RU_K,    RU_Y,    RU_M,    XXXXXXX,
  RU_HS,   RU_P,    RU_I,    RU_O,    RU_E,    RU_U,
  _______, RU_AE,   RU_YU,   RU_SS,   RU_YA,   RU_DOT,  XXXXXXX,
  _______, RU_YO,   XXXXXXX, XXXXXXX, XXXXXXX,
                                               XXXXXXX, XXXXXXX,
                                                        XXXXXXX,
                                      _______, _______, _______,
  // right hand
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, RU_V,    RU_L,    RU_Z,    RU_SH,   RU_IY,   RU_F,
           RU_R,    RU_N,    RU_T,    RU_S,    RU_B,    RU_H,
  XXXXXXX, RU_COMM, RU_G,    RU_D,    RU_ZH,   RU_SC,   MY_QUOT,
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS,
  XXXXXXX, XXXXXXX,
  XXXXXXX,
  _______, _______, _______
),

/* Lower, lockable - navigation and numpad
 * Mod keys on thumb cluster are meant for locked layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |      | Home |  Up  | End  | PgUp |      |           |      |   %  |   7  |   8  |   9  |   *  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Hyper  |      | Left | Down |Right | PgDn |------|           |------|      |   4  |   5  |   6  |   -  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |      |      |      |      |      |      |           |      |   0  |   1  |   2  |   3  |   +  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |⌘(Gui)|^/Del |      |      |                                       |      |      |   .  | Bsp  |  =   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | ⌘/Esc|██████|------|       |------|RaiSpc|⌥+Ent |
 *                                 |      |      | ^/Del|       |MehTab|      |      |
 *                                 `--------------------'       `--------------------'
 */
[_LOWER] = LAYOUT_ergodox(
  // left hand
  XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_HOME,        KC_UP,   KC_END,  KC_PGUP, XXXXXXX,
  _______, XXXXXXX, KC_LEFT,        KC_DOWN, KC_RGHT, KC_PGDN,
  _______, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_LGUI, LCTL_T(KC_DEL), XXXXXXX, XXXXXXX,
                                                      XXXXXXX, XXXXXXX,
                                                               XXXXXXX,
                                             _______, _______, _______,
  // right hand
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  XXXXXXX, KC_PERC, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_SLSH, 
           XXXXXXX, KC_4,    KC_5,    KC_6,    TD_MINS, XXXXXXX, 
  XXXXXXX, KC_0,    KC_1,    KC_2,    KC_3,    KC_PLUS, XXXXXXX, 
                    XXXXXXX, XXXXXXX, TD_DOT,  KC_BSPC, KC_EQL, 
  XXXXXXX, XXXXXXX,
  XXXXXXX,
  _______, _______, RALT(KC_ENT)
),

/* Raise - symbols layer
 * Shifting left mod key to be reachable
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   #  |   $  |   %  |      |           |      |   ^  |   [  |  ]   |PrvSpc|NxtSpc| AppLnc |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Hyper  |      |      |   +  |   -  |  =   |------|           |------|   *  |   (  |  )   |PrvTab|NxtTab|AppSwtch|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |      |      |      |   _  |      |      |           |      |   &  |   {  |  }   |      |      | MsnCtl |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |⌥(Alt)|      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | ⌘/Esc|LwrBsp|------|       |------|██████|⌥/Ent |
 *                                 |      |      | ^/Del|       |MehTab|      |      |
 *                                 `--------------------'       `--------------------'
 */
[_RAISE] = LAYOUT_ergodox(
  // left hand
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, KC_PLUS, KC_MINS, KC_EQL,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                               XXXXXXX, XXXXXXX,
                                                        XXXXXXX,
                                      _______, _______, _______,
  // right hand
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_CIRC, KC_LBRC, KC_RBRC, PRV_SPC, NXT_SPC, APP_LNC, 
           KC_ASTR, KC_LPRN, KC_RPRN, PRV_TAB, NXT_TAB, APP_SWT,
  XXXXXXX, KC_AMPR, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, MSN_CTL,
                    KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,
  XXXXXXX,
  _______, _______, _______
),

/* Adjust (Lower + Raise) - Control and utilities
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |Version |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |RGB_TOG |RGBSLD|RGBMOD|RGB H+|RGB S+|RGB V+|------|           |------|Wrkman|Rssian|      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | ⌘/Esc|██████|------|       |------|██████|⌥/Ent |
 *                                 |      |      | ^/Del|       |MehTab|      |      |
 *                                 `--------------------'       `--------------------'
 */
[_ADJUST] = LAYOUT_ergodox(
  // left hand
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_VRSN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  RGB_TOG, RGB_SLD, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                               XXXXXXX, XXXXXXX,
                                                        XXXXXXX,
                                      XXXXXXX, _______, XXXXXXX,
  // right hand
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
           WORKMAN, RUSSIAN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,
  XXXXXXX,
  XXXXXXX, _______, XXXXXXX
)

};

// ----- Helpers

void indicate_layer(uint8_t layer) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  
  switch (layer) {
    case _RUSSIAN:
      ergodox_right_led_1_set(LED_BRIGHTNESS_LO);
      ergodox_right_led_1_on();
      break;
 
    default: 
      break;
  }
}

// ----- Overrided defaults

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  set_unicode_input_mode(UC_OSX); // Mac OSX
  #ifdef RGBLIGHT_ENABLE
    rgblight_init();
  #endif
};

// Runs constantly in background loop.
void matrix_scan_user(void) {
   indicate_layer(get_active_layer());
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if (!process_shift_override(keycode, record) ||
        !process_russian_override(keycode, record) ||
        !process_common_override(keycode, record))
        return true;

  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      #ifdef RGBLIGHT_ENABLE
        case RGB_SLD:
          rgblight_mode(1);
          return false;
      #endif
    }
  }
  return true;
}

// ----- Work in progress 

void raw_hid_receive(uint8_t *data, uint8_t length) {
    uint8_t *command_id   = &(data[0]);
    uint8_t *command_data = &(data[1]);

    char buffer[50];
    sprintf(buffer, "command id: %d, data: %d", *command_id, *command_data);
    send_string(buffer);
/*
    switch (*command_id) {
        case id_get_keyboard_value: {
            if (command_data[0] == id_uptime) {
                uint32_t value  = timer_read32();
                command_data[1] = (value >> 24) & 0xFF;
                command_data[2] = (value >> 16) & 0xFF;
                command_data[3] = (value >> 8) & 0xFF;
                command_data[4] = value & 0xFF;
            } else {
                *command_id = id_unhandled;
            }
            break;
        }

        case id_bootloader_jump: {
            raw_hid_send(data, length);
            wait_ms(100);
            bootloader_jump();
            break;
        }

        case id_rgblight_color: {
#ifdef RGBLIGHT_ENABLE
            uint16_t hue = ((uint16_t)command_data[0] << 8) | command_data[1];
            uint8_t  sat = command_data[2];
            rhruiz_change_leds_to(hue, sat);
#endif
            break;
        }

        case id_rgblight_reset: {
#ifdef RGBLIGHT_ENABLE
            rhruiz_rgblight_reset();
#endif
            break;
        }

        case id_backlight_toggle: {
#ifdef BACKLIGHT_ENABLE
            backlight_toggle();
#endif
            break;
        }

        case id_rgblight_toggle: {
#ifdef RGBLIGHT_ENABLE
            rgblight_toggle();
#endif
            break;
        }
    }
*/
    raw_hid_send(data, length);
}
