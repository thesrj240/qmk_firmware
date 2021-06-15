void keyboard_post_init_user(void) {
  // Call the post init code.
  rgblight_enable_noeeprom(); // enables Rgb, without saving settings
  rgblight_sethsv_noeeprom(HSV_MAGENTA); // sets the color to teal/cyan without saving
  rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE); // sets mode to Fast breathing without saving
}


layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 4:   // reset
        rgblight_sethsv_noeeprom(HSV_RED);
        rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3);
        break;
    case 3:   // mouse
        rgblight_sethsv_noeeprom(HSV_BLUE);
        rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE);
        break;
    case 2:   // nav
        rgblight_sethsv_noeeprom(HSV_ORANGE);
        rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE);
        break;
    case 1:   // symbols
        rgblight_sethsv_noeeprom(HSV_PURPLE);
        rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE);
        break;
    default: //  for any other layers, or the default layer
        rgblight_sethsv_noeeprom(HSV_MAGENTA);
        rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE);
        break;
    }
  return state;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_TOG:
      if (record->event.pressed) {
        rgblight_toggle_noeeprom();
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