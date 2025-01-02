
const uint16_t PROGMEM combo0[] = {
  MT(MOD_RSFT, KC_QUOTE),
  MT(MOD_LSFT, KC_BSPC),
  COMBO_END
};

const uint16_t PROGMEM combo1[] = {
  EG_C,
  EG_O,
  COMBO_END
};

combo_t key_combos[] = {
    COMBO(combo0, KC_CAPS),
    COMBO(combo1, KC_ESC),
};
