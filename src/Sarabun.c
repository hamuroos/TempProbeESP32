/*******************************************************************************
 * Size: 14 px
 * Bpp: 1
 * Opts: --bpp 1 --size 14 --font Sarabun-Regular.ttf --range 3585-3675,0-127 --format lvgl -o Sarabun.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef SARABUN
#define SARABUN 1
#endif

#if SARABUN

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0000 "\u0000" */
    0x0,

    /* U+000D "\r" */
    0x0,

    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xaa, 0xa8, 0xf0,

    /* U+0022 "\"" */
    0xb6, 0x80,

    /* U+0023 "#" */
    0x22, 0x22, 0x22, 0xff, 0x46, 0x44, 0xff, 0x44,
    0x44, 0x44,

    /* U+0024 "$" */
    0x21, 0xe8, 0x60, 0xc1, 0xc1, 0x81, 0x6, 0x17,
    0x88,

    /* U+0025 "%" */
    0x60, 0x92, 0x22, 0x4c, 0x49, 0x9, 0x40, 0xc9,
    0x82, 0x48, 0xc9, 0x11, 0x24, 0x18,

    /* U+0026 "&" */
    0x38, 0x22, 0x11, 0xd, 0x87, 0x6, 0x8a, 0x25,
    0xe, 0xc7, 0x3e, 0x80,

    /* U+0027 "'" */
    0xe0,

    /* U+0028 "(" */
    0x6a, 0x49, 0x24, 0x89, 0x80,

    /* U+0029 ")" */
    0xc9, 0x92, 0x49, 0x2b, 0x0,

    /* U+002A "*" */
    0x68, 0xcf, 0xcc, 0x68,

    /* U+002B "+" */
    0x10, 0x20, 0x47, 0xf1, 0x2, 0x4, 0x0,

    /* U+002C "," */
    0xf6,

    /* U+002D "-" */
    0xf0,

    /* U+002E "." */
    0xc0,

    /* U+002F "/" */
    0x4, 0x20, 0x84, 0x10, 0x82, 0x10, 0x42, 0x8,
    0x0,

    /* U+0030 "0" */
    0x79, 0x28, 0x61, 0x86, 0x18, 0x61, 0x49, 0xe0,

    /* U+0031 "1" */
    0x33, 0xc9, 0x4, 0x10, 0x41, 0x4, 0x11, 0xf0,

    /* U+0032 "2" */
    0x7a, 0x30, 0x41, 0xc, 0x21, 0x8, 0x43, 0xf0,

    /* U+0033 "3" */
    0x72, 0x20, 0x86, 0x70, 0x20, 0x41, 0x8d, 0xe0,

    /* U+0034 "4" */
    0xc, 0x18, 0x51, 0xa2, 0x48, 0xb1, 0x7f, 0x4,
    0x8,

    /* U+0035 "5" */
    0x7d, 0xc, 0x30, 0xfb, 0x30, 0x41, 0x8d, 0xe0,

    /* U+0036 "6" */
    0x0, 0x62, 0x10, 0xbb, 0x38, 0x61, 0xcd, 0xe0,

    /* U+0037 "7" */
    0xfc, 0x30, 0x84, 0x10, 0xc2, 0x8, 0x20, 0x80,

    /* U+0038 "8" */
    0x7a, 0x18, 0x61, 0x7b, 0x38, 0x61, 0xcd, 0xe0,

    /* U+0039 "9" */
    0x7b, 0x38, 0x61, 0xcd, 0xd0, 0x86, 0x70, 0x0,

    /* U+003A ":" */
    0xc6,

    /* U+003B ";" */
    0xc7, 0x80,

    /* U+003C "<" */
    0x2, 0xc, 0x63, 0xc, 0x6, 0x3, 0x1,

    /* U+003D "=" */
    0xfe, 0x0, 0x7, 0xf0,

    /* U+003E ">" */
    0x81, 0x80, 0xc0, 0x60, 0x63, 0x18, 0x40,

    /* U+003F "?" */
    0x74, 0x42, 0x11, 0x8, 0x84, 0x1, 0x0,

    /* U+0040 "@" */
    0x1f, 0x18, 0x64, 0xce, 0x9, 0x8e, 0x64, 0x99,
    0x2f, 0x7e, 0x60, 0xf, 0x80,

    /* U+0041 "A" */
    0x18, 0x18, 0x1c, 0x34, 0x24, 0x26, 0x62, 0x7e,
    0x43, 0xc1,

    /* U+0042 "B" */
    0xfa, 0x18, 0x61, 0xfa, 0x38, 0x61, 0x8f, 0xe0,

    /* U+0043 "C" */
    0x3c, 0x87, 0x4, 0x8, 0x10, 0x20, 0x60, 0x42,
    0x78,

    /* U+0044 "D" */
    0xf9, 0xa, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x85,
    0xf0,

    /* U+0045 "E" */
    0xfe, 0x8, 0x20, 0xfa, 0x8, 0x20, 0x83, 0xf0,

    /* U+0046 "F" */
    0xfe, 0x8, 0x20, 0x83, 0xe8, 0x20, 0x82, 0x0,

    /* U+0047 "G" */
    0x3c, 0x86, 0x4, 0x8, 0x11, 0xe0, 0xc1, 0x42,
    0x7c,

    /* U+0048 "H" */
    0x83, 0x6, 0xc, 0x18, 0x3f, 0xe0, 0xc1, 0x83,
    0x4,

    /* U+0049 "I" */
    0xff, 0xc0,

    /* U+004A "J" */
    0x8, 0x42, 0x10, 0x84, 0x21, 0xb, 0x80,

    /* U+004B "K" */
    0x85, 0x12, 0x45, 0x8f, 0x1a, 0x26, 0x44, 0x85,
    0xc,

    /* U+004C "L" */
    0x82, 0x8, 0x20, 0x82, 0x8, 0x20, 0x83, 0xf0,

    /* U+004D "M" */
    0x80, 0xe0, 0xf0, 0x7c, 0x7a, 0x2d, 0x16, 0x53,
    0x29, 0x9c, 0xc4, 0x40,

    /* U+004E "N" */
    0x83, 0x87, 0x8d, 0x19, 0x33, 0x62, 0xc7, 0x87,
    0x4,

    /* U+004F "O" */
    0x3c, 0x42, 0xc3, 0x81, 0x81, 0x81, 0x81, 0xc3,
    0x42, 0x3c,

    /* U+0050 "P" */
    0xfa, 0x38, 0x61, 0x8f, 0xe8, 0x20, 0x82, 0x0,

    /* U+0051 "Q" */
    0x3c, 0x42, 0xc3, 0x81, 0x81, 0x81, 0x81, 0xc3,
    0x42, 0x3c, 0xf,

    /* U+0052 "R" */
    0xfa, 0x38, 0x61, 0x8f, 0xe8, 0xa2, 0x86, 0x10,

    /* U+0053 "S" */
    0x7a, 0x18, 0x30, 0x70, 0x60, 0x41, 0x8d, 0xe0,

    /* U+0054 "T" */
    0xfe, 0x20, 0x40, 0x81, 0x2, 0x4, 0x8, 0x10,
    0x20,

    /* U+0055 "U" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x44,
    0xf8,

    /* U+0056 "V" */
    0xc1, 0x43, 0x42, 0x62, 0x26, 0x24, 0x34, 0x1c,
    0x18, 0x18,

    /* U+0057 "W" */
    0xc6, 0x28, 0xc5, 0x19, 0xa5, 0x36, 0x94, 0xd2,
    0x8a, 0x51, 0x8a, 0x30, 0xc6, 0x10,

    /* U+0058 "X" */
    0x43, 0x62, 0x24, 0x1c, 0x18, 0x18, 0x14, 0x26,
    0x62, 0x43,

    /* U+0059 "Y" */
    0xc6, 0x89, 0x11, 0x42, 0x82, 0x4, 0x8, 0x10,
    0x20,

    /* U+005A "Z" */
    0x7e, 0xc, 0x30, 0x41, 0x82, 0xc, 0x30, 0x41,
    0xfc,

    /* U+005B "[" */
    0xf2, 0x49, 0x24, 0x93, 0x80,

    /* U+005C "\\" */
    0x83, 0x4, 0x18, 0x20, 0xc1, 0x6, 0x8, 0x30,
    0x40,

    /* U+005D "]" */
    0xe4, 0x92, 0x49, 0x27, 0x80,

    /* U+005E "^" */
    0x10, 0x60, 0xe2, 0x44, 0x90, 0xa1, 0x0,

    /* U+005F "_" */
    0xf8,

    /* U+0060 "`" */
    0x48,

    /* U+0061 "a" */
    0x7a, 0x10, 0x5f, 0x86, 0x37, 0x40,

    /* U+0062 "b" */
    0x82, 0x8, 0x2e, 0xce, 0x18, 0x61, 0xce, 0xe0,

    /* U+0063 "c" */
    0x7b, 0x18, 0x20, 0x83, 0x17, 0x80,

    /* U+0064 "d" */
    0x4, 0x10, 0x5d, 0xce, 0x18, 0x61, 0xcd, 0xd0,

    /* U+0065 "e" */
    0x7b, 0x38, 0x7f, 0x83, 0x17, 0x80,

    /* U+0066 "f" */
    0x34, 0x4f, 0x44, 0x44, 0x44,

    /* U+0067 "g" */
    0x77, 0x38, 0x61, 0x87, 0x37, 0x41, 0xd, 0xe0,

    /* U+0068 "h" */
    0x82, 0x8, 0x2e, 0xce, 0x18, 0x61, 0x86, 0x10,

    /* U+0069 "i" */
    0x9f, 0xc0,

    /* U+006A "j" */
    0x20, 0x12, 0x49, 0x24, 0xe0,

    /* U+006B "k" */
    0x82, 0x8, 0x22, 0x92, 0x8e, 0x24, 0x9a, 0x20,

    /* U+006C "l" */
    0x92, 0x49, 0x24, 0x9c,

    /* U+006D "m" */
    0xb7, 0x64, 0x62, 0x31, 0x18, 0x8c, 0x46, 0x22,

    /* U+006E "n" */
    0xbb, 0x18, 0x61, 0x86, 0x18, 0x40,

    /* U+006F "o" */
    0x38, 0x8a, 0xc, 0x18, 0x28, 0x8f, 0x0,

    /* U+0070 "p" */
    0xbb, 0x38, 0x61, 0x87, 0x3b, 0xa0, 0x82, 0x0,

    /* U+0071 "q" */
    0x77, 0x38, 0x61, 0x87, 0x37, 0x41, 0x4, 0x10,

    /* U+0072 "r" */
    0xbc, 0x88, 0x88, 0x80,

    /* U+0073 "s" */
    0x74, 0x30, 0x60, 0xc5, 0xc0,

    /* U+0074 "t" */
    0x44, 0xf4, 0x44, 0x44, 0x30,

    /* U+0075 "u" */
    0x86, 0x18, 0x61, 0x86, 0x37, 0x40,

    /* U+0076 "v" */
    0xc4, 0x89, 0x33, 0x42, 0x86, 0x4, 0x0,

    /* U+0077 "w" */
    0xc8, 0xa6, 0x55, 0x6a, 0xa5, 0x31, 0x18, 0x8c,

    /* U+0078 "x" */
    0x4d, 0xa3, 0x4, 0x39, 0x2c, 0x40,

    /* U+0079 "y" */
    0xc5, 0x14, 0x8a, 0x28, 0xc1, 0xc, 0x23, 0x0,

    /* U+007A "z" */
    0xfc, 0x21, 0x8, 0x61, 0xf, 0xc0,

    /* U+007B "{" */
    0x69, 0x25, 0x12, 0x49, 0x80,

    /* U+007C "|" */
    0xff, 0xf0,

    /* U+007D "}" */
    0xc9, 0x24, 0x52, 0x4b, 0x0,

    /* U+007E "~" */
    0xf3, 0x3c,

    /* U+0E01 "ก" */
    0x7a, 0x3c, 0x71, 0x86, 0x18, 0x61,

    /* U+0E02 "ข" */
    0x72, 0xd6, 0xab, 0x91, 0x22, 0x44, 0x8e,

    /* U+0E03 "ฃ" */
    0x7a, 0xd6, 0xab, 0x91, 0x22, 0x44, 0x86,

    /* U+0E04 "ค" */
    0x7d, 0x8e, 0xed, 0x5f, 0xa8, 0x50, 0xa1,

    /* U+0E05 "ฅ" */
    0x65, 0xb6, 0xd, 0xdd, 0xa8, 0x50, 0xa1,

    /* U+0E06 "ฆ" */
    0x59, 0xa9, 0xe9, 0xb1, 0xf1, 0x3d, 0x57, 0x31,

    /* U+0E07 "ง" */
    0x39, 0x4e, 0x1c, 0xb4, 0xe3,

    /* U+0E08 "จ" */
    0x7b, 0x10, 0x59, 0x64, 0xd1, 0x47,

    /* U+0E09 "ฉ" */
    0x79, 0x88, 0x16, 0x2c, 0x49, 0x9d, 0xa6,

    /* U+0E0A "ช" */
    0x1, 0x71, 0x6b, 0xab, 0x71, 0x11, 0x11, 0x11,
    0xe,

    /* U+0E0B "ซ" */
    0x1, 0x7b, 0x6b, 0xa9, 0x71, 0x11, 0x11, 0x11,
    0xe,

    /* U+0E0C "ฌ" */
    0x78, 0xc2, 0x71, 0x30, 0x98, 0x4e, 0x76, 0xdf,
    0xd9,

    /* U+0E0D "ญ" */
    0x3c, 0x51, 0x94, 0x24, 0x89, 0x42, 0x50, 0x97,
    0x25, 0xc6, 0x0, 0x0, 0xd0, 0x54, 0xe,

    /* U+0E0E "ฎ" */
    0x1c, 0x4d, 0x89, 0x12, 0x2c, 0x68, 0xb1, 0x2,
    0x65, 0x7b, 0x90,

    /* U+0E0F "ฏ" */
    0x1c, 0x4d, 0x89, 0x12, 0x2c, 0x68, 0xb1, 0x12,
    0xe6, 0x7b, 0x50,

    /* U+0E10 "ฐ" */
    0x3e, 0xe0, 0x39, 0x97, 0x26, 0x44, 0x8e, 0x0,
    0x2d, 0xdb, 0x50,

    /* U+0E11 "ฑ" */
    0x7b, 0xa5, 0x7b, 0xb7, 0x97, 0x48, 0xc4, 0x62,
    0x21,

    /* U+0E12 "ฒ" */
    0x6c, 0x64, 0x9b, 0xa7, 0x29, 0xba, 0x7d, 0xd6,
    0xbd, 0x19,

    /* U+0E13 "ณ" */
    0x78, 0xa3, 0x2c, 0x4a, 0x12, 0x84, 0xb9, 0x6a,
    0x77, 0x97,

    /* U+0E14 "ด" */
    0x7d, 0x8e, 0xee, 0x5b, 0xbe, 0x58, 0xa1,

    /* U+0E15 "ต" */
    0x20, 0xfe, 0xc, 0xda, 0xab, 0x54, 0xb1, 0x42,

    /* U+0E16 "ถ" */
    0x7a, 0x3c, 0x61, 0x87, 0x9a, 0x79,

    /* U+0E17 "ท" */
    0xe7, 0xa5, 0xe9, 0x29, 0x29, 0x31, 0x31, 0x21,

    /* U+0E18 "ธ" */
    0x7c, 0xc0, 0x72, 0x24, 0x48, 0x91, 0x1c,

    /* U+0E19 "น" */
    0xe1, 0xa1, 0xe1, 0x21, 0x21, 0x27, 0x3d, 0x33,

    /* U+0E1A "บ" */
    0xe1, 0xa1, 0xe1, 0x21, 0x21, 0x21, 0x21, 0x1e,

    /* U+0E1B "ป" */
    0x1, 0x1, 0x1, 0xe1, 0xa1, 0xe1, 0x21, 0x21,
    0x21, 0x21, 0x1e,

    /* U+0E1C "ผ" */
    0xe3, 0x47, 0x8c, 0x19, 0x35, 0x71, 0xc1,

    /* U+0E1D "ฝ" */
    0x2, 0x4, 0xf, 0x1a, 0x3c, 0x60, 0xc9, 0xab,
    0x8e, 0x8,

    /* U+0E1E "พ" */
    0xe4, 0xd7, 0x7a, 0xa5, 0x53, 0x19, 0x8c, 0xc6,
    0x41,

    /* U+0E1F "ฟ" */
    0x0, 0x80, 0x40, 0x3c, 0x9a, 0xef, 0x54, 0xaa,
    0x63, 0x31, 0x98, 0xc8, 0x20,

    /* U+0E20 "ภ" */
    0x1e, 0x23, 0x71, 0x21, 0x21, 0x61, 0xa1, 0x61,

    /* U+0E21 "ม" */
    0x63, 0x45, 0x89, 0x12, 0x2e, 0x6f, 0xb3,

    /* U+0E22 "ย" */
    0xe6, 0x9e, 0x59, 0x86, 0x18, 0x5e,

    /* U+0E23 "ร" */
    0x7b, 0x3, 0x82, 0x8, 0xe2, 0x8e,

    /* U+0E24 "ฤ" */
    0x7a, 0x38, 0x51, 0x86, 0x1e, 0x79, 0x4, 0x10,
    0x41,

    /* U+0E25 "ล" */
    0x3c, 0x8f, 0x9, 0xf4, 0x2e, 0x54, 0xb9,

    /* U+0E26 "ฦ" */
    0x1c, 0x4d, 0x88, 0x92, 0x24, 0x58, 0xb1, 0x2,
    0x4, 0x8, 0x10,

    /* U+0E27 "ว" */
    0x7b, 0x10, 0x41, 0x4, 0x71, 0x47,

    /* U+0E28 "ศ" */
    0x7f, 0x8e, 0x6d, 0x5b, 0xa8, 0x50, 0xa1,

    /* U+0E29 "ษ" */
    0xe1, 0x50, 0xbb, 0x45, 0xb2, 0xf1, 0x8, 0x84,
    0x3c,

    /* U+0E2A "ส" */
    0x3e, 0x8c, 0x69, 0x74, 0x2e, 0x54, 0xb9,

    /* U+0E2B "ห" */
    0xe3, 0xa5, 0xe3, 0x25, 0x29, 0x39, 0x31, 0x21,

    /* U+0E2C "ฬ" */
    0x0, 0xf8, 0xea, 0x2b, 0x8e, 0x24, 0x8a, 0xa2,
    0xa8, 0xc6, 0x30, 0x80,

    /* U+0E2D "อ" */
    0x7d, 0x85, 0xca, 0x97, 0x28, 0x50, 0x9e,

    /* U+0E2E "ฮ" */
    0x7b, 0x19, 0xf7, 0x2a, 0x5c, 0xa1, 0x3c,

    /* U+0E2F "ฯ" */
    0xef, 0xde, 0x41, 0x4, 0x10, 0x41,

    /* U+0E30 "ะ" */
    0xe6, 0x9e, 0x9c, 0x3, 0x9a, 0xde,

    /* U+0E31 "ั" */
    0xc6, 0xb7, 0x80,

    /* U+0E32 "า" */
    0x74, 0x42, 0x10, 0x84, 0x21,

    /* U+0E33 "ำ" */
    0xe0, 0x50, 0x38, 0x0, 0x0, 0x70, 0x44, 0x2,
    0x1, 0x0, 0x80, 0x40, 0x20, 0x10,

    /* U+0E34 "ิ" */
    0x7b, 0x3f, 0xc1,

    /* U+0E35 "ี" */
    0x76, 0x3f, 0x43,

    /* U+0E36 "ึ" */
    0x7f, 0x9f, 0xf0, 0x20,

    /* U+0E37 "ื" */
    0xa, 0x75, 0x1b, 0xd0, 0x60,

    /* U+0E38 "ุ" */
    0x6c, 0x90,

    /* U+0E39 "ู" */
    0x6d, 0x5a, 0x70,

    /* U+0E3A "ฺ" */
    0x80,

    /* U+0E3F "฿" */
    0x23, 0xe8, 0x61, 0x87, 0xe8, 0xe1, 0x86, 0x3f,
    0x88,

    /* U+0E40 "เ" */
    0x92, 0x49, 0xef,

    /* U+0E41 "แ" */
    0x89, 0x12, 0x24, 0x48, 0x9d, 0xea, 0xf7,

    /* U+0E42 "โ" */
    0x7d, 0x81, 0x4, 0x10, 0x41, 0x4, 0x10, 0x41,
    0xc5, 0x1c,

    /* U+0E43 "ใ" */
    0x72, 0xac, 0x84, 0x10, 0x41, 0x4, 0x10, 0x41,
    0xc5, 0x1c,

    /* U+0E44 "ไ" */
    0x92, 0xcd, 0x4, 0x10, 0x41, 0x4, 0x10, 0x41,
    0x86, 0x18,

    /* U+0E45 "ๅ" */
    0x74, 0x62, 0x10, 0x84, 0x21, 0x8, 0x42, 0x10,

    /* U+0E46 "ๆ" */
    0x7a, 0x1e, 0x69, 0xe4, 0x10, 0x41, 0x4, 0x10,
    0x40,

    /* U+0E47 "็" */
    0x4, 0x17, 0xb3, 0x7c,

    /* U+0E48 "่" */
    0xe0,

    /* U+0E49 "้" */
    0xce, 0x5d, 0x0,

    /* U+0E4A "๊" */
    0x53, 0x57, 0x36, 0xc0,

    /* U+0E4B "๋" */
    0x5d, 0x0,

    /* U+0E4C "์" */
    0x16, 0xcc,

    /* U+0E4D "ํ" */
    0xf7, 0x80,

    /* U+0E4E "๎" */
    0x74, 0x8e,

    /* U+0E4F "๏" */
    0x38, 0xfb, 0x1e, 0x3c, 0x6f, 0x8e, 0x0,

    /* U+0E50 "๐" */
    0x3c, 0xc3, 0x81, 0x81, 0xc3, 0x3c,

    /* U+0E51 "๑" */
    0x3c, 0xda, 0xa9, 0x99, 0xc9, 0x72,

    /* U+0E52 "๒" */
    0xc0, 0x20, 0x17, 0xcb, 0x15, 0x4a, 0xc5, 0x86,
    0x7e,

    /* U+0E53 "๓" */
    0x77, 0x89, 0x89, 0xe9, 0xa9, 0x69,

    /* U+0E54 "๔" */
    0x0, 0x80, 0x40, 0x4f, 0xcd, 0x85, 0x62, 0x61,
    0x98, 0x7f, 0x0,

    /* U+0E55 "๕" */
    0x0, 0x8e, 0x45, 0x47, 0xcd, 0x85, 0x42, 0x61,
    0x18, 0x7f, 0x80,

    /* U+0E56 "๖" */
    0x80, 0x40, 0x5e, 0x63, 0x1, 0x71, 0x53, 0x3c,

    /* U+0E57 "๗" */
    0x0, 0x80, 0x40, 0x2d, 0x99, 0x2c, 0x97, 0x8b,
    0x46, 0x66, 0x0,

    /* U+0E58 "๘" */
    0x1, 0x1, 0x1, 0x7e, 0xc0, 0x83, 0x95, 0xbb,
    0x4e,

    /* U+0E59 "๙" */
    0x0, 0x80, 0x40, 0x2f, 0xdc, 0xdc, 0x22, 0xd9,
    0x96, 0x71, 0x0,

    /* U+0E5A "๚" */
    0xed, 0xfb, 0x79, 0x20, 0x90, 0x48, 0x24, 0x12,
    0x9,

    /* U+0E5B "๛" */
    0x70, 0x6, 0x50, 0x2e, 0xfd, 0x57, 0xfb, 0x38,
    0x22, 0x1, 0xe0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 54, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2, .adv_w = 54, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 53, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 6, .adv_w = 79, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 8, .adv_w = 154, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 18, .adv_w = 118, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 27, .adv_w = 202, .box_w = 11, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 41, .adv_w = 150, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 53, .adv_w = 43, .box_w = 1, .box_h = 3, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 54, .adv_w = 71, .box_w = 3, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 59, .adv_w = 71, .box_w = 3, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 64, .adv_w = 100, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 68, .adv_w = 136, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 75, .adv_w = 56, .box_w = 2, .box_h = 4, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 76, .adv_w = 76, .box_w = 4, .box_h = 1, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 77, .adv_w = 56, .box_w = 1, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 78, .adv_w = 93, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 87, .adv_w = 123, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 95, .adv_w = 123, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 103, .adv_w = 123, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 111, .adv_w = 123, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 119, .adv_w = 123, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 128, .adv_w = 123, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 136, .adv_w = 123, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 144, .adv_w = 123, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 152, .adv_w = 123, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 160, .adv_w = 123, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 168, .adv_w = 56, .box_w = 1, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 169, .adv_w = 56, .box_w = 1, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 171, .adv_w = 136, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 178, .adv_w = 136, .box_w = 7, .box_h = 4, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 182, .adv_w = 136, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 189, .adv_w = 102, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 196, .adv_w = 178, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 209, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 219, .adv_w = 132, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 227, .adv_w = 131, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 236, .adv_w = 140, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 245, .adv_w = 124, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 253, .adv_w = 123, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 261, .adv_w = 142, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 270, .adv_w = 152, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 279, .adv_w = 65, .box_w = 1, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 281, .adv_w = 99, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 288, .adv_w = 136, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 297, .adv_w = 123, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 305, .adv_w = 179, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 317, .adv_w = 153, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 326, .adv_w = 148, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 336, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 344, .adv_w = 148, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 355, .adv_w = 130, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 363, .adv_w = 118, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 371, .adv_w = 125, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 380, .adv_w = 147, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 389, .adv_w = 135, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 399, .adv_w = 186, .box_w = 11, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 413, .adv_w = 136, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 423, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 432, .adv_w = 127, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 441, .adv_w = 69, .box_w = 3, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 446, .adv_w = 86, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 455, .adv_w = 69, .box_w = 3, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 460, .adv_w = 131, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 467, .adv_w = 72, .box_w = 5, .box_h = 1, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 468, .adv_w = 90, .box_w = 3, .box_h = 2, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 469, .adv_w = 115, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 475, .adv_w = 121, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 483, .adv_w = 106, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 489, .adv_w = 121, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 497, .adv_w = 116, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 503, .adv_w = 74, .box_w = 4, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 508, .adv_w = 121, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 516, .adv_w = 125, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 524, .adv_w = 55, .box_w = 1, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 526, .adv_w = 55, .box_w = 3, .box_h = 12, .ofs_x = -1, .ofs_y = -2},
    {.bitmap_index = 531, .adv_w = 109, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 539, .adv_w = 65, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 543, .adv_w = 188, .box_w = 9, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 551, .adv_w = 123, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 557, .adv_w = 125, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 564, .adv_w = 122, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 572, .adv_w = 122, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 580, .adv_w = 78, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 584, .adv_w = 93, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 589, .adv_w = 84, .box_w = 4, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 594, .adv_w = 124, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 600, .adv_w = 107, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 607, .adv_w = 150, .box_w = 9, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 615, .adv_w = 103, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 621, .adv_w = 103, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 629, .adv_w = 101, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 635, .adv_w = 72, .box_w = 3, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 640, .adv_w = 54, .box_w = 1, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 642, .adv_w = 72, .box_w = 3, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 647, .adv_w = 136, .box_w = 7, .box_h = 2, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 649, .adv_w = 129, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 655, .adv_w = 133, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 662, .adv_w = 136, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 669, .adv_w = 135, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 676, .adv_w = 136, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 683, .adv_w = 143, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 691, .adv_w = 102, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 696, .adv_w = 125, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 702, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 709, .adv_w = 136, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 718, .adv_w = 138, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 727, .adv_w = 181, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 736, .adv_w = 186, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 751, .adv_w = 137, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 762, .adv_w = 137, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 773, .adv_w = 121, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 784, .adv_w = 159, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 793, .adv_w = 186, .box_w = 10, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 803, .adv_w = 186, .box_w = 10, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 813, .adv_w = 133, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 820, .adv_w = 136, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 828, .adv_w = 130, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 834, .adv_w = 147, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 842, .adv_w = 121, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 849, .adv_w = 143, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 857, .adv_w = 144, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 865, .adv_w = 147, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 876, .adv_w = 139, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 883, .adv_w = 139, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 893, .adv_w = 161, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 902, .adv_w = 161, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 915, .adv_w = 138, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 923, .adv_w = 138, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 930, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 936, .adv_w = 108, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 942, .adv_w = 130, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 951, .adv_w = 130, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 958, .adv_w = 137, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 969, .adv_w = 115, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 975, .adv_w = 135, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 982, .adv_w = 152, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 991, .adv_w = 130, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 998, .adv_w = 142, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1006, .adv_w = 161, .box_w = 10, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1018, .adv_w = 131, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1025, .adv_w = 127, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1032, .adv_w = 122, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1038, .adv_w = 120, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1044, .adv_w = 0, .box_w = 6, .box_h = 3, .ofs_x = -5, .ofs_y = 9},
    {.bitmap_index = 1047, .adv_w = 109, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1052, .adv_w = 109, .box_w = 9, .box_h = 12, .ofs_x = -3, .ofs_y = 0},
    {.bitmap_index = 1066, .adv_w = 0, .box_w = 6, .box_h = 4, .ofs_x = -7, .ofs_y = 9},
    {.bitmap_index = 1069, .adv_w = 0, .box_w = 6, .box_h = 4, .ofs_x = -7, .ofs_y = 9},
    {.bitmap_index = 1072, .adv_w = 0, .box_w = 7, .box_h = 4, .ofs_x = -7, .ofs_y = 9},
    {.bitmap_index = 1076, .adv_w = 0, .box_w = 7, .box_h = 5, .ofs_x = -8, .ofs_y = 9},
    {.bitmap_index = 1081, .adv_w = 0, .box_w = 3, .box_h = 4, .ofs_x = -4, .ofs_y = -5},
    {.bitmap_index = 1083, .adv_w = 0, .box_w = 5, .box_h = 4, .ofs_x = -6, .ofs_y = -5},
    {.bitmap_index = 1086, .adv_w = 0, .box_w = 1, .box_h = 1, .ofs_x = -2, .ofs_y = -2},
    {.bitmap_index = 1087, .adv_w = 132, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1096, .adv_w = 69, .box_w = 3, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1099, .adv_w = 130, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1106, .adv_w = 85, .box_w = 6, .box_h = 13, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 1116, .adv_w = 85, .box_w = 6, .box_h = 13, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 1126, .adv_w = 87, .box_w = 6, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1136, .adv_w = 66, .box_w = 5, .box_h = 12, .ofs_x = -2, .ofs_y = -4},
    {.bitmap_index = 1144, .adv_w = 139, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1153, .adv_w = 0, .box_w = 6, .box_h = 5, .ofs_x = -7, .ofs_y = 9},
    {.bitmap_index = 1157, .adv_w = 0, .box_w = 1, .box_h = 3, .ofs_x = -2, .ofs_y = 9},
    {.bitmap_index = 1158, .adv_w = 0, .box_w = 5, .box_h = 4, .ofs_x = -5, .ofs_y = 9},
    {.bitmap_index = 1161, .adv_w = 0, .box_w = 7, .box_h = 4, .ofs_x = -6, .ofs_y = 9},
    {.bitmap_index = 1165, .adv_w = 0, .box_w = 3, .box_h = 3, .ofs_x = -3, .ofs_y = 9},
    {.bitmap_index = 1167, .adv_w = 0, .box_w = 4, .box_h = 4, .ofs_x = -4, .ofs_y = 9},
    {.bitmap_index = 1169, .adv_w = 0, .box_w = 3, .box_h = 3, .ofs_x = -3, .ofs_y = 9},
    {.bitmap_index = 1171, .adv_w = 0, .box_w = 4, .box_h = 4, .ofs_x = -4, .ofs_y = 9},
    {.bitmap_index = 1173, .adv_w = 139, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1180, .adv_w = 148, .box_w = 8, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1186, .adv_w = 151, .box_w = 8, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1192, .adv_w = 153, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1201, .adv_w = 155, .box_w = 8, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1207, .adv_w = 152, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1218, .adv_w = 152, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1229, .adv_w = 151, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1237, .adv_w = 167, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1248, .adv_w = 151, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1257, .adv_w = 155, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1268, .adv_w = 172, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1277, .adv_w = 228, .box_w = 13, .box_h = 7, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0xd
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 0, .range_length = 14, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 2, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    },
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 3,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 3585, .range_length = 58, .glyph_id_start = 98,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 3647, .range_length = 29, .glyph_id_start = 156,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    15, 55,
    15, 57,
    15, 60,
    15, 71,
    15, 74,
    15, 82,
    15, 84,
    15, 89,
    15, 90,
    17, 55,
    17, 57,
    17, 60,
    17, 71,
    17, 74,
    17, 82,
    17, 84,
    17, 89,
    17, 90,
    36, 38,
    36, 50,
    36, 52,
    36, 54,
    36, 55,
    36, 56,
    36, 57,
    36, 58,
    36, 60,
    36, 68,
    36, 70,
    36, 71,
    36, 72,
    36, 74,
    36, 82,
    36, 84,
    36, 88,
    36, 89,
    36, 92,
    37, 36,
    37, 57,
    37, 59,
    37, 60,
    39, 36,
    39, 57,
    39, 60,
    41, 15,
    41, 17,
    41, 36,
    41, 45,
    46, 68,
    46, 70,
    46, 71,
    46, 72,
    46, 74,
    46, 84,
    46, 92,
    47, 38,
    47, 42,
    47, 50,
    47, 52,
    47, 55,
    47, 56,
    47, 57,
    47, 58,
    47, 60,
    47, 68,
    47, 70,
    47, 71,
    47, 72,
    47, 74,
    47, 82,
    47, 84,
    47, 87,
    47, 89,
    47, 90,
    47, 92,
    50, 36,
    50, 57,
    50, 58,
    50, 59,
    50, 60,
    51, 15,
    51, 17,
    51, 36,
    51, 45,
    51, 57,
    51, 59,
    51, 60,
    51, 68,
    51, 70,
    51, 71,
    51, 74,
    51, 82,
    51, 84,
    51, 86,
    52, 36,
    52, 57,
    52, 58,
    52, 59,
    52, 60,
    54, 36,
    54, 57,
    54, 60,
    55, 15,
    55, 17,
    55, 36,
    55, 38,
    55, 68,
    55, 70,
    55, 71,
    55, 72,
    55, 74,
    55, 80,
    55, 81,
    55, 82,
    55, 84,
    55, 86,
    55, 88,
    55, 89,
    55, 90,
    55, 91,
    55, 92,
    55, 93,
    56, 15,
    56, 17,
    56, 36,
    57, 15,
    57, 17,
    57, 36,
    57, 38,
    57, 42,
    57, 45,
    57, 50,
    57, 52,
    57, 54,
    57, 68,
    57, 70,
    57, 71,
    57, 72,
    57, 74,
    57, 77,
    57, 80,
    57, 81,
    57, 82,
    57, 83,
    57, 84,
    57, 86,
    57, 88,
    57, 89,
    57, 91,
    57, 92,
    58, 15,
    58, 17,
    58, 36,
    58, 50,
    58, 52,
    58, 68,
    58, 70,
    58, 71,
    58, 72,
    58, 74,
    58, 82,
    58, 84,
    59, 38,
    59, 42,
    59, 50,
    59, 52,
    59, 68,
    59, 70,
    59, 71,
    59, 72,
    59, 74,
    59, 82,
    59, 84,
    59, 88,
    59, 89,
    59, 92,
    60, 15,
    60, 17,
    60, 36,
    60, 38,
    60, 42,
    60, 45,
    60, 50,
    60, 52,
    60, 54,
    60, 68,
    60, 70,
    60, 71,
    60, 72,
    60, 74,
    60, 80,
    60, 81,
    60, 82,
    60, 84,
    60, 86,
    60, 88,
    60, 89,
    60, 91,
    60, 92,
    61, 70,
    61, 71,
    61, 72,
    61, 74,
    61, 82,
    61, 84,
    68, 57,
    68, 60,
    69, 15,
    69, 17,
    69, 57,
    69, 60,
    69, 92,
    70, 57,
    70, 60,
    72, 15,
    72, 17,
    72, 36,
    72, 57,
    72, 59,
    72, 60,
    72, 86,
    72, 89,
    72, 92,
    73, 15,
    73, 17,
    73, 68,
    73, 70,
    73, 71,
    73, 72,
    73, 74,
    73, 82,
    73, 84,
    74, 57,
    74, 60,
    78, 55,
    78, 57,
    78, 60,
    78, 68,
    78, 70,
    78, 71,
    78, 72,
    78, 74,
    78, 82,
    78, 84,
    78, 92,
    79, 70,
    79, 71,
    79, 72,
    79, 74,
    79, 82,
    79, 84,
    79, 86,
    79, 89,
    79, 90,
    79, 92,
    80, 55,
    80, 57,
    80, 60,
    81, 55,
    81, 57,
    81, 60,
    82, 15,
    82, 17,
    82, 36,
    82, 55,
    82, 57,
    82, 60,
    82, 89,
    82, 92,
    83, 15,
    83, 17,
    83, 55,
    83, 57,
    83, 58,
    83, 59,
    83, 89,
    83, 92,
    85, 15,
    85, 17,
    85, 82,
    86, 17,
    86, 55,
    86, 57,
    86, 59,
    86, 60,
    86, 72,
    87, 82,
    88, 55,
    88, 57,
    88, 60,
    89, 15,
    89, 17,
    89, 36,
    89, 55,
    89, 57,
    89, 59,
    89, 60,
    89, 68,
    89, 70,
    89, 71,
    89, 72,
    89, 74,
    89, 82,
    89, 84,
    91, 55,
    91, 57,
    91, 60,
    91, 71,
    91, 74,
    91, 84,
    92, 15,
    92, 17,
    92, 36,
    92, 55,
    92, 59,
    92, 60,
    92, 68,
    92, 71,
    92, 72,
    92, 74,
    92, 82,
    92, 84,
    93, 55,
    93, 57,
    93, 60
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -22, -22, -22, -7, -7, -7, -7, -13,
    -13, -22, -22, -22, -7, -7, -7, -7,
    -13, -13, -7, -7, -7, -9, -13, -13,
    -11, -7, -13, -7, -7, -7, -7, -7,
    -7, -7, -9, -9, -9, -4, -7, -9,
    -9, -9, -13, -11, -22, -22, -22, -20,
    -7, -4, -4, -4, -4, -4, -9, -7,
    -7, -11, -11, -25, -7, -22, -18, -22,
    -4, -4, -4, -4, -4, -4, -4, -7,
    -13, -9, -18, -7, -7, -2, -9, -9,
    -22, -22, -18, -22, -7, -13, -7, -7,
    -7, -7, -7, -7, -7, -4, -7, -7,
    -2, -9, -9, -7, -7, -7, -22, -22,
    -13, -9, -18, -13, -18, -18, -18, -13,
    -13, -18, -18, -16, -13, -13, -9, -11,
    -9, -11, -9, -9, -13, -22, -22, -11,
    -9, -9, -16, -7, -7, -7, -18, -18,
    -18, -18, -18, -18, -11, -11, -13, -11,
    -18, -11, -11, -13, -11, -11, -18, -18,
    -7, -2, -2, -4, -4, -4, -4, -4,
    -4, -4, -9, -7, -9, -9, -11, -7,
    -7, -9, -7, -7, -7, -7, -11, -16,
    -22, -22, -13, -11, -13, -16, -9, -9,
    -7, -13, -13, -13, -13, -13, -13, -13,
    -13, -13, -13, -13, -13, -18, -13, -4,
    -4, -4, -4, -4, -4, -13, -18, -7,
    -7, -18, -18, -4, -9, -13, -7, -7,
    -9, -18, -11, -18, 4, -7, -4, -13,
    -13, -9, -9, -9, -7, -9, -9, -9,
    -9, -13, -13, -20, -13, -9, -9, -9,
    -4, -9, -4, -9, -7, -4, -4, -7,
    -4, -7, -4, -4, -7, -4, -7, -13,
    -16, -18, -13, -16, -18, -7, -7, -9,
    -13, -13, -16, -2, -2, -7, -7, -13,
    -13, -13, -11, -4, -2, -13, -13, -2,
    -7, -13, -11, -9, -13, 4, -7, -18,
    -11, -13, -13, -13, -22, -9, -13, -11,
    -13, -7, -7, -4, -4, -4, -2, -4,
    -9, -11, -18, -7, -7, -7, -9, -9,
    -18, -9, -13, -13, -7, -2, -2, -2,
    -2, -2, -4, -9, -9
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 325,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 4,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};

extern const lv_font_t lv_font_montserrat_14;


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t Sarabun = {
#else
lv_font_t Sarabun = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 19,          /*The maximum line height required by the font*/
    .base_line = 5,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = &lv_font_montserrat_14,
#endif
    .user_data = NULL,
};



#endif /*#if SARABUN*/

