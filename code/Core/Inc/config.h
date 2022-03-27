#pragma once

#include <sys/types.h>

#include "main.h"

// Matrix buttons config

#define MATRIX_ROWS 6
#define MATRIX_COLS 15

#define MATRIX_DEBOUNCE_TICKS 5
#define MATRIX_SCAN_DELAY 1

#define MATRIX_MAX_LAYERS 2

extern const uint16_t MATRIX_ROWS_PINS[MATRIX_ROWS];
extern GPIO_TypeDef * const MATRIX_ROWS_PORTS[MATRIX_ROWS];

extern const uint16_t MATRIX_COLS_PINS[MATRIX_COLS];
extern GPIO_TypeDef * const MATRIX_COLS_PORTS[MATRIX_COLS];

extern const uint16_t MATRIX_LAYERS[MATRIX_MAX_LAYERS][MATRIX_ROWS][MATRIX_COLS];

// Buttons HID keycodes

#define KEY_MOD_LEFTCTRL   0b00000001
#define KEY_MOD_LEFTSHIFT  0b00000010
#define KEY_MOD_LEFTALT    0b00000100
#define KEY_MOD_LEFTGUI    0b00001000
#define KEY_MOD_RIGHTCTRL  0b00010000
#define KEY_MOD_RIGHTSHIFT 0b00100000
#define KEY_MOD_RIGHTALT   0b01000000
#define KEY_MOD_RIGHTGUI   0b10000000

#define KEY_NONE 0x00
#define KEY_A 0x04
#define KEY_B 0x05
#define KEY_C 0x06
#define KEY_D 0x07
#define KEY_E 0x08
#define KEY_F 0x09
#define KEY_G 0x0A
#define KEY_H 0x0B
#define KEY_I 0x0C
#define KEY_J 0x0D
#define KEY_K 0x0E
#define KEY_L 0x0F
#define KEY_M 0x10
#define KEY_N 0x11
#define KEY_O 0x12
#define KEY_P 0x13
#define KEY_Q 0x14
#define KEY_R 0x15
#define KEY_S 0x16
#define KEY_T 0x17
#define KEY_U 0x18
#define KEY_V 0x19
#define KEY_W 0x1A
#define KEY_X 0x1B
#define KEY_Y 0x1C
#define KEY_Z 0x1D
#define KEY_1 0x1E
#define KEY_2 0x1F
#define KEY_3 0x20
#define KEY_4 0x21
#define KEY_5 0x22
#define KEY_6 0x23
#define KEY_7 0x24
#define KEY_8 0x25
#define KEY_9 0x26
#define KEY_0 0x27
#define KEY_ENTER 0x28
#define KEY_ESCAPE 0x29
#define KEY_BACKSPACE 0x2A
#define KEY_TAB 0x2B
#define KEY_SPACE 0x2C
#define KEY_HYPHEN 0x2D
#define KEY_EQUAL 0x2E
#define KEY_LB 0x2F
#define KEY_RB 0x30
#define KEY_BACKSLASH 0x31
#define KEY_COLON 0x33
#define KEY_QUOTE 0x34
#define KEY_TILDE 0x35
#define KEY_COMMA 0x36
#define KEY_PERIOD 0x37
#define KEY_SLASH 0x38
#define KEY_CAPSLOCK 0x39
#define KEY_F1 0x3A
#define KEY_F2 0x3B
#define KEY_F3 0x3C
#define KEY_F4 0x3D
#define KEY_F5 0x3E
#define KEY_F6 0x3F
#define KEY_F7 0x40
#define KEY_F8 0x41
#define KEY_F9 0x42
#define KEY_F10 0x43
#define KEY_F11 0x44
#define KEY_F12 0x45
#define KEY_PRINT 0x46
#define KEY_SCROLL 0x47
#define KEY_PAUSE 0x48
#define KEY_INSERT 0x49
#define KEY_HOME 0x4A
#define KEY_PAGEUP 0x4B
#define KEY_DELETE 0x4C
#define KEY_END 0x4D
#define KEY_PAGEDOWN 0x4E
#define KEY_RIGHTARROW 0x4F
#define KEY_LEFTARROW 0x50
#define KEY_DOWNARROW 0x51
#define KEY_UPARROW 0x52
#define KEY_LEFTCTRL 0xE0
#define KEY_LEFTSHIFT 0xE1
#define KEY_LEFTALT 0xE2
#define KEY_LEFTGUI 0xE3
#define KEY_RIGHTCTRL 0xE4
#define KEY_RIGHTSHIFT 0xE5
#define KEY_RIGHTALT 0xE6
#define KEY_RIGHTGUI 0xE7

// Extra keycodes (> 256)

#define KEY_BOOTLOADER 0xFF
#define KEY_LED_INC 0x100
#define KEY_LED_DEC 0x101

#define KEY_LAYER(n) (0xFFFF - n - 1)
#define KEY_TRNS 0xFFFF

#define LED_COUNT 83

#define LED_MAX_BRIGHTNESS 0.1

// Define ARR value for bit states
#define LED_ARR_LO 1
#define LED_ARR_HI 2

#define LED_DMA_BUFFER_SIZE 48

#define LED_BRIGHTENING_TICKS 300
#define LED_DARKENING_TICKS 1000
#define LED_ACTIVATION_PROBABILITY 0.003
extern const uint8_t LED_BACKLIGHT_COLOR[3];
extern const uint8_t LED_BRIGHTEN_COLOR[3];
extern const uint8_t LED_ACCENT_COLOR[3];
#define LED_CAPSLOCK 25

#define LED_BRIGHTNESS_LEVELS_COUNT 4
extern const double LED_BRIGHTNESS_LEVELS[LED_BRIGHTNESS_LEVELS_COUNT];
