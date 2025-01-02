#include QMK_KEYBOARD_H

/*
Colors are defined as HSV (hue, saturation, and valus)
- Hue is an angle which controls the color. This is codded
  on 8 bits. 0 is angle 0 degres and 255 is 360 degres.
- saturation lays between 0 (no color) and 255 (full color).
- value controls brightness on8 bits.
*/
#define C_NONE    {0,0,0}
#define C_RED     {0,255,255}
#define C_ORANG   {21,255,255}
#define C_YELLO   {43,255,255}
#define C_CHART   {64,255,255}   // Green chartreuse
#define C_GREEN   {85,255,255}
#define C_SPRIN   {106,255,255}  // Spring green
#define C_CYAN    {128,255,255}
#define C_AZURE   {149,255,255}
#define C_BLUE    {170,255,255}
#define C_VIOLE   {191,255,255}
#define C_MAGEN   {213,255,255}
#define C_ROSE    {234,255,255}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = {
      C_BLUE,  C_BLUE,  C_BLUE,  C_BLUE,  C_BLUE,  C_BLUE,
      C_BLUE,  C_BLUE,  C_BLUE,  C_BLUE,  C_BLUE,  C_BLUE,
      C_BLUE,  C_BLUE,  C_BLUE,  C_BLUE,  C_BLUE,  C_BLUE,
      C_ROSE,  C_BLUE,  C_BLUE,  C_BLUE,  C_BLUE,  C_BLUE,
                                          C_BLUE,  C_BLUE,

      C_BLUE,  C_BLUE,  C_BLUE,  C_BLUE,  C_BLUE,  C_BLUE,
      C_BLUE,  C_BLUE,  C_BLUE,  C_ROSE,  C_BLUE,  C_BLUE,
      C_BLUE,  C_BLUE,  C_BLUE,  C_BLUE,  C_BLUE,  C_BLUE,
      C_BLUE,  C_BLUE,  C_BLUE,  C_BLUE,  C_BLUE,  C_ROSE,
      C_BLUE,  C_BLUE
    },
    [1] = {
      C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN,
      C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN,
      C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN,
      C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN,
                                          C_SPRIN, C_SPRIN,

      C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN, C_AZURE,
      C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN, C_AZURE,
      C_SPRIN, C_ROSE,  C_ROSE,  C_ROSE,  C_ROSE,  C_AZURE,
      C_SPRIN, C_ORANG, C_YELLO, C_YELLO, C_ORANG, C_AZURE,
      C_SPRIN, C_SPRIN
    },
    [2] = {
      C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN,
      C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN,
      C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN,
      C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN,
                                          C_SPRIN, C_SPRIN,

      C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN, C_AZURE,
      C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN, C_SPRIN, C_AZURE,
      C_SPRIN, C_ROSE,  C_ROSE,  C_ROSE,  C_ROSE,  C_AZURE,
      C_SPRIN, C_ORANG, C_YELLO, C_YELLO, C_ORANG, C_AZURE,
      C_SPRIN, C_SPRIN
    },
    [3] = {
      C_NONE, C_NONE, C_NONE, C_NONE, C_NONE, C_NONE,
      C_NONE, C_NONE, C_NONE, C_NONE, C_AZURE, C_NONE,
      C_NONE, C_NONE, C_NONE, C_NONE, C_AZURE, C_NONE,
      C_NONE, C_NONE, C_NONE, C_NONE, C_NONE, C_NONE,
                                      C_NONE, C_NONE,

      C_NONE, C_NONE, C_NONE, C_NONE, C_NONE, C_NONE,
      C_NONE, C_NONE, C_NONE, C_NONE, C_NONE, C_NONE,
      C_NONE, C_NONE, C_NONE, C_NONE, C_NONE, C_NONE,
      C_RED,  C_NONE, C_NONE, C_NONE, C_NONE, C_NONE,
      C_NONE, C_NONE
    },
    [4] = {
      C_VIOLE, C_ROSE,  C_ROSE,  C_ROSE,  C_ROSE,  C_ROSE,
      C_VIOLE, C_VIOLE, C_VIOLE, C_VIOLE, C_VIOLE, C_VIOLE,
      C_VIOLE, C_VIOLE, C_VIOLE, C_VIOLE, C_VIOLE, C_VIOLE,
      C_VIOLE, C_VIOLE, C_VIOLE, C_VIOLE, C_VIOLE, C_VIOLE,
                                          C_VIOLE, C_VIOLE,

      C_ROSE,  C_ROSE,  C_ROSE,  C_ROSE,  C_ROSE,  C_ROSE,
      C_VIOLE, C_VIOLE, C_VIOLE, C_VIOLE, C_VIOLE, C_ROSE,
      C_VIOLE, C_ORANG, C_ORANG, C_ORANG, C_VIOLE, C_VIOLE,
      C_VIOLE, C_CYAN,  C_CYAN,  C_VIOLE, C_VIOLE, C_VIOLE,
      C_VIOLE, C_VIOLE
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
    case 4:
      set_layer_color(4);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}