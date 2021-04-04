#include QMK_KEYBOARD_H


#define BASE 0
#define META 1
#define SYMB 2
#define GAME 3

#define MT_SHIFT_ENTER MT(MOD_RSFT, KC_ENT)
#define MT_CTRL_ESC MT(MOD_LCTL, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BASE
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |  T   | TBD  |   | TBD  |   Y  |   U  |   I  |   O  |   P  |  BS  |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | ESCC |   A  |   S  |   D  |   F  |  G   | TBD  |   | TBD  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | LSft |   Z  |   X  |   C  |   V  |  B   | TBD  |   | TBD  |   N  |   M  |   ,  |   .  |   /  | ENTS |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | N/A  | Esc  |  Alt |  GUI | MOD1 |Space | TBD  |   | TBD  |Space | MOD2 | LEFT | DOWN |  UP  | RIGHT|
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [BASE] = LAYOUT( \
    KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,   XXXXXXX, XXXXXXX,  KC_Y,   KC_U,     KC_I,    KC_O,    KC_P,    KC_BSPC, \
    MT_CTRL_ESC, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,   XXXXXXX, XXXXXXX,  KC_H,   KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT,     KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,   XXXXXXX, XXXXXXX,  KC_N,   KC_M,     KC_COMM, KC_DOT,  KC_SLSH, MT_SHIFT_ENTER, \
    XXXXXXX,     XXXXXXX, KC_LALT, KC_LGUI, MO(META), KC_SPC, XXXXXXX, XXXXXXX,  KC_SPC, MO(SYMB), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
  ),

  /* META
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |      |   !  |   @  |   #  |   $  |   5  |      |   |      |   ^  |   &  |   *  |   (  |   )  |      |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * |      |      |      | Alt  | Sft  |      |      |   |      | Left | Down |  Up  |Right |      |      | 
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |      | Home | PgUp | PgDwn| End  |      |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [META] = LAYOUT( \
    _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), XXXXXXX, XXXXXXX, S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), _______, \
    _______, XXXXXXX, XXXXXXX, KC_LALT, KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  XXXXXXX, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  ),

  /* SYMB
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |  `   |   1  |   2  |   3  |   4  |   5  |      |   |      |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |      |      |   -  |   =  |   [  |   ]  |  \   |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |      |      |      | Home | End  |      |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |      |      |      | Next | Vol- | Vol+ | Play |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [SYMB] = LAYOUT( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5   , _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, KC_HOME, KC_END,  _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
  )

};
