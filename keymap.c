/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdint.h>
#include <stdbool.h>
#include "keycode.h"
#include "action.h"
#include "util.h"
#include "serial.h"
#include "keymap.h"

#define KEYMAP( \
                    K56, K48, K40, K32, K24, K16, K08, K00, \
     K62, K63, K55, K47, K46, K39, K38, K31, K30, K23, K14, K15, K06, K07,   K64, K71, K70, \
     K57, K58, K49, K54, K42, K41, K33, K26, K25, K17, K22, K09, K02, K01,        K65, \
     K59, K51, K50, K43, K44, K34, K35, K27, K19, K18, K11, K10, K03, K04,   K67,      K66, \
     K60, K53, K52, K45, K37, K36, K29, K28, K21, K20, K13, K12, K05,             K68, \
                                   K61, K69 \
) { \
    { KC_##K00, KC_##K01, KC_##K02, KC_##K03, KC_##K04, KC_##K05, KC_##K06, KC_##K07 }, \
    { KC_##K08, KC_##K09, KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, KC_##K15 }, \
    { KC_##K16, KC_##K17, KC_##K18, KC_##K19, KC_##K20, KC_##K21, KC_##K22, KC_##K23 }, \
    { KC_##K24, KC_##K25, KC_##K26, KC_##K27, KC_##K28, KC_##K29, KC_##K30, KC_##K31 }, \
    { KC_##K32, KC_##K33, KC_##K34, KC_##K35, KC_##K36, KC_##K37, KC_##K38, KC_##K39 }, \
    { KC_##K40, KC_##K41, KC_##K42, KC_##K43, KC_##K44, KC_##K45, KC_##K46, KC_##K47 }, \
    { KC_##K48, KC_##K49, KC_##K50, KC_##K51, KC_##K52, KC_##K53, KC_##K54, KC_##K55 }, \
    { KC_##K56, KC_##K57, KC_##K58, KC_##K59, KC_##K60, KC_##K61, KC_##K62, KC_##K63 }, \
    { KC_##K64, KC_##K65, KC_##K66, KC_##K67, KC_##K68, KC_##K69, KC_##K70, KC_##K71 }, \
}

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP(
                      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,

        1,   2,   3,   4,   5,   6,   7,   8,   9,   0,MINS, EQL, GRV,BSPC,       HOME, INS, DEL,
      ESC,   Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,BSLS,LBRC, ENT,              UP,
     LCTL,   A,   S,   D,   F,   G,   H,   J,   K,   L, SCLN,QUOT,RBRC,RGUI,      LEFT,     RGHT,
     LSFT,   Z,   X,   C,   V,   B,   N,   M,COMM, DOT,SLSH,RALT,RSFT,                 DOWN,
                                    LALT, SPC
    ),
};

const action_t PROGMEM fn_actions[] = {
};
