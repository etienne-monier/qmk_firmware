#include QMK_KEYBOARD_H

// ---- Simple keycodes ----

// homerow mod-taps (aliases for readability + re-use in combo definitions)
#define HM_A    GUI_T(EG_A)
#define HM_S    CTL_T(EG_S)
#define HM_E    ALT_T(EG_E)
#define HM_N    SFT_T(EG_N)
#define HM_R    SFT_T(EG_R)
#define HM_T    ALT_T(EG_T)
#define HM_I    CTL_T(EG_I)
#define HM_U    GUI_T(EG_U)

// Tab navigation
#define PREV_T  C(S(KC_TAB))
#define NEXT_T  C(KC_TAB)
#define CLOSE_T C(EG_W)
#define OPEN_T  C(EG_T)

// I3 Workspace navigation
#define WORKS_1 G(KC_1)
#define WORKS_2 G(KC_2)
#define WORKS_3 G(KC_3)
#define WORKS_4 G(KC_4)
#define WORKS_5 G(KC_5)
#define WORKS_6 G(KC_6)
#define WORKS_7 G(KC_7)
#define WORKS_8 G(KC_8)
#define WORKS_9 G(KC_9)
#define WORKS_0 G(KC_0)
#define MOVE_1 C(G(KC_1))
#define MOVE_2 C(G(KC_2))
#define MOVE_3 C(G(KC_3))
#define MOVE_4 C(G(KC_4))
#define MOVE_5 C(G(KC_5))
#define MOVE_6 C(G(KC_6))
#define MOVE_7 C(G(KC_7))
#define MOVE_8 C(G(KC_8))
#define MOVE_9 C(G(KC_9))
#define MOVE_0 C(G(KC_0))

// I3 commands
#define DEL_W   CTL_T(C(G(EG_A)))
#define TERM    ALT_T(G(KC_ENTER))
#define MENU    SFT_T(G(EG_D))
#define SCR_OFF C(G(EG_X))
#define H_STACK GUI_T(G(EG_H))
#define V_STACK G(EG_V)
#define REBOOT  C(G(EG_Z))
#define RESIZE  G(EG_X)
#define DISPLAY C(G(EG_D))

#define XWORK_1 S(G(EG_Q))
#define XWORK_2 S(G(EG_C))
#define XWORK_3 S(G(EG_O))
#define XWORK_4 S(G(EG_P))
#define XWORK_5 S(G(EG_W))
#define XWORK_6 S(G(EG_J))
#define XWORK_7 S(G(EG_M))
#define XWORK_8 S(G(EG_D))
#define XWORK_9 S(G(EG_V))
#define XWORK_0 S(G(EG_F))
#define XMOVE_1 S(G(KC_F1))
#define XMOVE_2 S(G(KC_F2))
#define XMOVE_3 S(G(KC_F3))
#define XMOVE_4 S(G(KC_F4))
#define XMOVE_5 S(G(KC_F5))
#define XMOVE_6 S(G(KC_F6))
#define XMOVE_7 S(G(KC_F7))
#define XMOVE_8 S(G(KC_F8))
#define XMOVE_9 S(G(KC_F9))
#define XMOVE_0 S(G(KC_F10))
#define XDEL_W S(G(EG_S))
#define XTERM S(G(EG_E))
#define XMENU S(G(EG_N))
#define XFULLSC S(G(EG_B))
#define XH_STAC S(G(EG_A))
#define XV_STAC S(G(EG_Z))
#define XREBOOT S(G(EG_X))
#define XRESIZL S(G(KC_LEFT))
#define XRESIZR S(G(KC_RIGHT))
#define XRESIZU S(G(KC_UP))
#define XRESIZD S(G(KC_DOWN))
#define XFOCUSL S(G(EG_R))
#define XFOCUSR S(G(EG_U))
#define XFOCUSU S(G(EG_I))
#define XFOCUSD S(G(EG_T))
#define XMOVEL S(G(EG_H))
#define XMOVER S(G(EG_K))
#define XMOVEU S(G(EG_Y))
#define XMOVED S(G(EG_G))




// Editor keycodes
#define  E_DEL_L C(S(EG_K))


// ---- END Simple keycodes ----

// ---- Less simple keycodes ----

enum custom_keycodes {
  E_BLOCK = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  const bool pressed = record->event.pressed;
  const int count = record->tap.count;
  // const uint8_t mod_state = get_mods();

  switch (keycode) {

    // Mod-tap with complex tapped keys
    case H_STACK: return mod_tap_fix(C(G(EG_H)), pressed, count);
    case DEL_W: return mod_tap_fix(C(G(EG_A)), pressed, count);
    case TERM: return mod_tap_fix(G(KC_ENTER), pressed, count);
    case MENU: return mod_tap_fix(G(EG_D), pressed, count);

    case E_BLOCK: return tap_key_list(C(EG_1), C(EG_2), pressed);

    default:
      return true;

    break;
  }
}

// ---- END Less simple keycodes ----