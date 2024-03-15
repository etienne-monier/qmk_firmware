#include QMK_KEYBOARD_H


#define c_none     {0,0,0}
#define c_red      {0,255,255}
#define c_orange   {21,255,255}
#define c_yellow   {43,255,255}
#define c_green_chartreuse  {64,255,255}
#define c_green    {85,255,255}
#define c_spring_green      {106,255,255}
#define c_cyan     {128,255,255}
#define c_azure    {149,255,255}
#define c_blue     {170,255,255}
#define c_violet   {191,255,255}
#define c_magenta  {213,255,255}
#define c_rose     {234,255,255}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = {
      c_blue,  c_blue,  c_blue,  c_blue,  c_blue,  c_blue,
      c_blue,  c_blue,  c_blue,  c_blue,  c_blue,  c_blue,
      c_blue,  c_blue,  c_blue,  c_blue,  c_blue,  c_blue,
      c_blue,  c_blue,  c_blue,  c_blue,  c_blue,  c_blue,
                                          c_blue,  c_blue,

      c_blue,  c_blue,  c_blue,  c_blue,  c_blue,  c_blue,
      c_blue,  c_blue,  c_blue,  c_blue,  c_blue,  c_blue,
      c_blue,  c_blue,  c_blue,  c_blue,  c_blue,  c_blue,
      c_blue,  c_blue,  c_blue,  c_blue,  c_blue,  c_blue,
      c_blue,  c_blue
    },
    [1] = {
      c_none,  c_none,    c_none,    c_none,    c_none,    c_none,
      c_none,  c_orange,  c_orange,  c_orange,  c_orange,  c_orange,
      c_none,  c_orange,  c_orange,  c_orange,  c_orange,  c_orange,
      c_none,  c_none,    c_none,    c_none,    c_none,    c_orange,
                                                c_none,    c_none,

      c_none,  c_none,  c_none,    c_none,    c_none,    c_none,
      c_none,  c_none,  c_none,    c_none,    c_none,    c_none,
      c_none,  c_none,  c_orange,  c_orange,  c_orange,  c_none,
      c_none,  c_none,  c_none,    c_none,    c_none,    c_none,
      c_none,    c_none,
    },
    [2] = {
      c_violet,  c_violet,  c_violet,  c_violet,  c_violet,  c_violet,
      c_violet,  c_violet,  c_violet,  c_violet,  c_violet,  c_violet,
      c_violet,  c_violet,  c_violet,  c_violet,  c_violet,  c_violet,
      c_violet,  c_violet,  c_violet,  c_violet,  c_violet,  c_violet,
                                                  c_violet,  c_violet,

      c_violet,  c_violet,  c_violet,  c_violet,  c_violet,  c_violet,
      c_violet,  c_violet,  c_violet,  c_violet,  c_violet,  c_violet,
      c_violet,  c_violet,  c_violet,  c_violet,  c_violet,  c_violet,
      c_violet,  c_violet,  c_violet,  c_violet,  c_violet,  c_violet,
      c_violet,  c_violet
    },
    [3] = {
      c_orange,  c_orange,  c_orange,  c_orange,  c_orange,  c_orange,
      c_orange,  c_orange,  c_orange,  c_orange,  c_orange,  c_orange,
      c_orange,  c_orange,  c_orange,  c_orange,  c_orange,  c_orange,
      c_orange,  c_orange,  c_orange,  c_orange,  c_orange,  c_orange,
                                                  c_orange,  c_orange,

      c_orange,  c_orange,  c_orange,  c_orange,  c_orange,  c_orange,
      c_orange,  c_orange,  c_orange,  c_orange,  c_orange,  c_orange,
      c_orange,  c_orange,  c_orange,  c_orange,  c_orange,  c_orange,
      c_orange,  c_orange,  c_orange,  c_orange,  c_orange,  c_orange,
      c_orange,  c_orange
    },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}