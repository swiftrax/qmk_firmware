#pragma once

#include "slice.h"

#include "quantum.h"

//////////////////////////////////////////////////////////////////////////////
// When only use Slice Rev1.
//////////////////////////////////////////////////////////////////////////////
/*
 * ,------------------------------------------------        --------------------------------------------------.
 * | L00 | L01 | L02 | L03 | L04 | L05 | L06 | L07 |        | R00 | R01 | R02 | R03 | R04 | R05 |  R06R07R08  |
 * |------------------------------------------------      ------------------------------------------------------+
 * | L10 |   L11  | L12 | L13 | L14 | L15 | L16 |         | R10 | R11 | R12 | R13 | R14 | R15 | R16 |    R37    |
 * |----------------------------------------------        ------------------------------------------------------+
 * | L20 |   L21   | L22 | L23 | L24 | L25 | L26 |          | R20 | R21 | R22 | R23 | R24 | R25 |      R26      |
 * |-------------------------------------------------   --------------------------------------------------------+
 * | L30 |    L31     | L32 | L33 | L34 | L35 | L36 |   | R30 | R31 | R32 | R33 | R34 | R34 | R35 |  R36R37R38  |
 * |-------------------------------------------------   --------------------------------------------------------'
 * | L40 |  L41  |  L42  |          L43 | L44L45L46 |    |   R40   | R41 |                |  R42  |  R43  | R44 |
 * |-------------------------------------------------    -------------------------------------------------------'
 */

#define LAYOUT( \
    L00, L01, L02, L03, L04, L05, L06, L07,      R00, R01, R02, R03, R04, R05,      R07,  \
    L10, L11, L12, L13, L14, L15, L16,           R10, R11, R12, R13, R14, R15, R16, R17, \
    L20, L21, L22, L23, L24, L25, L26,           R20, R21, R22, R23, R24, R25, R26, \
    L30, L31, L32, L33, L34, L35, L36,           R30, R31, R32, R33, R34, R35, R36, R38,\
    L40, L41, L42, L43,      L45,                R40, R41, R42, R43, R44 \
  ) \
  { \
    { L00,   L01,   L02,   L03,   L04,   L05,   L06,   L07,     KC_NO }, \
    { L10,   L11,   L12,   L13,   L14,   L15,   L16,   KC_NO,   KC_NO }, \
    { L20,   L21,   L22,   L23,   L24,   L25,   L26,   KC_NO,   KC_NO }, \
    { L30,   L31,   L32,   L33,   L34,   L35,   L36,   KC_NO,   KC_NO }, \
    { L40,   L41,   L42,   L43, KC_NO,   L45, KC_NO,   KC_NO,   KC_NO },  \
    { R00,   R01,   R02,   R03,   R04,   R05, KC_NO,     R07,   KC_NO },  \
    { R10,   R11,   R12,   R13,   R14,   R15,   R16,     R17,   KC_NO }, \
    { R20,   R21,   R22,   R23,   R24,   R25,   R26,   KC_NO,   KC_NO }, \
    { R30,   R31,   R32,   R33,   R34,   R35,   R36,   KC_NO,     R38 }, \
    { R40,   R41,   R42,   R43,   R44, KC_NO, KC_NO,   KC_NO,   KC_NO } \
  }

#define LAYOUT_all( \
    L00, L01, L02, L03, L04, L05, L06, L07,      R00, R01, R02, R03, R04, R05, R06, R07, R08, \
    L10, L11, L12, L13, L14, L15, L16,           R10, R11, R12, R13, R14, R15, R16, R17, \
    L20, L21, L22, L23, L24, L25, L26,           R20, R21, R22, R23, R24, R25, R26, \
    L30, L31, L32, L33, L34, L35, L36,           R30, R31, R32, R33, R34, R35, R36, R37, R38,\
    L40, L41, L42, L43, L44, L45, L46,           R40, R41, R42, R43, R44 \
  ) \
  { \
    { L00,   L01,   L02,   L03,   L04,   L05,   L06,   L07,     KC_NO }, \
    { L10,   L11,   L12,   L13,   L14,   L15,   L16,   KC_NO,   KC_NO }, \
    { L20,   L21,   L22,   L23,   L24,   L25,   L26,   KC_NO,   KC_NO }, \
    { L30,   L31,   L32,   L33,   L34,   L35,   L36,   KC_NO,   KC_NO }, \
    { L40,   L41,   L42,   L43,   L44,   L45,   L46,   KC_NO,   KC_NO },  \
    { R00,   R01,   R02,   R03,   R04,   R05,   R06,     R07,     R08 },  \
    { R10,   R11,   R12,   R13,   R14,   R15,   R16,     R17,   KC_NO }, \
    { R20,   R21,   R22,   R23,   R24,   R25,   R26,   KC_NO,   KC_NO }, \
    { R30,   R31,   R32,   R33,   R34,   R35,   R36,     R37,     R38 }, \
    { R40,   R41,   R42,   R43,   R44, KC_NO, KC_NO,   KC_NO,   KC_NO } \
  }

