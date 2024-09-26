bool led_enabled_by_layer;
uint8_t previous_animation;

void keyboard_post_init_user(void) {
  // Call the post init code.
  rgblight_enable_noeeprom(); // enables Rgb, without saving settings
  previous_animation = RGBLIGHT_MODE_SNAKE;
  led_enabled_by_layer = false;
  rgblight_sethsv_noeeprom(HSV_MAGENTA);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE);
}


layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
      case 4:   // reset
          if(!rgblight_is_enabled()){
            rgblight_toggle_noeeprom();
            led_enabled_by_layer = true;
          }
          rgblight_sethsv_noeeprom(HSV_RED);
          previous_animation = rgblight_get_mode();
          rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3);
          break;
      case 3:   // mouse
          if(!rgblight_is_enabled()){
            rgblight_toggle_noeeprom();
            previous_animation = rgblight_get_mode();
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            led_enabled_by_layer = true;
          }
          rgblight_sethsv_noeeprom(HSV_BLUE);
          break;
      case 2:   // nav
          if(!rgblight_is_enabled()){
            rgblight_toggle_noeeprom();
            previous_animation = rgblight_get_mode();
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            led_enabled_by_layer = true;
          }
          rgblight_sethsv_noeeprom(HSV_ORANGE);
          break;
      case 1:   // symbols
          if(!rgblight_is_enabled()){
            rgblight_toggle_noeeprom();
            previous_animation = rgblight_get_mode();
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            led_enabled_by_layer = true;
          }
          rgblight_sethsv_noeeprom(HSV_PURPLE);
          break;
      default: //  for any other layers, or the default layer
          if(rgblight_is_enabled() && led_enabled_by_layer){
            rgblight_mode_noeeprom(previous_animation);
            rgblight_sethsv_noeeprom(HSV_MAGENTA);
            rgblight_toggle_noeeprom();
            led_enabled_by_layer = false;
          }
          else{
            rgblight_mode_noeeprom(previous_animation);
            rgblight_sethsv_noeeprom(HSV_MAGENTA);
          }
          break;
  }
  return state;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_TOG:
      if (record->event.pressed) {
        if(led_enabled_by_layer){
          rgblight_disable_noeeprom();
          led_enabled_by_layer = false;
        }
        else{
          rgblight_toggle_noeeprom();
      }
      }
      return false; // Skip all further processing of this key

    case RGB_MODE_FORWARD:
      if (record->event.pressed) {
        rgblight_step_noeeprom();
      }
      return false; // Skip all further processing of this key

    case RGB_MODE_REVERSE:
      if (record->event.pressed) {
        rgblight_step_reverse_noeeprom();
      }
      return false; // Skip all further processing of this key

    case RGB_HUI:
      if (record->event.pressed) {
        rgblight_increase_hue_noeeprom();
      }
      return false; // Skip all further processing of this key

    case RGB_HUD:
      if (record->event.pressed) {
        rgblight_decrease_hue_noeeprom();
      }
      return false; // Skip all further processing of this key

    case RGB_SAI:
      if (record->event.pressed) {
        rgblight_increase_sat_noeeprom();
      }
      return false; // Skip all further processing of this key

    case RGB_SAD:
      if (record->event.pressed) {
        rgblight_decrease_sat_noeeprom();
      }
      return false; // Skip all further processing of this key

    case RGB_VAI:
      if (record->event.pressed) {
        rgblight_increase_val_noeeprom();
      }
      return false; // Skip all further processing of this key

    case RGB_VAD:
      if (record->event.pressed) {
        rgblight_decrease_val_noeeprom();
      }
      return false; // Skip all further processing of this key

    default:
      return true; // Process all other keycodes normally
  }
}