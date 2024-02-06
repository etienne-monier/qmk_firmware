// ---- Simple keycodes ---- {{{

// homerow mod-taps (aliases for readability + re-use in combo definitions)
#define HM_S    CTL_T(FR_S)
#define HM_E    ALT_T(FR_E)
#define HM_N    SFT_T(FR_N)
#define HM_R    SFT_T(FR_R)
#define HM_T    ALT_T(FR_T)
#define HM_I    CTL_T(FR_I)

// Tab navigation
#define PREV_T  C(S(KC_TAB))
#define NEXT_T  C(KC_TAB)
#define CLOSE_T C(FR_W)
#define OPEN_T  C(FR_T)

// Workspace navigation
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

#define DEL_W   C(G(FR_A))
#define H_STACK CTL_T(G(FR_H))
#define V_STACK ALT_T(G(FR_V))
#define MENU    SFT_T(G(FR_D))
#define DISPLAY C(G(FR_D))
#define SCR_OFF C(G(FR_X))
#define REBOOT  C(G(FR_R))


#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)
#define MOON_LED_LEVEL LED_LEVEL

// ---- END Simple keycodes ----

// ---- Less simple keycodes ----

enum custom_keycodes {
  // Undead characters
  UD_GRV = SAFE_RANGE,
  UD_CIRC,

  // Accented letters
  E_ACUTE,
  E_GRV,
  E_CIRC,
  A_GRV,
  U_GRV,
  A_CIRC,
  I_CIRC,
  O_CIRC,
  U_CIRC,
  C_CED,

  // RGB LED keys
  RGB_SLD,
  COLOR_R,
  COLOR_G,
  COLOR_B,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  const bool pressed = record->event.pressed;

  switch (keycode) {

    // Undead characters
    case UD_GRV:  return undead(FR_GRV,  pressed);
    case UD_CIRC: return undead(FR_CIRC, pressed);

    // Accented letters with dead key
    case E_CIRC: return accented_letter(FR_CIRC,  FR_E, pressed);
    case A_CIRC: return accented_letter(FR_CIRC,  FR_A, pressed);
    case I_CIRC: return accented_letter(FR_CIRC,  FR_I, pressed);
    case O_CIRC: return accented_letter(FR_CIRC,  FR_O, pressed);
    case U_CIRC: return accented_letter(FR_CIRC,  FR_U, pressed);

    // RGB keys
    case RGB_SLD:
      if (pressed) {
        rgblight_mode(1);
      }
      return false;
    case COLOR_R:
      if (pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
    case COLOR_G:
      if (pressed) {
        rgblight_mode(1);
        rgblight_sethsv(74,255,255);
      }
      return false;
    case COLOR_B:
      if (pressed) {
        rgblight_mode(1);
        rgblight_sethsv(169,255,255);
      }
      return false;

    default:
      return true;

    break;
  }
}

// ---- END Less simple keycodes ----