//#include QMK_KEYBOARD_H
#include "marklindsay.h"

enum layers {
    _QWERTY,
    _COLEMAK,
    _EXPRMNT,
    _NUMPAD,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  EXPRMNT,
  TG_NMPD,
  GUI_ENT,
  LOWER,
  RAISE,
  ADJUST
};

/* Abreviations */
#define TG_NMPD TG(_NUMPAD)
#define GUI_ENT LGUI_T(KC_ENT)


#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_ergodox_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
    KC_ESC,  ________________NUMBER_LEFT________________, KC_RBRC,                   KC_EQL,  ________________NUMBER_RIGHT_______________, KC_EQL,  \
    KC_GRV,  K01,     K02,     K03,     K04,     K05,     KC_LBRC,                   KC_MINS, K06,     K07,     K08,     K09,     K0A,     KC_BSLS, \
    KC_TAB,  K11,     K12,     K13,     K14,     K15,     KC_SLCK,                   KC_BSPC, K16,     K17,     K18,     K19,     K1A,     K1B,     \
    KC_LSFT, K21,     K22,     K23,     K24,     K25,     RAISE,                   TG_NMPD, K26,     K27,     K28,     K29,     K2A,     KC_ENT,  \
    KC_LGUI, KC_LCTL, KC_LALT, KC_ENT,  GUI_ENT, KC_SPC,  LOWER,                     RAISE,   KC_SPC,  GUI_ENT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
  )
#define LAYOUT_ergodox_base_wrapper(...) LAYOUT_ergodox_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_ergodox_base_wrapper(
    _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
    _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
    _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
  ),

  [_COLEMAK] = LAYOUT_ergodox_base_wrapper(
    _________________COLEMAK_L1________________, _________________COLEMAK_R1________________,
    _________________COLEMAK_L2________________, _________________COLEMAK_R2________________,
    _________________COLEMAK_L3________________, _________________COLEMAK_R3________________
  ),

  [_NUMPAD] = LAYOUT_wrapper( \
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, KC_BSPC,\
    _______, _______, KC_7,    KC_8,    KC_9,    KC_PMNS, KC_PSLS,                   _______, ________________TEN_KEY_TOP________________, _______,\
    _______, KC_DOT,  KC_4,    KC_5,    KC_6,    KC_PPLS, KC_PAST,                   _______, ________________TEN_KEY_MID________________, _______,\
    _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_EQL,  KC_TRNS,                   KC_TRNS, ________________TEN_KEY_BOT________________, _______,\
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______ \
  ),

  [_LOWER] = LAYOUT_wrapper( \
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                   _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12, \
    _______, _______, _______, KC_LPRN, KC_LCBR, KC_LBRC, _______,                   _______, KC_RBRC, KC_RCBR, KC_RPRN, _______, _______, _______,\
    _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGUP, KC_END,                    _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,\
    KC_CAPS, KC_VOLD, KC_VOLU, _______, _______, KC_PGDN, _______,                   _______, _______, _______, _______, _______, _______, KC_CAPS,\
    _______, _______, _______, _______, _______, KC_TRNS, _______,                   _______, KC_TRNS, _______, _______, _______, _______, _______ \
  ),

  [_RAISE] = LAYOUT_wrapper( \
    _______, _______, KC_F10,  KC_F11,  KC_F12,  _______, _______,                   _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12, \
    _______, _______, KC_F7,   KC_F8,   KC_F9,   _______, _______,                   _______, _______, _______, _______, _______, _______, _______,\
    _______, _______, KC_F4,   KC_F5,   KC_F6,   _______, _______,                   KC_DEL,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,\
    KC_CAPS, _______, KC_F1,   KC_F2,   KC_F3,   _______, _______,                   _______, _______, _______, _______, _______, _______, _______,\
    _______, _______, _______, _______, _______, KC_TRNS, _______,                   _______, KC_TRNS, _______, _______, _______, _______, _______ \
  ),

  [_ADJUST] = LAYOUT_wrapper( \
    QWERTY,  COLEMAK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   RGB_M_P, RGB_MOD, RGB_RMOD,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
    XXXXXXX, XXXXXXX, XXXXXXX, BL_STEP, BL_TOGG, XXXXXXX, XXXXXXX,                   RGB_M_K, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  \
    RESET,   EEP_RST, XXXXXXX, BL_BRTG, BL_INC,  XXXXXXX, XXXXXXX,                   RGB_M_X, RGB_M_T, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,\
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BL_DEC,  XXXXXXX, XXXXXXX,                   XXXXXXX, RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,\
    CG_SWAP, CG_NORM, XXXXXXX, XXXXXXX, XXXXXXX, LOWER,   XXXXXXX,                   XXXXXXX, RAISE,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
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

// Layer LED Settings/
// See: https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgblight

#define LAYER_VAL 120

// Define led segments for each layer
const rgblight_segment_t PROGMEM capslock_segments[] = RGBLIGHT_LAYER_SEGMENTS(
	{3, 1, 0, 255, LAYER_VAL}
);
const rgblight_segment_t PROGMEM num_segments[] = RGBLIGHT_LAYER_SEGMENTS(
	{11, 1, 64, 255, LAYER_VAL}
);
const rgblight_segment_t PROGMEM lower_segments[] = RGBLIGHT_LAYER_SEGMENTS(
	{0, 1, 0, 255, LAYER_VAL}
);
const rgblight_segment_t PROGMEM raise_segments[] = RGBLIGHT_LAYER_SEGMENTS(
	{23, 1, 0, 255, LAYER_VAL}
);
const rgblight_segment_t PROGMEM adjust_segments[] = RGBLIGHT_LAYER_SEGMENTS(
	{9, 1, 0, 255, LAYER_VAL}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM mod_led_layers[] = RGBLIGHT_LAYERS_LIST(
	capslock_segments,
	num_segments,
	lower_segments,
	raise_segments,
	adjust_segments
);

void keyboard_post_init_user(void) {
	// Enable the LED layers
	rgblight_layers = mod_led_layers;
}

#define BIT_SET(intval, bitnum) ((intval & (1 << bitnum)) > 0)

// Use the RGBLight layers feature to indicate active layers
uint32_t layer_state_set_user(uint32_t state) {
	rgblight_set_layer_state(1, BIT_SET(state, _NUMPAD));
	rgblight_set_layer_state(2, BIT_SET(state, _LOWER));
	rgblight_set_layer_state(3, BIT_SET(state, _RAISE));
	rgblight_set_layer_state(4, BIT_SET(state, _ADJUST));
	// This isn't required but it improves the responsiveness
	rgblight_set();
  	return state;
}

// Called when the host computer indicates an LED should change state.
// This didn't work until I checked "Manipulate LED" in Karabiner Elements preferences
bool led_update_user(led_t led_state) {
	//uprintf("Caps_lock = %s  (%d)\n", led_state.caps_lock ? "ON": "OFF", led_state.raw);
	rgblight_set_layer_state(0, led_state.caps_lock);
	rgblight_set();
	return true;
}

