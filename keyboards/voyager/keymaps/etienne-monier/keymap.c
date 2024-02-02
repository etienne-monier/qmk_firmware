#include QMK_KEYBOARD_H
#include "version.h"

// This include AZERTY keymap aliases
// As I'll use the keyboard with azerty layouts only,
// This simplifies the design a lot.
#include "keymap_french.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
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

enum custom_keycodes {
  CIRC_A,
  CIRC_E,
  CIRC_I,
  CIRC_O,
  CIRC_U,
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_255_255,
  HSV_74_255_255,
  HSV_169_255_255,
};

enum tap_dance_codes {
  DANCE_0,
};




#define CC_1DK       FR_O   // ErgoL: main dead key on [O]


/**
LAYOUTS
*/

// Each layer gets a name for readability.
enum layer_names {
    _BL,
    _1DK,
    _SYMB,
    _NAV,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // Base layer: alpha layer
  [_BL] = LAYOUT_voyager(
    TD(DANCE_0),            KC_1,    KC_2,    KC_3,       KC_4,    KC_5,                        KC_6,      KC_7,    KC_8,    KC_9,    KC_0,    KC_MINUS,
    CAPS_WORD,              FR_Q,    FR_C,    FR_O,       FR_P,    FR_W,                        FR_J,      FR_M,    FR_D,    OSL(1),  FR_F,    KC_BSLASH,
    MT(MOD_LSFT, KC_BSPACE),FR_A,    FR_S,    FR_E,       FR_N,    FR_COMM,                     FR_L,      FR_R,    FR_T,    FR_I,    FR_U,    MT(MOD_RSFT, KC_QUOTE),
    KC_LGUI,                FR_Z,    FR_X,    FR_MINS,    FR_V,    FR_B,                        FR_DOT,    FR_H,    FR_G,    FR_Y,    FR_K,    KC_RCTRL,
                                           LT(1,KC_ENTER),  CTL_T(KC_TAB),                      SFT_T(KC_BSPACE), LT(2,KC_SPACE)
  ),

  // 1dk layer: ErgoL accents
  [_1DK] = LAYOUT_voyager(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_GRAVE,       _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        KC_F12,
    _______,        FR_AGRV,        FR_EACU,        FR_EGRV,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        KC_BSPACE,
    _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        KC_ENTER,
                                                    _______, _______,                                 _______, KC_0
  ),

  // Code layer: ErgoL AltGr symbols
  [_SYMB] = LAYOUT_voyager(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_GRAVE,       KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_7,           KC_8,           KC_9,           KC_MINUS,       KC_SLASH,       KC_F12,
    _______, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,                                        KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_ASTR,        KC_BSPACE,
    _______, _______, KC_LBRACKET,    KC_RBRACKET,    KC_LCBR,        KC_RCBR,                                        KC_1,           KC_2,           KC_3,           KC_DOT,         KC_EQUAL,       KC_ENTER,
                                                    _______, _______,                                 _______, KC_0
  ),

  // Navigation layer: arrow keys and mouse emulation (constant mode)
  [_NAV] = LAYOUT_voyager(
    RGB_TOG,        TOGGLE_LAYER_COLOR,RGB_MOD,        RGB_SLD,        RGB_VAD,        RGB_VAI,                                        _______, _______, _______, _______, _______, _______,
    _______, _______, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  _______,                                 KC_PGUP,        KC_HOME,        KC_UP,          KC_END,         _______, _______,
    _______, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,_______,                                 KC_PGDOWN,      KC_LEFT,        KC_DOWN,        KC_RIGHT,       _______, _______,
    _______, _______, _______, HSV_0_255_255,  HSV_74_255_255, HSV_169_255_255,                                _______, LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),   _______, _______, _______,
                                                    _______, _______,                                 _______, _______
  ),
};


//
// CUSTOM KEYCODE DEFINITION
//

bool proceed_circ_tap(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        register_code16(FR_CIRC);
        tap_code16(keycode);
        unregister_code16(FR_CIRC);
        return false;
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case CIRC_A ... CIRC_U:
      return proceed_circ_tap(keycode, record);
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
    case HSV_74_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(74,255,255);
      }
      return false;
    case HSV_169_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(169,255,255);
      }
      return false;
  }
  return true;
}


/*
KEY OVERRIDES
*/

const key_override_t question_key_override = ko_make_basic(MOD_MASK_SHIFT, FR_MINS, FR_QUES);
const key_override_t column_key_override = ko_make_basic(MOD_MASK_SHIFT, FR_DOT, FR_COLN);
const key_override_t semi_column_key_override = ko_make_basic(MOD_MASK_SHIFT, FR_COMM, FR_SCLN);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &question_key_override,
    &column_key_override,
    &semi_column_key_override,
    NULL // Null terminate the array of overrides!
};


/*
COMBOS
*/

const uint16_t PROGMEM combo0[] = { MT(MOD_RSFT, KC_QUOTE), MT(MOD_LSFT, KC_BSPACE), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_CAPSLOCK),
};




typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[1];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_EQUAL);
        tap_code16(KC_EQUAL);
        tap_code16(KC_EQUAL);
    }
    if(state->count > 3) {
        tap_code16(KC_EQUAL);
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_EQUAL); break;
        case SINGLE_HOLD: register_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: register_code16(KC_EQUAL); register_code16(KC_EQUAL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_EQUAL); register_code16(KC_EQUAL);
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_EQUAL); break;
        case SINGLE_HOLD: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: unregister_code16(KC_EQUAL); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_EQUAL); break;
    }
    dance_state[0].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
};
