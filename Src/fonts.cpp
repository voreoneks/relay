﻿#include "fonts.h"

static const unsigned char Font7x9_EN[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // space
	0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00, 0x10, 0x00,  // !
	0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // "
	0x24, 0x24, 0x7E, 0x24, 0x24, 0x7E, 0x24, 0x24, 0x00,  // #
	0x10, 0x38, 0x54, 0x50, 0x38, 0x54, 0x54, 0x38, 0x10,  // $
	0x20, 0x54, 0x58, 0x30, 0x28, 0x54, 0x14, 0x08, 0x00,  // %
	0x10, 0x28, 0x28, 0x10, 0x34, 0x48, 0x48, 0x34, 0x00,  // &
	0x10, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // '
	0x08, 0x10, 0x20, 0x20, 0x20, 0x20, 0x10, 0x08, 0x00,  // (
	0x20, 0x10, 0x08, 0x08, 0x08, 0x08, 0x10, 0x20, 0x00,  // )
	0x10, 0x38, 0x10, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00,  // *
	0x00, 0x00, 0x10, 0x10, 0x7C, 0x10, 0x10, 0x00, 0x00,  // +
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x20,  // ,
	0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00,  // -
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00,  // .
	0x08, 0x08, 0x10, 0x10, 0x10, 0x10, 0x20, 0x20, 0x00,  // /
	0x38, 0x44, 0x44, 0x54, 0x44, 0x44, 0x44, 0x38, 0x00,  // 0
	0x10, 0x30, 0x50, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00,  // 1
	0x38, 0x44, 0x44, 0x04, 0x08, 0x10, 0x20, 0x7C, 0x00,  // 2
	0x38, 0x44, 0x04, 0x18, 0x04, 0x04, 0x44, 0x38, 0x00,  // 3
	0x08, 0x18, 0x28, 0x28, 0x48, 0x7C, 0x08, 0x08, 0x00,  // 4
	0x7C, 0x40, 0x40, 0x78, 0x04, 0x04, 0x44, 0x38, 0x00,  // 5
	0x38, 0x44, 0x40, 0x78, 0x44, 0x44, 0x44, 0x38, 0x00,  // 6
	0x7C, 0x04, 0x08, 0x10, 0x10, 0x20, 0x20, 0x20, 0x00,  // 7
	0x38, 0x44, 0x44, 0x38, 0x44, 0x44, 0x44, 0x38, 0x00,  // 8
	0x38, 0x44, 0x44, 0x44, 0x3C, 0x04, 0x44, 0x38, 0x00,  // 9
	0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00,  // :
	0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x10, 0x20,  // ;
	0x00, 0x00, 0x0C, 0x30, 0x40, 0x30, 0x0C, 0x00, 0x00,  // <
	0x00, 0x00, 0x00, 0x7C, 0x00, 0x7C, 0x00, 0x00, 0x00,  // =
	0x00, 0x00, 0x60, 0x18, 0x04, 0x18, 0x60, 0x00, 0x00,  // >
	0x38, 0x44, 0x04, 0x08, 0x10, 0x10, 0x00, 0x10, 0x00,  // ?
	0x38, 0x44, 0x4C, 0x54, 0x5C, 0x40, 0x40, 0x38, 0x00,  // @
	0x10, 0x28, 0x28, 0x28, 0x28, 0x7C, 0x44, 0x44, 0x00,  // A
	0x78, 0x44, 0x44, 0x78, 0x44, 0x44, 0x44, 0x78, 0x00,  // B
	0x38, 0x44, 0x40, 0x40, 0x40, 0x40, 0x44, 0x38, 0x00,  // C
	0x70, 0x48, 0x44, 0x44, 0x44, 0x44, 0x48, 0x70, 0x00,  // D
	0x7C, 0x40, 0x40, 0x7C, 0x40, 0x40, 0x40, 0x7C, 0x00,  // E
	0x7C, 0x40, 0x40, 0x78, 0x40, 0x40, 0x40, 0x40, 0x00,  // F
	0x38, 0x44, 0x40, 0x40, 0x5C, 0x44, 0x44, 0x38, 0x00,  // G
	0x44, 0x44, 0x44, 0x7C, 0x44, 0x44, 0x44, 0x44, 0x00,  // H
	0x38, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x38, 0x00,  // I
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x44, 0x38, 0x00,  // J
	0x44, 0x48, 0x50, 0x60, 0x50, 0x48, 0x48, 0x44, 0x00,  // K
	0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x7C, 0x00,  // L
	0x44, 0x6C, 0x6C, 0x54, 0x44, 0x44, 0x44, 0x44, 0x00,  // M
	0x44, 0x64, 0x64, 0x54, 0x54, 0x4C, 0x4C, 0x44, 0x00,  // N
	0x38, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x38, 0x00,  // O

	0x78, 0x44, 0x44, 0x44, 0x78, 0x40, 0x40, 0x40, 0x00,  // P
	0x38, 0x44, 0x44, 0x44, 0x44, 0x44, 0x54, 0x38, 0x04,  // Q
	0x78, 0x44, 0x44, 0x44, 0x78, 0x48, 0x48, 0x44, 0x00,  // R
	0x38, 0x44, 0x40, 0x30, 0x08, 0x04, 0x44, 0x38, 0x00,  // S
	0x7C, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00,  // T
	0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x38, 0x00,  // U
	0x44, 0x44, 0x44, 0x28, 0x28, 0x28, 0x10, 0x10, 0x00,  // V
	0x44, 0x44, 0x54, 0x54, 0x54, 0x6C, 0x28, 0x28, 0x00,  // W
	0x44, 0x28, 0x28, 0x10, 0x10, 0x28, 0x28, 0x44, 0x00,  // X
	0x44, 0x44, 0x28, 0x28, 0x10, 0x10, 0x10, 0x10, 0x00,  // Y
	0x7C, 0x04, 0x08, 0x10, 0x10, 0x20, 0x40, 0x7C, 0x00,  // Z
	0x00, 0x00, 0x00, 0x36, 0x49, 0x36, 0x00, 0x00, 0x00,  // [Infinity]
//	0x18, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x18, 0x00,  // [
//	0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x00,  // \ //
//	0x30, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x30, 0x00,  // ]
//	0x10, 0x28, 0x28, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00,  // ^
//	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x00,  // _
//	0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // `
//	0x00, 0x00, 0x38, 0x44, 0x3C, 0x44, 0x4C, 0x34, 0x00,  // a
//	0x40, 0x40, 0x58, 0x64, 0x44, 0x44, 0x64, 0x58, 0x00,  // b
//	0x00, 0x00, 0x38, 0x44, 0x40, 0x40, 0x44, 0x38, 0x00,  // c
//	0x04, 0x04, 0x34, 0x4C, 0x44, 0x44, 0x4C, 0x34, 0x00,  // d
//	0x00, 0x00, 0x38, 0x44, 0x7C, 0x40, 0x44, 0x38, 0x00,  // e
//	0x0C, 0x10, 0x7C, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00,  // f
//	0x00, 0x00, 0x34, 0x4C, 0x44, 0x4C, 0x34, 0x04, 0x78,  // g
//	0x40, 0x40, 0x58, 0x64, 0x44, 0x44, 0x44, 0x44, 0x00,  // h
//	0x10, 0x00, 0x70, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00,  // i
//	0x10, 0x00, 0x70, 0x10, 0x10, 0x10, 0x10, 0x10, 0xE0,  // j
//	0x40, 0x40, 0x48, 0x50, 0x60, 0x50, 0x48, 0x44, 0x00,  // k
//	0x70, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00,  // l
//	0x00, 0x00, 0x78, 0x54, 0x54, 0x54, 0x54, 0x54, 0x00,  // m
//	0x00, 0x00, 0x58, 0x64, 0x44, 0x44, 0x44, 0x44, 0x00,  // n
//	0x00, 0x00, 0x38, 0x44, 0x44, 0x44, 0x44, 0x38, 0x00,  // o
//	0x00, 0x00, 0x58, 0x64, 0x44, 0x64, 0x58, 0x40, 0x40,  // p
//	0x00, 0x00, 0x34, 0x4C, 0x44, 0x4C, 0x34, 0x04, 0x04,  // q
//	0x00, 0x00, 0x58, 0x64, 0x40, 0x40, 0x40, 0x40, 0x00,  // r
//	0x00, 0x00, 0x38, 0x44, 0x30, 0x08, 0x44, 0x38, 0x00,  // s
//	0x20, 0x20, 0x78, 0x20, 0x20, 0x20, 0x20, 0x18, 0x00,  // t
//	0x00, 0x00, 0x44, 0x44, 0x44, 0x44, 0x4C, 0x34, 0x00,  // u
//	0x00, 0x00, 0x44, 0x44, 0x28, 0x28, 0x28, 0x10, 0x00,  // v
//	0x00, 0x00, 0x54, 0x54, 0x54, 0x6C, 0x28, 0x28, 0x00,  // w
//	0x00, 0x00, 0x44, 0x28, 0x10, 0x10, 0x28, 0x44, 0x00,  // x
//	0x00, 0x00, 0x44, 0x44, 0x28, 0x28, 0x10, 0x10, 0x60,  // y
//	0x00, 0x00, 0x7C, 0x08, 0x10, 0x20, 0x40, 0x7C, 0x00,  // z
//	0x18, 0x10, 0x10, 0x20, 0x20, 0x10, 0x10, 0x18, 0x00,  // {
//	0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00,  // |
//	0x30, 0x10, 0x10, 0x08, 0x08, 0x10, 0x10, 0x30, 0x00,  // }
//	0x00, 0x00, 0x00, 0x32, 0x4C, 0x00, 0x00, 0x00, 0x00,  // ~
};

