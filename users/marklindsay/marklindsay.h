/* Copyright 2021 Mark Lindsay marklindsay@protonmail.com @marklindsay
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

#ifndef USERSPACE
#define USERSPACE

//#include "quantum.h"
#include QMK_KEYBOARD_H
#include "wrappers.h" // keymap blocks are defined in wrappers.h and then marklindsay.h is included in the keymap.c 

void my_custom_function(void);

#endif