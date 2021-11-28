//#include QMK_KEYBOARD_H
#include "marklindsay.h"


enum layers {
    _WINDOWS,
    _EXPRMNT,
    _NUMPAD,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
  WINDOWS = SAFE_RANGE,
  EXPRMNT,
  NUMPAD,
  LOWER,
  RAISE,
  ADJUST
};

//#define CTL_ENT MT(MOD_RCTL, KC_PENT)
//#define NUMPAD MO(_NUMPAD)
#define TG_NMPD TG(NUMPAD)

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_WINDOWS] = LAYOUT_wrapper( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS,                   KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,  \
    KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,                   KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME,                   KC_DEL,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    TG_NMPD,                   XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_LCTL, KC_LGUI, KC_LALT, KC_ENT,  KC_SPC,  LOWER,   KC_BSPC,                   KC_BSPC, RAISE,   KC_SPC,  KC_ENT,  KC_RALT, KC_RGUI, KC_RCTL  \
  ),

  [_EXPRMNT] = LAYOUT_wrapper( \
    KC_ESC,  ________________NUMBER_LEFT________________, KC_MINS,                   KC_EQL,  ________________NUMBER_RIGHT_______________, KC_EQL,  \
    KC_GRV,  _________________QWERTY_L1_________________, KC_LBRC,                   KC_RBRC, _________________QWERTY_R1_________________, KC_BSLS, \
    KC_TAB,  _________________QWERTY_L2_________________, KC_HOME,                   KC_DEL,  _________________QWERTY_R2_________________, \
    KC_LSFT, _________________QWERTY_L3_________________, TG_NMPD,                   XXXXXXX, _________________QWERTY_R3_________________, KC_RSFT, \
    KC_LCTL, KC_LGUI, KC_LALT, KC_ENT,  KC_SPC,  LOWER,   KC_BSPC,                   KC_BSPC, RAISE,   KC_SPC,  KC_ENT,  KC_RALT, KC_RGUI, KC_RCTL  \
  ),

  [_NUMPAD] = LAYOUT_wrapper( \
    _______, _______, _______, KC_PSLS, KC_PAST, KC_PAST, KC_PSLS,                   KC_PMNS, KC_PSLS, KC_PAST, _______, _______, _______, KC_BSPC, \
    _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, _______, KC_PMNS,                   KC_PPLS, _______, KC_KP_7, KC_KP_8, KC_KP_9, _______, _______, \
    _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_PDOT, KC_PPLS,                   KC_EQL,  KC_PDOT, KC_KP_4, KC_KP_5, KC_KP_6, _______, _______, \
    _______, KC_EQL,  KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_0, _______,                   _______, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                    KC_BSPC, RAISE,   KC_SPC,  KC_ENT,  KC_RALT, KC_RGUI, KC_RCTL \
  ),

  [_LOWER] = LAYOUT_wrapper( \
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                   _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    _______, _______, _______, KC_LPRN, KC_LCBR, KC_LBRC, _______,                   _______, KC_RBRC, KC_RCBR, KC_RPRN, _______, _______, _______, \
    _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGUP, _______,                   _______, _______, _______, _______, _______, _______, _______, \
    KC_CAPS, KC_VOLD, KC_VOLU, _______, _______, KC_PGDN, _______,                   _______, _______, _______, _______, _______, _______, KC_CAPS, \
    _______, _______, _______, _______, _______, LOWER,   _______,                   _______, RAISE,   _______, _______, _______, _______, _______  \
  ),

  [_RAISE] = LAYOUT_wrapper( \
    _______, _______, KC_F10,  KC_F11,  KC_F12,  _______, _______,                   _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    _______, _______, KC_F7,   KC_F8,   KC_F9,   _______, _______,                   _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, KC_F4,   KC_F5,   KC_F6,   _______, _______,                   _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
    KC_CAPS, _______, KC_F1,   KC_F2,   KC_F3,   _______, _______,                   _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, LOWER,   _______,                   _______, RAISE,   _______, _______, _______, _______, _______  \
  ),

  [_ADJUST] = LAYOUT_wrapper( \
    XXXXXXX, WINDOWS, EXPRMNT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, BL_STEP, BL_TOGG, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, RGB_TOG, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, \
    RESET,   XXXXXXX, XXXXXXX, BL_BRTG, BL_INC,  XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BL_DEC,  XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LOWER,   XXXXXXX,                   XXXXXXX, RAISE,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case WINDOWS:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WINDOWS);
      }
      return false;
      break;
    case EXPRMNT:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_EXPRMNT);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
