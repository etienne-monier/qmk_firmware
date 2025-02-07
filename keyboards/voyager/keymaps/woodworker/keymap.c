// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "version.h"

// This include ERGO-L keymap aliases
#include "src/ergol.c"

// Custom functionalities
#include "src/wood_functions.c"
#include "src/wood_keycodes.c"
#include "src/wood_tap_dance.c"
#include "src/wood_combos.c"
#include "src/wood_rgb.c"

enum layer_names {
    _BASE,
    _NAV,
    _NAV_VM,
    _EDIT,
    _SYS,
};

#define TD_KEY  TD(DANCE_0)
#define VM  TG(_NAV_VM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // The base alpha layer
  [_BASE] = LAYOUT_voyager(
    KC_ESC,  EG_1,    EG_2,    EG_3,    EG_4,    EG_5,       EG_6,    EG_7,    EG_8,    EG_9,    EG_0,    KC_DEL,
    QK_LOCK, EG_Q,    EG_C,    EG_O,    EG_P,    EG_W,       EG_J,    EG_M,    EG_D,    EG_1DK,  EG_Y,    ALGR(EG_L),
    MOD_LSFT,HM_A,    HM_S,    HM_E,    HM_N,    EG_F,       EG_L,    HM_R,    HM_T,    HM_I,    HM_U,    EG_QUOT,
    TG(VM),  EG_Z,    EG_X,    EG_MINS, EG_V,    EG_B,       EG_DOT,  EG_H,    EG_G,    EG_COMM, EG_K,    TG(_SYS),
                   LT(_NAV, KC_BSPC),  LT(_EDIT, KC_TAB),    SFT_T(KC_ENTER), ALGR_T(KC_SPACE)
  ),

  // Navigation keys
  [_NAV] = LAYOUT_voyager(
    _______, MOVE_1,  MOVE_2,  MOVE_3,  MOVE_4,  MOVE_5,     MOVE_6,  MOVE_7,  MOVE_8,  MOVE_9,  MOVE_0,  KC_HOME,
    _______, WORKS_1, WORKS_2, WORKS_3, WORKS_4, WORKS_5,    WORKS_6, WORKS_7, WORKS_8, WORKS_9, WORKS_0, KC_PGUP,
    _______, H_STACK, DEL_W,   TERM,    MENU,    SCR_OFF,    _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGDN,
    _______, V_STACK, REBOOT,  RESIZE,  DISPLAY, FULLSCR,    _______, CLOSE_T, PREV_T,  NEXT_T,  OPEN_T,  KC_END,
                                        _______, _______,    _______, _______
  ),

  // Navigation keys (VM)
  [_NAV_VM] = LAYOUT_voyager(
    _______, XMOVE_1, XMOVE_2, XMOVE_3, XMOVE_4, XMOVE_5,    XMOVE_6, XMOVE_7, XMOVE_8, XMOVE_9, XMOVE_0, XRESIZU,
    _______, XWORK_1, XWORK_2, XWORK_3, XWORK_4, XWORK_5,    XWORK_6, XWORK_7, XWORK_8, XWORK_9, XWORK_0, XRESIZL,
    _______, XH_STAC, XDEL_W,  XTERM,   XMENU,   _______,    _______, XFOCUSL, XFOCUSD, XFOCUSU, XFOCUSR, XRESIZR,
    _______, XV_STAC, XREBOOT, _______, _______, XFULLSC,    _______, XMOVEL,  XMOVED,  XMOVEU,  XMOVER,  XRESIZD,
                                        _______, _______,    _______, _______
  ),

  // Editor keys
  [_EDIT] = LAYOUT_voyager(
    _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, E_CUP,
    _______, _______, _______, _______, KC_F1,   E_PREVC,    _______, _______, _______, _______, _______, E_MLUP,
    _______, _______, E_DEL_L, _______, E_BLOCK, E_NEXTC,    _______, _______, _______, _______, _______, E_MLDOW,
    _______, _______, _______, _______, _______, _______,    E_XEDIT, _______, E_TAB_L, E_TAB_R, _______, E_CDOWN,
                                        _______, _______,    _______, _______
  ),

  // System keys
  [_SYS] = LAYOUT_voyager(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, _______, _______, _______, _______, _______,    _______, KC_PSCR, _______, _______, _______, KC_F12,
    _______, _______, _______, _______, _______, _______,    _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______,
    QK_BOOT, QK_RBT,  _______, _______, _______, _______,    _______, KC_BRID, KC_BRIU, _______, _______, _______,
                                        _______, _______,    _______, _______
  ),
};
