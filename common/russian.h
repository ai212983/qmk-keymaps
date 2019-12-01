#pragma once
#include "keycodes.h"
#include "layers.h"
#include "shift_override.h"

extern const uint32_t PROGMEM unicode_map[];

enum russian_keycodes {
  RU_DOT = COMMON_SAFE_RANGE,
  RU_SLSH,
  RUSSIAN_SAFE_RANGE
};

enum unicode_names {
  RU_A_L,  RU_A_U,
  RU_B_L,  RU_B_U,
  RU_V_L,  RU_V_U,
  RU_G_L,  RU_G_U,
  RU_D_L,  RU_D_U,
  RU_E_L,  RU_E_U,
  RU_ZH_L, RU_ZH_U,
  RU_Z_L,  RU_Z_U,
  RU_I_L,  RU_I_U,
  RU_IY_L, RU_IY_U,
  RU_K_L,  RU_K_U,
  RU_L_L,  RU_L_U,
  RU_M_L,  RU_M_U,
  RU_N_L,  RU_N_U,
  RU_O_L,  RU_O_U,
  RU_P_L,  RU_P_U,
  RU_R_L,  RU_R_U,
  RU_S_L,  RU_S_U,
  RU_T_L,  RU_T_U,
  RU_U_L,  RU_U_U,
  RU_F_L,  RU_F_U,
  RU_H_L,  RU_H_U,
  RU_C_L,  RU_C_U,
  RU_CH_L, RU_CH_U,
  RU_SH_L, RU_SH_U,
  RU_SC_L, RU_SC_U,
  RU_HS_L, RU_HS_U,
  RU_Y_L,  RU_Y_U,
  RU_SS_L, RU_SS_U,
  RU_AE_L, RU_AE_U,
  RU_YU_L, RU_YU_U,
  RU_YA_L, RU_YA_U,
  RU_YO_L, RU_YO_U
};


#define RU_A  XP(RU_A_L,  RU_A_U)
#define RU_B  XP(RU_B_L,  RU_B_U)
#define RU_V  XP(RU_V_L,  RU_V_U)
#define RU_G  XP(RU_B_L,  RU_B_U)
#define RU_D  XP(RU_D_L,  RU_D_U)
#define RU_E  XP(RU_E_L,  RU_E_U)
#define RU_ZH XP(RU_ZH_L, RU_ZH_U)
#define RU_Z  XP(RU_Z_L,  RU_Z_U)
#define RU_I  XP(RU_I_L,  RU_I_U)
#define RU_IY XP(RU_IY_L, RU_IY_U)
#define RU_K  XP(RU_K_L,  RU_K_U)
#define RU_L  XP(RU_L_L,  RU_L_U)
#define RU_M  XP(RU_M_L,  RU_M_U)
#define RU_N  XP(RU_N_L,  RU_N_U)
#define RU_O  XP(RU_O_L,  RU_O_U)
#define RU_P  XP(RU_P_L,  RU_P_U)
#define RU_R  XP(RU_R_L,  RU_R_U)
#define RU_S  XP(RU_S_L,  RU_S_U)
#define RU_T  XP(RU_T_L,  RU_T_U)
#define RU_U  XP(RU_U_L,  RU_U_U)
#define RU_F  XP(RU_F_L,  RU_F_U)
#define RU_H  XP(RU_H_L,  RU_H_U)
#define RU_C  XP(RU_C_L,  RU_C_U)
#define RU_CH XP(RU_CH_L, RU_CH_U)
#define RU_SH XP(RU_SH_L, RU_SH_U)
#define RU_SC XP(RU_SC_L, RU_SC_U)
#define RU_HS XP(RU_HS_L, RU_HS_U)
#define RU_Y  XP(RU_Y_L,  RU_Y_U)
#define RU_SS XP(RU_SS_L, RU_SS_U)
#define RU_AE XP(RU_AE_L, RU_AE_U)
#define RU_YU XP(RU_YU_L, RU_YU_U)
#define RU_YA XP(RU_YA_L, RU_YA_U)
#define RU_YO XP(RU_YO_L, RU_YO_U)

bool process_russian_override(uint16_t keycode, keyrecord_t *record);
