/* Copyright 2019 yynmt
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

enum layer_number {
    _BASE = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  BASE = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  RGBRST,
  PWD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base
   * ,-----------------------------------------.
   * | VSC  |Screen| Vol  |Enter |Close |Zoom  |
   * | git  | Shot | Dwn  | pwd  | Win  |Audio |
   * |------+------+------+------+------+------|
   * | VSC  | Mute | Vol  | Lock |Enter |Zoom  |
   * | frmt |      | Up   |Screen|      |Video |
   * `-----------------------------------------'
   */
	[_BASE] = LAYOUT(
    LCTL(LSFT(KC_G)), LCMD(LSFT(KC_4)), KC__VOLDOWN, PWD, LCMD(KC_W), LCMD(LSFT(KC_A)),
    LSFT(LOPT(KC_F)), KC__MUTE, KC__VOLUP, LCMD(LCTL(KC_Q)), KC_ENTER, LCMD(LSFT(KC_V))
  ),

  /* Lower
   * ,-----------------------------------------.
   * |      |      |      | Page |      |      |
   * |      |      |      |  Up  |      |      |
   * |------+------+------+------+------+------|
   * |      |      | Home | Page | End  |      |
   * |      |      |      | Down |      |      |
   * `-----------------------------------------'
   */
  [_LOWER] = LAYOUT(
    _______, _______, _______, KC_PGUP, _______, _______,
    _______, _______, KC_HOME, KC_PGDN, KC_END, _______
  ),

  /* Raise
   * ,-----------------------------------------.
   * |      |      |      |      |      |      |
   * |      |      |      |      |      |      |
   * |------+------+------+------+------+------|
   * |      |      |      |      |      |      |
   * |      |      |      |      |      |      |
   * `-----------------------------------------'
   */
  [_RAISE] = LAYOUT(
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______
  ),

  /* Adjust
   * ,-----------------------------------------.
   * | RGB  | RGB  | RGB  | RGB  | RGB  |      |
   * |Toggle|Mode+ | Hue+ | Sat+ | Val+ |      |
   * |------+------+------+------+------+------|
   * | RGB  | RGB  | RGB  | RGB  | RGB  |      |
   * |Reset |Mode- | Hue- | Sat- | Val- |      |
   * `-----------------------------------------'
   */
  [_ADJUST] = LAYOUT(
    RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______,
    RGBRST, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

int RGB_current_mode;

void matrix_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
  RGB_current_mode = rgblight_config.mode;
  #endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
      if (record->event.pressed) {
        eeconfig_update_rgblight_default();
        rgblight_enable();
        RGB_current_mode = rgblight_config.mode;
      }
      #endif
      break;
    
    case PWD:
      if (record->event.pressed) {
        // Enter password here
        SEND_STRING("xxxxxx");
      }
      break;
  }
  return true;
}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
