/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#define USB_SUSPEND_WAKEUP_DELAY 200
#define FIRMWARE_VERSION u8"dAA/M7l"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_8BIT
#define COMBO_COUNT 1

#define RGB_MATRIX_STARTUP_SPD 60

#define UNICODE_KEY_MAC 	      KC_LEFT_ALT
#define UNICODE_KEY_LNX 	      LCTL(LSFT(KC_U))
#define UNICODE_KEY_WINC      	KC_RIGHT_ALT
#define UNICODE_SELECTED_MODES 	UNICODE_MODE_LINUX
#define UNICODE_CYCLE_PERSIST 	true
#define UNICODE_TYPE_DELAY 	    10

#define TAPPING_TERM            300  // How long before a key press becomes a hold

