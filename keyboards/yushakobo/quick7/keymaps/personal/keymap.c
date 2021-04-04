/* Copyright 2020 yushakobo
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FUNC1
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    BASE = SAFE_RANGE,
    ALPACA,
    GATERONINK,
    HEALIO,
    KAILHBR,
    SAKURIO,
    ZILENT62,
    ZILENT65
};

// MO(_FUNC1)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_MUTE,  GATERONINK, RGB_MOD,
        ZILENT62, ZILENT65,   KAILHBR,
        HEALIO,   SAKURIO,    ALPACA
    ),
    [_FUNC1] = LAYOUT(
        RESET,   KC_TRNS, RGB_TOG,
        KC_HOME, KC_VOLU, KC_END,
        KC_MPRV, KC_VOLD, KC_MNXT
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALPACA:
            if (record->event.pressed) {
                SEND_STRING("Silent Alpaca\n");
            }
            break;
        case GATERONINK:
            if (record->event.pressed) {
                SEND_STRING("Gateron Ink V2 Blue\n");
            }
            break;
        case HEALIO:
            if (record->event.pressed) {
                SEND_STRING("Healio V2\n");
            }
            break;
        case KAILHBR:
            if (record->event.pressed) {
                SEND_STRING("Kailh Box Royal\n");
            }
            break;
        case SAKURIO:
            if (record->event.pressed) {
            } else {
                SEND_STRING("Sakurio\n");
            }
            break;
        case ZILENT62:
            if (record->event.pressed) {
                SEND_STRING("Zilent V2 62g\n");
            }
            break;
        case ZILENT65:
            if (record->event.pressed) {
                SEND_STRING("Zilent V2 65g\n");
            }
            break;
    }
    return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // Left encoder
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) { // Right encoder
        if (clockwise) {
            rgblight_decrease_hue_noeeprom();
        } else {
            rgblight_increase_hue_noeeprom();
        }
    }
}
