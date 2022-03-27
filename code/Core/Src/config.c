#include "config.h"

const uint16_t MATRIX_ROWS_PINS[MATRIX_ROWS] = {
  ROW1_Pin,
  ROW2_Pin,
  ROW3_Pin,
  ROW4_Pin,
  ROW5_Pin,
  ROW6_Pin,
};

GPIO_TypeDef * const MATRIX_ROWS_PORTS[MATRIX_ROWS] = {
  ROW1_GPIO_Port,
  ROW2_GPIO_Port,
  ROW3_GPIO_Port,
  ROW4_GPIO_Port,
  ROW5_GPIO_Port,
  ROW6_GPIO_Port,
};

const uint16_t MATRIX_COLS_PINS[MATRIX_COLS] = {
  COL1_Pin,
  COL2_Pin,
  COL3_Pin,
  COL4_Pin,
  COL5_Pin,
  COL6_Pin,
  COL7_Pin,
  COL8_Pin,
  COL9_Pin,
  COL10_Pin,
  COL11_Pin,
  COL12_Pin,
  COL13_Pin,
  COL14_Pin,
  COL15_Pin,
};

GPIO_TypeDef * const MATRIX_COLS_PORTS[MATRIX_COLS] = {
  COL1_GPIO_Port,
  COL2_GPIO_Port,
  COL3_GPIO_Port,
  COL4_GPIO_Port,
  COL5_GPIO_Port,
  COL6_GPIO_Port,
  COL7_GPIO_Port,
  COL8_GPIO_Port,
  COL9_GPIO_Port,
  COL10_GPIO_Port,
  COL11_GPIO_Port,
  COL12_GPIO_Port,
  COL13_GPIO_Port,
  COL14_GPIO_Port,
  COL15_GPIO_Port,
};

const uint16_t MATRIX_LAYERS[MATRIX_MAX_LAYERS][MATRIX_ROWS][MATRIX_COLS] = {
  {
    { KEY_ESCAPE, KEY_NONE, KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10, KEY_F11, KEY_F12, KEY_DELETE },
    { KEY_TILDE, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_0, KEY_HYPHEN, KEY_EQUAL, KEY_BACKSPACE, KEY_HOME },
    { KEY_TAB, KEY_Q, KEY_W, KEY_E, KEY_R, KEY_T, KEY_Y, KEY_U, KEY_I, KEY_O, KEY_P, KEY_LB, KEY_RB, KEY_BACKSLASH, KEY_END },
    { KEY_CAPSLOCK, KEY_A, KEY_S, KEY_D, KEY_F, KEY_G, KEY_H, KEY_J, KEY_K, KEY_L, KEY_COLON, KEY_QUOTE, KEY_NONE, KEY_ENTER, KEY_PAGEUP },
    { KEY_LEFTSHIFT, KEY_Z, KEY_X, KEY_C, KEY_V, KEY_B, KEY_N, KEY_M, KEY_COMMA, KEY_PERIOD, KEY_SLASH, KEY_RIGHTSHIFT, KEY_NONE, KEY_UPARROW, KEY_PAGEDOWN },
    { KEY_LEFTCTRL, KEY_LEFTGUI, KEY_LEFTALT, KEY_NONE, KEY_NONE, KEY_SPACE, KEY_NONE, KEY_NONE, KEY_NONE, KEY_RIGHTALT, KEY_LAYER(1), KEY_LEFTARROW, KEY_NONE, KEY_DOWNARROW, KEY_RIGHTARROW }
  },
  {
    { KEY_BOOTLOADER, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS },
    { KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS },
    { KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS },
    { KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS },
    { KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_LED_INC, KEY_TRNS },
    { KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_TRNS, KEY_LED_DEC, KEY_TRNS }
  }
};

const uint8_t LED_BACKLIGHT_COLOR[3] = { 10, 10, 10 };
const uint8_t LED_BRIGHTEN_COLOR[3] = { 100, 100, 100 };
const uint8_t LED_ACCENT_COLOR[3] = { 100, 0, 0 };

const double LED_BRIGHTNESS_LEVELS[LED_BRIGHTNESS_LEVELS_COUNT] = { 0, 0.2, 0.4, 0.6 };