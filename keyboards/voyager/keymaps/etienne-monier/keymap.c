// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "version.h"

// This include AZERTY keymap aliases
// As I'll use the keyboard with azerty layouts only,
// This simplifies the design a lot.
#include "keymap_french.h"

// Custom functionalities
#include "custom_functions.c"
#include "custom_keycodes.c"
#include "custom_key_override.c"
#include "custom_tap_dance.c"
#include "custom_combos.c"
#include "custom_unicode.c"

enum layer_names {
    _BASE,
    _1DK,
    _SYMB,
    _NUM,
    _NAV,
    _MOVE,
    _SYS,
};

#define DK1     OSL(_1DK)
#define TD_KEY  TD(DANCE_0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // The base alpha layer
  [_BASE] = LAYOUT_voyager(
    KC_ESC,  FR_1,    FR_2,    FR_3,    FR_4,    FR_5,       FR_6,    FR_7,    FR_8,    FR_9,    FR_0,    QK_BOOT,
    CW_TOGG, FR_Q,    FR_C,    FR_O,    FR_P,    FR_W,       FR_J,    FR_M,    FR_D,    DK1,     FR_F,    QK_RBT,
    MOD_LSFT,FR_A,    HM_S,    HM_E,    HM_N,    FR_COMM,    FR_L,    HM_R,    HM_T,    HM_I,    FR_U,    KC_RCTL,
    KC_LGUI, FR_Z,    FR_X,    FR_MINS, FR_V,    FR_B,       FR_DOT,  FR_H,    FR_G,    FR_Y,    FR_K,    MT(MOD_RSFT, KC_QUOTE),
                       SFT_T(KC_BSPC), LT(_SYS, KC_TAB),    LT(_NAV,KC_ENTER), LT(_SYMB,KC_SPACE)
  ),

  // The daed key layer to write accents
  [_1DK] = LAYOUT_voyager(
    _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
    _______, A_CIRC,  FR_CCED, UC_OE,   O_CIRC,  _______,    _______, _______, _______, _______, _______, _______,
    _______, FR_AGRV, FR_EACU, FR_EGRV, E_CIRC,  _______,    _______, _______, I_CIRC,  U_CIRC,  FR_UGRV, _______,
    _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                        _______, _______,    _______, _______
  ),

  // The programation symbols
  [_SYMB] = LAYOUT_voyager(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, FR_AT,   FR_LABK, FR_RABK, FR_DLR,  FR_PERC,    UD_CIRC, FR_AMPR, FR_ASTR, FR_QUOT, UD_GRV,  KC_F12,
    _______, FR_LCBR, FR_LPRN, FR_RPRN, FR_RCBR, FR_EQL,     FR_BSLS, FR_PLUS, FR_MINS, FR_SLSH, FR_DQUO, _______,
    _______, FR_TILD, FR_LBRC, FR_RBRC, FR_UNDS, FR_HASH,    FR_PIPE, FR_EXLM, FR_SCLN, FR_COLN, FR_QUES, _______,
                                       MO(_NUM), _______,    _______, _______
  ),

  // Navigation keys
  [_NUM] = LAYOUT_voyager(
    _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
    _______, FR_1,    FR_2,    FR_3,    FR_4,    FR_5,       FR_6,    FR_7,    FR_8,    FR_9,    FR_0,    _______,
    _______, _______, _______, FR_EURO, _______, _______,    _______, FR_DOT,  FR_COMM, _______, _______, _______,
                                        _______, _______,    _______, _______
  ),

  // Navigation keys
  [_NAV] = LAYOUT_voyager(
    _______, _______, _______, _______, _______, _______,    _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
    _______, WORKS_1, WORKS_2, WORKS_3, WORKS_4, WORKS_5,    WORKS_6, WORKS_7, WORKS_8, WORKS_9, WORKS_0, _______,
    _______, DEL_W,   H_STACK, V_STACK, MENU,    SCR_OFF,    _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
    _______, _______, _______, REBOOT,  DISPLAY, _______,    _______, CLOSE_T, PREV_T,  NEXT_T,  OPEN_T,  _______,
                                        _______, OSL(_MOVE), _______, _______
  ),

  // Move-to-workspace keys
  [_MOVE] = LAYOUT_voyager(
    _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
    _______, MOVE_1,  MOVE_2,  MOVE_3,  MOVE_4,  MOVE_5,     MOVE_6,  MOVE_7,  MOVE_8,  MOVE_9,  MOVE_0,  _______,
    _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                        _______, _______,    _______, _______
  ),

  // System keys
  [_SYS] = LAYOUT_voyager(
    RGB_TOG, RGB_MOD, RGB_SLD, RGB_VAD, RGB_VAI, _______,    _______, _______, _______, _______, _______, _______,
    _______, _______, COLOR_R, COLOR_G, COLOR_B, _______,    _______, KC_PSCR, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,    _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______,
    _______, _______, _______, _______, _______, _______,    _______, KC_BRID, KC_BRIU, _______, _______, _______,
                                        _______, _______,    _______, _______
  ),
};

// KC_PRINT_SCREEN