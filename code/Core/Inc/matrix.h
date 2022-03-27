#pragma once

#include <sys/types.h>

struct MATRIX_Button {
  uint32_t last_debounce_tick;
  uint8_t last_button_state;
  uint8_t button_state;
};

void MATRIX_Init();
void MATRIX_Scan();

extern uint8_t MATRIX_CapslockOn;
