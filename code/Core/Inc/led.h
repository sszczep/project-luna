#ifndef __LED_H
#define __LED_H

#include "main.h"
#include "config.h"

enum LED_ANIMATION_Mode {
  BRIGHTENING,
  DARKENING,
  STATIC
};

struct LED {
  uint8_t colors[3];
  uint8_t animation_active;
  enum LED_ANIMATION_Mode animation_mode;
  uint32_t animation_start_tick;
};

void LED_Init(TIM_HandleTypeDef *htim, uint32_t tim_channel);
void LED_DMA_Step(size_t current_half);
void LED_Update();
void LED_NextBrightnessLevel();
void LED_PrevBrightnessLevel();

#endif