static const unsigned char Font7x9_RU[] = {
		
	0x10, 0x28, 0x28, 0x28, 0x28, 0x7C, 0x44, 0x44, 0x00,  // À
	0x78, 0x40, 0x40, 0x78, 0x44, 0x44, 0x44, 0x78, 0x00,  // Á
	0x78, 0x44, 0x44, 0x78, 0x44, 0x44, 0x44, 0x78, 0x00,  // Â
	0x7C, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00,  // Ã
	0x1C, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x7E, 0x42,  // Ä
	0x7C, 0x40, 0x40, 0x78, 0x40, 0x40, 0x40, 0x7C, 0x00,  // Å
	0x54, 0x54, 0x38, 0x38, 0x10, 0x38, 0x54, 0x54, 0x00,  // Æ
	0x78, 0x44, 0x04, 0x18, 0x04, 0x04, 0x04, 0x78, 0x00,  // Ç
	0x44, 0x4C, 0x4C, 0x54, 0x54, 0x64, 0x64, 0x44, 0x00,  // È
	0x54, 0x4C, 0x4C, 0x54, 0x54, 0x64, 0x64, 0x44, 0x00,  // É
	0x44, 0x48, 0x50, 0x60, 0x50, 0x48, 0x48, 0x44, 0x00,  // Ê
	0x1C, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x44, 0x00,  // Ë 
	0x44, 0x6C, 0x6C, 0x54, 0x44, 0x44, 0x44, 0x44, 0x00,  // Ì
	0x44, 0x44, 0x44, 0x7C, 0x44, 0x44, 0x44, 0x44, 0x00,  // Í
	0x38, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x38, 0x00,  // Î
	0x7C, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x00,  // Ï
	0x78, 0x44, 0x44, 0x44, 0x78, 0x40, 0x40, 0x40, 0x00,  // Ð
	0x38, 0x44, 0x40, 0x40, 0x40, 0x40, 0x44, 0x38, 0x00,  // Ñ
	0x7C, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00,  // Ò
	0x44, 0x44, 0x28, 0x28, 0x10, 0x10, 0x20, 0x60, 0x00,  // Ó
	0x10, 0x38, 0x54, 0x54, 0x54, 0x54, 0x38, 0x10, 0x00,  // Ô
	0x44, 0x28, 0x28, 0x10, 0x10, 0x28, 0x28, 0x44, 0x00,  // Õ
	0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x7C, 0x04,  // Ö
	0x44, 0x44, 0x44, 0x44, 0x3C, 0x04, 0x04, 0x04, 0x00,  // × 
	0x44, 0x44, 0x54, 0x54, 0x54, 0x54, 0x54, 0x7C, 0x00,  // Ø 
	0x44, 0x44, 0x54, 0x54, 0x54, 0x54, 0x54, 0x7E, 0x02,  // Ù
	0x60, 0x20, 0x20, 0x38, 0x24, 0x24, 0x24, 0x38, 0x00,  // Ú 
	0x42, 0x42, 0x42, 0x72, 0x4A, 0x4A, 0x4A, 0x72, 0x00,  // Û 
	0x40, 0x40, 0x40, 0x78, 0x44, 0x44, 0x44, 0x78, 0x00,  // Ü 
	0x38, 0x44, 0x04, 0x1C, 0x04, 0x04, 0x44, 0x38, 0x00,  // Ý
	0x4C, 0x52, 0x52, 0x72, 0x52, 0x52, 0x52, 0x4C, 0x00,  // Þ
	0x3C, 0x44, 0x44, 0x44, 0x3C, 0x24, 0x24, 0x44, 0x00,  // ß
};

