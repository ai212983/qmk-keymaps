#include "common.h"
#include "russian.h"
#include "shift_override.h"

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

/* Colemak
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |      |           |MsnCtl|   6  |   7  |   8  |   9  |   0  |   -_   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   F  |   P  |   G  |PrvSpc|           |NxtSpc|   J  |   L  |   U  |   Y  |   :  |   \|   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Hyper  |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |   O  |   "'   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |  /?  |   ~`   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Meh  | Lang |      |      |      |                                       |      |      |   ⌥  |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | ^/Del| ⌘/Bsp|------|       |------|Space |Enter |
 *                                 |      |      | LOWER|       |RAISE |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_COLEMAK] = LAYOUT_ergodox(
  // left hand
  XXXXXXX, KC_1,   KC_2,    KC_3,    KC_4,    KC_5, XXXXXXX,
  KC_TAB,  KC_Q,   KC_W,    KC_F,    KC_P,    KC_G, PRV_SPC,
  KC_HYPR, KC_A,   KC_R,    KC_S,    KC_T,    KC_D,
  KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX,
  KC_MEH,  T_LANG, XXXXXXX, XXXXXXX, XXXXXXX,
                                                   XXXXXXX, XXXXXXX,
                                                            XXXXXXX,
                           LCTL_T(KC_DEL), LGUI_T(KC_BSPC), LOWER,
  // right hand
  MSN_CTL, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  NXT_SPC, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
           KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    MY_QUOT,
  XXXXXXX, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MY_TILD,
                    XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,
  XXXXXXX,
  RAISE,   KC_SPACE, KC_ENT
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
 *   | Meh  |⌘(Gui)|^/Del |      |      |                                       |      |   .  |   ,  | Bsp  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | ^/Del| ⌘/Bsp|------|       |------|Space |Enter |
 *                                 |      |      |██████|       | RAISE|      |      |
 *                                 `--------------------'       `--------------------'
 */
[_LOWER] = LAYOUT_ergodox(
  // left hand
  XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_HOME,        KC_UP,   KC_END,  KC_PGUP, XXXXXXX,
  _______, XXXXXXX, KC_LEFT,        KC_DOWN, KC_RGHT, KC_PGDN,
  _______, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, KC_LGUI, LCTL_T(KC_DEL), XXXXXXX, XXXXXXX,
                                                      XXXXXXX, XXXXXXX,
                                                               XXXXXXX,
                                             _______, _______, _______,
  // right hand
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  XXXXXXX, KC_PERC, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_SLSH, 
           XXXXXXX, KC_4,    KC_5,    KC_6,    KC_MINS, XXXXXXX, 
  XXXXXXX, KC_0,    KC_1,    KC_2,    KC_3,    KC_PLUS, XXXXXXX, 
                    XXXXXXX, KC_DOT,  KC_COMM, KC_BSPC, XXXXXXX, 
  XXXXXXX, XXXXXXX,
  XXXXXXX,
  _______, _______, _______
),

/* Raise - symbols layer
 * Shifting left mod key to be reachable
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      | RGB  |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   #  |   $  |   %  |      |           |      |   ^  |   [  |  ]   |PrvSpc|NxtSpc| MsnCtl |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Hyper  |      |      |   +  |   -  |  =   |------|           |------|   *  |   (  |  )   |PrvTab|NxtTab|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |      |      |      |   _  |      |      |           |      |   &  |   {  |  }   |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Meh  |      |      |      |      |                                       |⌥(Alt)|      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | ^/Del| ⌘/Bsp|------|       |------|      |      |
 *                                 |      |      |LOWER |       |██████|      |      |
 *                                 `--------------------'       `--------------------'
 */
[_RAISE] = LAYOUT_ergodox(
  // left hand
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_SLD, XXXXXXX,
  XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, KC_PLUS, KC_MINS, KC_EQL,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                               XXXXXXX, XXXXXXX,
                                                        XXXXXXX,
                                      _______, _______, _______,
  // right hand
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_CIRC, KC_LBRC, KC_RBRC, PRV_SPC, NXT_SPC, MSN_CTL, 
           KC_ASTR, KC_LPRN, KC_RPRN, PRV_TAB, NXT_TAB, XXXXXXX,
  XXXXXXX, KC_AMPR, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX,
                    KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,
  XXXXXXX,
  _______, XXXXXXX, XXXXXXX
),


/* Russian
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |    Ъ   |   Й  |   Ц  |   У  |   К  |   Е  |      |           |      |  Н   |  Г   |  Ш   |  Щ   |  З   |   Х    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Right |   Ф  |   Ы  |   В  |   А  |   П  |------|           |------|  Р   |  О   |  Л   |  Д   |  Ж   |   Э    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Я  |   Ч  |   С  |   М  |   И  |      |           |      |  Т   |  Ь   |  Б   |  Ю   |  .,  |   "'   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |   Ë  | Lang |      |      |      |                                       |      |      |PrvTab|NxtTab|  \/  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | ^/Del| ⌘/Bsp|------|       |------|Space |⌥/Ent |
 *                                 |      |      | LOWER|       |RAISE |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_RUSSIAN] = LAYOUT_ergodox(
  // left hand
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  RU_HS,   RU_IY,   RU_C,    RU_U,    RU_K,    RU_E,    XXXXXXX,
  KC_RGHT, RU_F,    RU_Y,    RU_V,    RU_A,    RU_P,
  KC_LSFT, RU_YA,   RU_CH,   RU_S,    RU_M,    RU_I,    XXXXXXX,
  RU_YO,   T_LANG,  XXXXXXX, XXXXXXX, XXXXXXX,
                                           XXXXXXX, XXXXXXX,
                                                    XXXXXXX,
                     LCTL_T(KC_DEL), LGUI_T(KC_BSPC), LOWER,
  // right hand
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, RU_N,    RU_G,    RU_SH,   RU_SC,   RU_Z,    RU_H,
           RU_R,    RU_O,    RU_L,    RU_D,    RU_ZH,   RU_AE,
  XXXXXXX, RU_T,    RU_SS,   RU_B,    RU_YU,   RU_DOT,  MY_QUOT,
                    XXXXXXX, XXXXXXX, PRV_TAB, NXT_TAB, RU_SLSH,
  XXXXXXX, XXXXXXX,
  XXXXXXX,
  RAISE,   KC_SPACE, RALT_T(KC_ENT)
)

};

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

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    set_unicode_input_mode(UC_OSX); // Mac OSX
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
