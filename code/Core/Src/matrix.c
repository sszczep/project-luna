#include "matrix.h"

#include "usb_device.h"
#include "config.h"
#include "utils.h"
#include "led.h"

struct MATRIX_Button MATRIX_Buttons[MATRIX_COLS][MATRIX_ROWS];

uint8_t MATRIX_report[8];

extern USBD_HandleTypeDef hUsbDeviceFS;

void MATRIX_SendReport();
void MATRIX_OnPress(const uint16_t keycode);
void MATRIX_OnRelease(const uint16_t keycode);
uint16_t MATRIX_GetKeycode(const size_t row, const size_t col);
uint8_t MATRIX_IsModifier(const uint16_t keycode);
uint8_t *MATRIX_ReportFindEmpty();
uint8_t *MATRIX_ReportFindSet(const uint16_t keycode);
uint16_t MATRIX_MapModifier(const uint16_t keycode);

size_t MATRIX_layerStack[MATRIX_MAX_LAYERS] = { 0 };
size_t MATRIX_layerCount = 1;
uint8_t MATRIX_CapslockOn = 0;

void MATRIX_Init() {
  memset(MATRIX_report, 0, sizeof(MATRIX_report));

  for(size_t col = 0; col < MATRIX_COLS; ++col) {
    for(size_t row = 0; row < MATRIX_ROWS; ++row) {
      struct MATRIX_Button *button = &MATRIX_Buttons[col][row];

      button->last_debounce_tick = HAL_GetTick();
      button->last_button_state = button->button_state = GPIO_PIN_RESET;
    }
  }
}

void MATRIX_Scan() {
  for(size_t col = 0; col < MATRIX_COLS; ++col) {
    HAL_GPIO_WritePin(MATRIX_COLS_PORTS[col], MATRIX_COLS_PINS[col], GPIO_PIN_SET);

    for(size_t row = 0; row < MATRIX_ROWS; ++row) {
      struct MATRIX_Button * const button = &MATRIX_Buttons[col][row];

      uint8_t button_state = HAL_GPIO_ReadPin(MATRIX_ROWS_PORTS[row], MATRIX_ROWS_PINS[row]);

      if (button->last_button_state != button_state) {
        button->last_debounce_tick = HAL_GetTick();
      }

      if((HAL_GetTick() - button->last_debounce_tick) >= MATRIX_DEBOUNCE_TICKS) {
        if(button->button_state != button_state) {
          button->button_state = button_state;

          if(button_state == GPIO_PIN_SET) {
            MATRIX_OnPress(MATRIX_GetKeycode(row, col));
          } else {
            MATRIX_OnRelease(MATRIX_GetKeycode(row, col));
          }
        }
      }

      button->last_button_state = button_state;
    }

    HAL_GPIO_WritePin(MATRIX_COLS_PORTS[col], MATRIX_COLS_PINS[col], GPIO_PIN_RESET);

    HAL_Delay(MATRIX_SCAN_DELAY);
  }

  MATRIX_SendReport();
}

void MATRIX_SendReport() {
  USBD_HID_SendReport(&hUsbDeviceFS, MATRIX_report, sizeof(MATRIX_report));
}

void MATRIX_OnPress(const uint16_t keycode) {
  if(MATRIX_IsModifier(keycode)) {
    MATRIX_report[0] |= MATRIX_MapModifier(keycode);
  } else if(keycode <= KEY_LAYER(0) && keycode >= KEY_LAYER(MATRIX_MAX_LAYERS - 1)) {
    MATRIX_layerStack[MATRIX_layerCount] = KEY_LAYER(0) - keycode;
    ++MATRIX_layerCount;
  } else if(keycode == KEY_LED_INC) {
    LED_NextBrightnessLevel();
  } else if(keycode == KEY_LED_DEC) {
    LED_PrevBrightnessLevel();
  } else if(keycode == KEY_BOOTLOADER) {
    BOOTLOADER_Jump();
  } else {
    uint8_t * const slot = MATRIX_ReportFindEmpty();

    if(slot != NULL) {
      *slot = keycode;

      if(keycode == KEY_CAPSLOCK) MATRIX_CapslockOn = MATRIX_CapslockOn == 1 ? 0 : 1;
    }
  }
}

void MATRIX_OnRelease(const uint16_t keycode) {
  if(MATRIX_IsModifier(keycode)) {
    MATRIX_report[0] &= ~MATRIX_MapModifier(keycode);
  } else if(keycode <= KEY_LAYER(0) && keycode >= KEY_LAYER(MATRIX_MAX_LAYERS - 1)) {
    --MATRIX_layerCount;
  } else {
    uint8_t * const slot = MATRIX_ReportFindSet(keycode);

    // Should never be equal NULL, left just in case something weird happens
    if(slot != NULL) {
      *slot = 0;
    }
  }
}

uint16_t MATRIX_GetKeycode(const size_t row, const size_t col) {
  for(size_t i = MATRIX_layerCount - 1; i >= 0; --i) {
    if(MATRIX_LAYERS[i][row][col] == KEY_TRNS) continue;
    else return MATRIX_LAYERS[i][row][col];
  }

  return KEY_NONE;
}

uint8_t MATRIX_IsModifier(const uint16_t keycode) {
  return (keycode >= KEY_LEFTCTRL) && (keycode <= KEY_RIGHTGUI);
}

uint8_t *MATRIX_ReportFindEmpty() {
  for (size_t i = 2; i < 8; ++i) {
    if(MATRIX_report[i] == 0) return &MATRIX_report[i];
  }

  return NULL;
}

uint8_t *MATRIX_ReportFindSet(const uint16_t keycode) {
  for (size_t i = 2; i < 8; i++) {
    if(MATRIX_report[i] == keycode) return &MATRIX_report[i];
  }

  return NULL;
}

uint16_t MATRIX_MapModifier(const uint16_t keycode) {
  switch(keycode) {
    case KEY_LEFTCTRL: return KEY_MOD_LEFTCTRL;
    case KEY_LEFTSHIFT: return KEY_MOD_LEFTSHIFT;
    case KEY_LEFTALT: return KEY_MOD_LEFTALT;
    case KEY_LEFTGUI: return KEY_MOD_LEFTGUI;
    case KEY_RIGHTCTRL: return KEY_MOD_RIGHTCTRL;
    case KEY_RIGHTSHIFT: return KEY_MOD_RIGHTSHIFT;
    case KEY_RIGHTALT: return KEY_MOD_RIGHTALT;
    case KEY_RIGHTGUI: return KEY_MOD_RIGHTGUI;
    default: return 0;
  }
}
