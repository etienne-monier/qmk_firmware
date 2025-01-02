#include QMK_KEYBOARD_H


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

// Fix Mod-tap with non-simple keys being tapped.
bool mod_tap_fix(uint16_t tap_key, bool pressed, int count) {
  if (count && pressed) {
    tap_code16(tap_key);
    return false;
  }
  return true;
}


// Send key1 followed by key2.
bool tap_key_list(uint16_t tap_key_1, uint16_t tap_key_2, bool pressed) {
  if (pressed) {
    tap_code16(tap_key_1);
    tap_code16(tap_key_2);
    return false;
  }
  return true;
}

// Send ctrl+key1 followed by ctrl+key2
bool editor_shortkeys(uint16_t tap_key_1, uint16_t tap_key_2, bool pressed) {
  return tap_key_list(C(tap_key_1), C(tap_key_2), pressed);
}