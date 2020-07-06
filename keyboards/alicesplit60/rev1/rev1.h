#pragma once

#include "alicesplit60.h"

#include "quantum.h"

//////////////////////////////////////////////////////////////////////////////
// When only use 7skb.
//////////////////////////////////////////////////////////////////////////////
/*
 * ,------------------------------------   ------------------------------------------------------.
 * | L00 | L01 | L02 | L03 | L04 | L05 |   | R00 | R01 | R02 | R03 | R04 | R05 | R06 | R07 | R17 |
 * |---------------------------------------------------------------------------------------------+
 * |   L10  | L11 | L12 | L13 | L14 | L15 |   | R10 | R11 | R12 | R13 | R14 | R15 | R16 |   R27  |
 * |----------------------------------------  ---------------------------------------------------+
 * |   L20   | L21 | L22 | L23 | L24 | L25 |   | R20 | R21 | R22 | R23 | R24 | R25 |     R26     |
 * |---------------------------------------------------------------------------------------------+
 * |    L30     | L31 | L32 | L33 | L34 | L35 |   | R30 | R31 | R32 | R33 | R34 |   R35    | R36 |
 * |-------------------------------------------   -----------------------------------------------'
 *           | L41 |   L42  | L43  |  L44  |   |  R40  |    R41   |  R43  | R44 |
 *           |------------------------------   ---------------------------------'
 */

#define LAYOUT( \
    L00, L01, L02, L03, L04, L05, L06, L07,      R01, R02, R03, R04, R05, R06, R07, \
    L10, L11, L12, L13, L14, L15, L16,           R11, R12, R13, R14, R15, R16, R17, \
    L20, L21, L22, L23, L24, L25, L26,           R21, R22, R23, R24, R25, R26, R27, \
    L30, L31, L32, L33, L34, L35, L36,           R31, R32, R33, R34, R35, R36, R37, \
    L40, L41, L42, L43, L44, L45, L46,                     R43, R44, R45, R46, R47 \
  ) \
  { \
    { L00,   L01,   L02,   L03,   L04,   L05,   L06,   L07 }, \
    { L10,   L11,   L12,   L13,   L14,   L15,   L16,   KC_NO }, \
    { L20,   L21,   L22,   L23,   L24,   L25,   L26,   KC_NO }, \
    { L30,   L31,   L32,   L33,   L34,   L35,   L36,   KC_NO }, \
    { L40,   L41,   L42,   L43,   L44,   L45,   L46,   KC_NO },  \
    { KC_NO, KC_NO, KC_NO, R47,   R46,   R45,   R44,   R43 },  \
    { KC_NO, R37,   R36,   R35,   R34,   R33,   R32,   R31 }, \
    { KC_NO, R27,   R26,   R25,   R24,   R23,   R22,   R21 }, \
    { KC_NO, R17,   R16,   R15,   R14,   R13,   R12,   R11 }, \
    { KC_NO, R07,   R06,   R05,   R04,   R03,   R02,   R01 } \
  }





