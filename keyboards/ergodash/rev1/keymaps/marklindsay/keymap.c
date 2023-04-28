//#include QMK_KEYBOARD_H
#include "marklindsay.h"

enum layers {
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  LOWER,
  RAISE,
  ADJUST,
  GUI_ENT
};

/* Abreviations */
#define TG_DFLT TO(0)
//#define TG_LOWR TG(_LOWER)
//#define TG_RAIS TG(_RAISE)
//#define TG_ADJS TG(_ADJUST)
#define LWR_BSP LT(_LOWER, KC_BSPC)
#define RAS_BSP LT(_RAISE, KC_BSPC)
#define LWR_ENT LT(_LOWER, KC_ENT)
#define RAS_ENT LT(_RAISE, KC_ENT)
#define SFT_ENT SFT_T(KC_ENT)
#define GUI_SPC GUI_T(KC_SPC)
#define CTL_SPC CTL_T(KC_SPC)
//#define ALT_SPC ALT_T(KC_SPC)
//#define ALT_ENT ALT_T(KC_ENT)
//#define SFT_ENT SFT_T(KC_ENT)
#define TAP_LOW TT(_LOWER)
//#define LOWR_F2 LT(LOWER, KC_F2)  //not how this works
//#define RAIS_F2 LT(RAISE, KC_BSPC)  //not how this works
#define MEH__F2 MT(MOD_LGUI | MOD_LALT | MOD_LSFT, KC_F2)

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_ergodox_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
    KC_ESC,  ________________NUMBER_LEFT________________, KC_RBRC,                   KC_EQL,  ________________NUMBER_RIGHT_______________, KC_DEL, \
    KC_GRV,  K01,     K02,     K03,     K04,     K05,     KC_LBRC,                   KC_MINS, K06,     K07,     K08,     K09,     K0A,     KC_BSLS,\
    KC_TAB,  K11,     K12,     K13,     K14,     K15,     KC_SLCK,                   KC_BSPC, K16,     K17,     K18,     K19,     K1A,     K1B,    \
    KC_LSFT, K21,     K22,     K23,     K24,     K25,         LOWER,             RAISE,       K26,     K27,     K28,     K29,     K2A,     KC_ENT, \
    MEH__F2, KC_LGUI, KC_LALT, TAP_LOW,     SFT_ENT, CTL_SPC, KC_BSPC,           KC_BSPC,  KC_SPC, RAS_ENT,     ______________ARROWS______________ \
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

  [_LOWER] = LAYOUT_wrapper( \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                   KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
    KC_7,    KC_8,    KC_9,    KC_DEL,  KC_CAPS, KC_UP,   _______,                   _______, _______, _______, _______, _______, _______, _______,\
    KC_4,    KC_5,    KC_6,    _______, KC_LEFT, KC_DOWN, KC_RGHT,                   _______, _______, _______, _______, _______, _______, _______,\
    KC_1,    KC_2,    KC_3,    KC_TAB,  KC_PMNS, KC_PPLS, KC_TRNS,                   _______, _______, _______, _______, _______, _______, _______,\
    KC_BSPC, KC_0,    KC_DOT,  KC_TRNS, _______, _______, _______,                   _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END  \
  ),

  [_RAISE] = LAYOUT_wrapper( \
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,\
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,\
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,\
    _______, _______, _______, _______, _______, _______, _______,                   KC_TRNS, _______, _______, _______, _______, _______, _______,\
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, KC_TRNS, _______, KC_VOLD, KC_VOLU, _______ \
  ),

  [_ADJUST] = LAYOUT_wrapper( \
    QWERTY,  COLEMAK, _______, _______, _______, _______, _______,                   RGB_M_P, RGB_MOD, RGB_RMOD,_______, _______, _______, _______,\
    _______, _______, _______, _______, _______, _______, _______,                   RGB_M_K, _______, _______, _______, _______, _______, _______,\
    RESET,   EEP_RST, _______, _______, _______, _______, _______,                   RGB_M_X, RGB_M_T, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______,\
    _______, _______, _______, _______, _______, _______, KC_TRNS,                   KC_TRNS, RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______,\
    CG_SWAP, CG_NORM, _______, KC_TRNS, _______, _______, _______,                   _______, _______, KC_TRNS, _______, _______, _______, _______ \
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
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
  }
  return true;
}

// Layer LED Settings/
// See: https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgblight

#define LAYER_VAL 120

// Define led segments for each layer
const rgblight_segment_t PROGMEM capslock_segments[] = RGBLIGHT_LAYER_SEGMENTS(
	{3, 1, 64, 255, LAYER_VAL}
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
	adjust_segments,
	raise_segments,
	lower_segments
);

void keyboard_post_init_user(void) {
	// Enable the LED layers
	rgblight_layers = mod_led_layers;
}

#define BIT_SET(intval, bitnum) ((intval & (1 << bitnum)) > 0)

// Use the RGBLight layers feature to indicate active layers
uint32_t layer_state_set_user(uint32_t state) {
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