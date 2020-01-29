#include "russian.h"

const uint32_t PROGMEM unicode_map[] = {
  [RU_A_L]  = 0x0430, [RU_A_U]  = 0x0410,
  [RU_B_L]  = 0x0431, [RU_B_U]  = 0x0411,
  [RU_V_L]  = 0x0432, [RU_V_U]  = 0x0412,
  [RU_G_L]  = 0x0433, [RU_G_U]  = 0x0413,
  [RU_D_L]  = 0x0434, [RU_D_U]  = 0x0414,
  [RU_E_L]  = 0x0435, [RU_E_U]  = 0x0415,
  [RU_ZH_L] = 0x0436, [RU_ZH_U] = 0x0416,
  [RU_Z_L]  = 0x0437, [RU_Z_U]  = 0x0417,
  [RU_I_L]  = 0x0438, [RU_I_U]  = 0x0418,
  [RU_IY_L] = 0x0439, [RU_IY_U] = 0x0419,
  [RU_K_L]  = 0x043A, [RU_K_U]  = 0x041A,
  [RU_L_L]  = 0x043B, [RU_L_U]  = 0x041B,
  [RU_M_L]  = 0x043C, [RU_M_U]  = 0x041C,
  [RU_N_L]  = 0x043D, [RU_N_U]  = 0x041D,
  [RU_O_L]  = 0x043E, [RU_O_U]  = 0x041E,
  [RU_P_L]  = 0x043F, [RU_P_U]  = 0x041F,
  [RU_R_L]  = 0x0440, [RU_R_U]  = 0x0420,
  [RU_S_L]  = 0x0441, [RU_S_U]  = 0x0421,
  [RU_T_L]  = 0x0442, [RU_T_U]  = 0x0422,
  [RU_U_L]  = 0x0443, [RU_U_U]  = 0x0423,
  [RU_F_L]  = 0x0444, [RU_F_U]  = 0x0424,
  [RU_H_L]  = 0x0445, [RU_H_U]  = 0x0425,
  [RU_C_L]  = 0x0446, [RU_C_U]  = 0x0426,
  [RU_CH_L] = 0x0447, [RU_CH_U] = 0x0427,
  [RU_SH_L] = 0x0448, [RU_SH_U] = 0x0428,
  [RU_SC_L] = 0x0449, [RU_SC_U] = 0x0429,
  [RU_HS_L] = 0x044A, [RU_HS_U] = 0x042A,
  [RU_Y_L]  = 0x044B, [RU_Y_U]  = 0x042B,
  [RU_SS_L] = 0x044C, [RU_SS_U] = 0x042C,
  [RU_AE_L] = 0x044D, [RU_AE_U] = 0x042D,
  [RU_YU_L] = 0x044E, [RU_YU_U] = 0x042E,
  [RU_YA_L] = 0x044F, [RU_YA_U] = 0x042F,
  [RU_YO_L] = 0x0451, [RU_YO_U] = 0x0401
};

bool process_russian_override(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RU_DOT:
        override_key(record, KC_DOT, KC_COMM);
        return false;
    
    case T_LANG:
        if (record->event.pressed) {
          if (get_active_layer() == _RUSSIAN) {
            set_prev_layer();
          } else {
            set_persistent_layer(_RUSSIAN);
          }
          register_code(KC_LANG);
        } else {
            unregister_code(KC_LANG);
        }
        return false;

  }
  return true;
}
