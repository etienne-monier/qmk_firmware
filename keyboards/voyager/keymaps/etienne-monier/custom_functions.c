#include QMK_KEYBOARD_H
//#include "custom_unicode.c"


bool undead(uint16_t  character, bool pressed) {
  if (pressed) {
    tap_code16(character);
    tap_code(KC_SPC);
  }
  return false;
}

void unmod(uint16_t keycode) {
  uint8_t mod_state = get_mods();
  uint8_t osm_state = get_oneshot_mods();
  uint8_t weak_mods_state = get_weak_mods();
  /* clear_mods(); clear_oneshot_mods(); clear_macro_mods(); clear_weak_mods(); */
  unregister_mods(MOD_MASK_SHIFT);
  del_oneshot_mods(MOD_MASK_SHIFT);
  del_weak_mods(MOD_MASK_SHIFT);
  tap_code16(keycode);
  register_mods(mod_state);
  add_oneshot_mods(osm_state);
  add_weak_mods(weak_mods_state);
}

bool accented_letter(uint16_t accent, uint16_t letter, uint32_t unicode_index, bool pressed) {
  if (pressed) {                        // On press:
    if (get_mods() == MOD_BIT(KC_LSFT)){
      // Send unicode
      tap_code16(FR_B);                 // Press accent, unmoded
      unicode_input_start();
      register_unicodemap(unicode_index);
      unicode_input_finish();
    }
    else {               // Press accent, unmoded
      tap_code16(accent);                 // Press accent, unmoded
      tap_code16(letter);                 // Press letter.
    }
  }                                     // If shift is pressed it'll be released by the user
  return false;                         // Don't continue with the key handling.
}

bool use_unicode_as_upper(uint32_t unicode_index, bool pressed){
  if (pressed){
    if (get_mods() & MOD_MASK_SHIFT){
      // Send unicode
      return false;
    }
    else {
      // No Shift, process letter normally.
      return true;
    }

  }
  return false;
}

// Fix Mod-tap with non-simple keys being tapped.
bool mod_tap_fix(uint16_t tap_key, bool pressed, int count) {
  if (count && pressed) {
    tap_code16(tap_key);
    return false;
  }
  return true;
}