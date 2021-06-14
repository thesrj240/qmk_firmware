#pragma once

#define USE_SERIAL
#define MASTER_LEFT
#define TAPPING_TOGGLE 2


// RGB backlight
#undef RGB_DI_PIN
#define RGB_DI_PIN D3
#undef RGBLED_NUM
#define RGBLED_NUM 30
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_LIMIT_VAL 95
#define RGBLIGHT_SPLIT {15, 15}
#define RGBLIGHT_DISABLE_KEYCODES