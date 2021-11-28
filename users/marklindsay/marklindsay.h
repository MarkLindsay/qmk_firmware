#ifndef USERSPACE
#define USERSPACE

//#include "quantum.h"
#include QMK_KEYBOARD_H
#include "wrappers.h" // keymap blocks are defined in wrappers.h and then marklindsay.h is included in the keymap.c 

void my_custom_function(void);

#endif