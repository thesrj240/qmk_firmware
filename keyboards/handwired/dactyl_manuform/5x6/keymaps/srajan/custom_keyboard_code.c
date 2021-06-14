void keyboard_post_init_user(void) {
  // Call the post init code.
  rgblight_enable_noeeprom(); // enables Rgb, without saving settings
  rgblight_sethsv_noeeprom(180, 255, 255); // sets the color to teal/cyan without saving
  rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3); // sets mode to Fast breathing without saving
}


layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _RAISE:
        rgblight_setrgb (0x00,  0x00, 0xFF); // use set hsv no eeprom version here
        break;
    case _LOWER:
        rgblight_setrgb (0xFF,  0x00, 0x00);
        break;
    case _PLOVER:
        rgblight_setrgb (0x00,  0xFF, 0x00);
        break;
    case _ADJUST:
        rgblight_setrgb (0x7A,  0x00, 0xFF);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0x00,  0xFF, 0xFF);
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