#define LAYOUT_split_backspace( \
    L00, L01, L02, L03, L04, L05, L06, L07,      R00, R01, R02, R03, R04, R05, R06,       R08, \
    L10, L11, L12, L13, L14, L15, L16,           R10, R11, R12, R13, R14, R15, R16, R17, \
    L20, L21, L22, L23, L24, L25, L26,           R20, R21, R22, R23, R24, R25, R26, \
    L30, L31, L32, L33, L34, L35, L36,           R30, R31, R32, R33, R34, R35, R36,       R38,\
    L40, L41, L42, L43,      L45,                R40, R41, R42, R43, R44 \
  ) \
  { \
    { L00,   L01,   L02,   L03,   L04,   L05,   L06,   L07,     KC_NO }, \
    { L10,   L11,   L12,   L13,   L14,   L15,   L16,   KC_NO,   KC_NO }, \
    { L20,   L21,   L22,   L23,   L24,   L25,   L26,   KC_NO,   KC_NO }, \
    { L30,   L31,   L32,   L33,   L34,   L35,   L36,   KC_NO,   KC_NO }, \
    { L40,   L41,   L42,   L43, KC_NO,   L45, KC_NO,   KC_NO,   KC_NO },  \
    { R00,   R01,   R02,   R03,   R04,   R05,   R06,   KC_NO,     R08 },  \
    { R10,   R11,   R12,   R13,   R14,   R15,   R16,     R17,   KC_NO }, \
    { R20,   R21,   R22,   R23,   R24,   R25,   R26,   KC_NO,   KC_NO }, \
    { R30,   R31,   R32,   R33,   R34,   R35,   R36,   KC_NO,     R38 }, \
    { R40,   R41,   R42,   R43,   R44, KC_NO, KC_NO,   KC_NO,   KC_NO } \
  }


<<<<<<< HEAD
=======
#define LAYOUT_split_left_space( \
    L00, L01, L02, L03, L04, L05, L06, L07,      R00, R01, R02, R03, R04, R05,      R07, \
    L10, L11, L12, L13, L14, L15, L16,           R10, R11, R12, R13, R14, R15, R16, R17, \
    L20, L21, L22, L23, L24, L25, L26,           R20, R21, R22, R23, R24, R25, R26, \
    L30, L31, L32, L33, L34, L35, L36,           R30, R31, R32, R33, R34, R35, R36,     R38,\
    L40, L41, L42, L43, L44,      L46,           R40, R41, R42, R43, R44 \
  ) \
  { \
    { L00,   L01,   L02,   L03,   L04,   L05,   L06,   L07,     KC_NO }, \
    { L10,   L11,   L12,   L13,   L14,   L15,   L16,   KC_NO,   KC_NO }, \
    { L20,   L21,   L22,   L23,   L24,   L25,   L26,   KC_NO,   KC_NO }, \
    { L30,   L31,   L32,   L33,   L34,   L35,   L36,   KC_NO,   KC_NO }, \
    { L40,   L41,   L42,   L43,   L44, KC_NO,   L46,   KC_NO,   KC_NO },  \
    { R00,   R01,   R02,   R03,   R04,   R05, KC_NO,     R07,   KC_NO },  \
    { R10,   R11,   R12,   R13,   R14,   R15,   R16,     R17,   KC_NO }, \
    { R20,   R21,   R22,   R23,   R24,   R25,   R26,   KC_NO,   KC_NO }, \
    { R30,   R31,   R32,   R33,   R34,   R35,   R36,   KC_NO,     R38 }, \
    { R40,   R41,   R42,   R43,   R44, KC_NO, KC_NO,   KC_NO,   KC_NO } \
  }

>>>>>>> 0fcefdc0136cb3f6c49a678d07d3430455a008d1

