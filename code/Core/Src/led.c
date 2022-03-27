#include "led.h"
#include "matrix.h"

#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <time.h>

typedef uint32_t LED_DMA_Buffer_t;

struct LED LED_Leds[LED_COUNT];

LED_DMA_Buffer_t LED_DMA_Buffer[LED_DMA_BUFFER_SIZE];

size_t LED_BrightnessLevel = 2;

void LED_ToBuffer(struct LED *led, LED_DMA_Buffer_t *buffer) {
    uint8_t r = led->colors[0] * LED_BRIGHTNESS_LEVELS[LED_BrightnessLevel];
    uint8_t g = led->colors[1] * LED_BRIGHTNESS_LEVELS[LED_BrightnessLevel];
    uint8_t b = led->colors[2] * LED_BRIGHTNESS_LEVELS[LED_BrightnessLevel];

  for(size_t i = 0; i < 8; ++i) {
      buffer[(0 * 8) + i] = (g & (128 >> i)) ? LED_ARR_HI : LED_ARR_LO;
      buffer[(1 * 8) + i] = (r & (128 >> i)) ? LED_ARR_HI : LED_ARR_LO;
      buffer[(2 * 8) + i] = (b & (128 >> i)) ? LED_ARR_HI : LED_ARR_LO;
    }
}

void LED_Init(TIM_HandleTypeDef *htim, uint32_t tim_channel) {
  // Zero-fill DMA buffer
  memset(LED_DMA_Buffer, 0, sizeof(LED_DMA_Buffer));

  // Reset LED colors
  for(size_t i = 0; i < LED_COUNT; ++i) {
   memcpy(LED_Leds[i].colors, LED_BACKLIGHT_COLOR, sizeof(LED_BACKLIGHT_COLOR));
  }

  // Run DMA
  HAL_TIM_PWM_Start_DMA(htim, tim_channel, (uint32_t *) LED_DMA_Buffer, LED_DMA_BUFFER_SIZE);
}

void LED_DMA_Step(size_t current_half) {
  // -2 and -1 for reset pulse
  static ssize_t next_led = -2;

  LED_DMA_Buffer_t * const halved_buffer = LED_DMA_Buffer + (current_half == 0 ? LED_DMA_BUFFER_SIZE / 2 : 0);

  // Prepare next half for the first reset pulse
  if(next_led == -2) {
    memset(halved_buffer, 0, sizeof(*halved_buffer) * LED_DMA_BUFFER_SIZE / 2);
  }

  // Prepare next half for the second reset pulse
  else if(next_led == -1) {
    memset(halved_buffer, 0, sizeof(*halved_buffer) * LED_DMA_BUFFER_SIZE / 2);
  }

  // Prepare next half for the next LED
  else {
    LED_ToBuffer(&LED_Leds[next_led], halved_buffer);
  }

  ++next_led;

  if(next_led == LED_COUNT) {
    next_led = -2;
  }
}

void LED_Update() {
  for(size_t i = 0; i < LED_COUNT; ++i) {
    struct LED *led = &LED_Leds[i];

    if(MATRIX_CapslockOn && i == LED_CAPSLOCK) {
      memcpy(led->colors, LED_ACCENT_COLOR, sizeof(LED_ACCENT_COLOR));
      led->animation_mode = STATIC;
      led->animation_active = 0;
      continue;
    } else if(i == LED_CAPSLOCK && led->animation_mode == STATIC) {
      memcpy(led->colors, LED_BACKLIGHT_COLOR, sizeof(LED_BACKLIGHT_COLOR));
      led->animation_mode = BRIGHTENING;
      led->animation_active = 0;
    }

    if(led->animation_active == 0 && rand() <= (RAND_MAX * LED_ACTIVATION_PROBABILITY)) {
      led->animation_mode = BRIGHTENING;
      led->animation_start_tick = HAL_GetTick();
      led->animation_active = 1;
    }

    if(led->animation_active == 1) {
      const uint32_t time_delta = HAL_GetTick() - led->animation_start_tick;

      if(led->animation_mode == BRIGHTENING) {
        if(time_delta > LED_BRIGHTENING_TICKS) {
          led->animation_mode = DARKENING;
          led->animation_start_tick = HAL_GetTick();
        } else {
          for(size_t j = 0; j < 3; ++j) {
            led->colors[j] = LED_BACKLIGHT_COLOR[j] + (LED_BRIGHTEN_COLOR[j] - LED_BACKLIGHT_COLOR[j]) * (1.0 * time_delta / LED_BRIGHTENING_TICKS);
          }
        }
      } else {
        if(time_delta > LED_DARKENING_TICKS) {
          led->animation_active = 0;
        } else {
          for(size_t j = 0; j < 3; ++j) {
            led->colors[j] = LED_BRIGHTEN_COLOR[j] - (LED_BRIGHTEN_COLOR[j] - LED_BACKLIGHT_COLOR[j]) * (1.0 * time_delta / LED_DARKENING_TICKS);
          }
        }
      }
    }
  }
}

void LED_NextBrightnessLevel() {
  if(LED_BrightnessLevel < LED_BRIGHTNESS_LEVELS_COUNT - 1) {
    ++LED_BrightnessLevel;
  }
}

void LED_PrevBrightnessLevel() {
  if(LED_BrightnessLevel > 0) {
    --LED_BrightnessLevel;
  }
}