static const uint16_t Font16x26[] = {
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Space
	0x03E0,0x03C0,0x01C0,0x39CE,0x3FFF,0x3F7F,0x0320,0x0370,0x07F8,0x0F78,0x1F3C,0x0638,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [*]
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x3FFE,0x3FFE,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [-]
	0x0000,0x0000,0x0000,0x7FF0,0x7FFC,0x787E,0x781F,0x781F,0x780F,0x780F,0x780F,0x780F,0x780F,
	0x780F,0x780F,0x780F,0x781F,0x781E,0x787E,0x7FF8,0x7FE0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [D]
	0x0000,0x0000,0x0000,0x3E00,0x3E00,0x3E00,0x3E00,0x3E00,0x3E00,0x3E00,0x3E00,0x3E00,0x3E00,
	0x3E00,0x3E00,0x3E00,0x3E00,0x3E00,0x3E00,0x3FFF,0x3FFF,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [L]
	0x07F0,0x0FF8,0x1F7C,0x3E3E,0x3C1E,0x7C1F,0x7C1F,0x780F,0x780F,0x780F,0x780F,0x780F,0x780F,
	0x780F,0x7C1F,0x7C1F,0x3C1E,0x3E3E,0x1F7C,0x0FF8,0x07F0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [0]
	0x00F0,0x07F0,0x3FF0,0x3FF0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,
	0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x01F0,0x3FFF,0x3FFF,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [1]
	0x0FE0,0x3FF8,0x3C7C,0x003C,0x003E,0x003E,0x003E,0x003C,0x003C,0x007C,0x00F8,0x01F0,0x03E0,
	0x07C0,0x0780,0x0F00,0x1E00,0x3E00,0x3C00,0x3FFE,0x3FFE,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [2]
	0x0FF0,0x1FF8,0x1C7C,0x003E,0x003E,0x003E,0x003C,0x003C,0x00F8,0x0FF0,0x0FF8,0x007C,0x003E,
	0x001E,0x001E,0x001E,0x001E,0x003E,0x1C7C,0x1FF8,0x1FE0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [3]
	0x0078,0x00F8,0x00F8,0x01F8,0x03F8,0x07F8,0x07F8,0x0F78,0x1E78,0x1E78,0x3C78,0x7878,0x7878,
	0xFFFF,0xFFFF,0x0078,0x0078,0x0078,0x0078,0x0078,0x0078,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [4]
	0x1FFC,0x1FFC,0x1FFC,0x1E00,0x1E00,0x1E00,0x1E00,0x1E00,0x1FE0,0x1FF8,0x00FC,0x007C,0x003E,
	0x003E,0x001E,0x003E,0x003E,0x003C,0x1C7C,0x1FF8,0x1FE0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [5]
	0x01FC,0x07FE,0x0F8E,0x1F00,0x1E00,0x3E00,0x3C00,0x3C00,0x3DF8,0x3FFC,0x7F3E,0x7E1F,0x3C0F,
	0x3C0F,0x3C0F,0x3C0F,0x3E0F,0x1E1F,0x1F3E,0x0FFC,0x03F0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [6]
	0x3FFF,0x3FFF,0x3FFF,0x000F,0x001E,0x001E,0x003C,0x0038,0x0078,0x00F0,0x00F0,0x01E0,0x01E0,
	0x03C0,0x03C0,0x0780,0x0F80,0x0F80,0x0F00,0x1F00,0x1F00,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [7]
	0x07F8,0x0FFC,0x1F3E,0x1E1E,0x3E1E,0x3E1E,0x1E1E,0x1F3C,0x0FF8,0x07F0,0x0FF8,0x1EFC,0x3E3E,
	0x3C1F,0x7C1F,0x7C0F,0x7C0F,0x3C1F,0x3F3E,0x1FFC,0x07F0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [8]
	0x07F0,0x0FF8,0x1E7C,0x3C3E,0x3C1E,0x7C1F,0x7C1F,0x7C1F,0x7C1F,0x3C1F,0x3E3F,0x1FFF,0x07EF,
	0x001F,0x001E,0x001E,0x003E,0x003C,0x38F8,0x3FF0,0x1FE0,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [9]
	
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x1E3C,0x3F7E,0x73E7,0x61C3,
	0x61C3,0x73E7,0x3F7E,0x1E3C,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000  //  Ascii = [infinity]
};

FontDef_16Bit Font_16x26 = { 16, 26, Font16x26 };
FontDef_8Bit Font_7x9 = {7, 9, Font7x9_EN, Font7x9_RU};