SRC +=marklindsay.c

ifdef RGB_ENABLE
  # Include my fancy rgb functions source here
  #SRC += cool_rgb_stuff.c
  
  #undef RGBLED_NUM
  //#define RGBLIGHT_ANIMATIONS
	//#define RGBLIGHT_EFFECT_BREATHING
	//define RGBLIGHT_EFFECT_RAINBOW_MOOD
	//#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
	//#define RGBLIGHT_EFFECT_SNAKE
	#define RGBLIGHT_EFFECT_KNIGHT
	#define RGBLIGHT_EFFECT_CHRISTMAS
	//#define RGBLIGHT_EFFECT_STATIC_GRADIENT
	#define RGBLIGHT_EFFECT_RGB_TEST
	//#define RGBLIGHT_EFFECT_ALTERNATING
	//#define RGBLIGHT_EFFECT_TWINKLE

  #define RGBLED_NUM 24
	#define RGBLED_SPLIT { 12, 12 } // don't know if this is right.

	//#define RGBLED_NUM 30
  #define RGBLIGHT_LIMIT_VAL 120
  #define RGBLIGHT_HUE_STEP 10
  #define RGBLIGHT_SAT_STEP 17
  #define RGBLIGHT_VAL_STEP 17
endif