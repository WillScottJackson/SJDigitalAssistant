/*
 * StrobePattern.h
 * This header contains an array of bytes which will serve
 * as the strobe pattern on the JY-LKM1638. The LEDs will
 * strobe in the pattern defined when a humanoid or cat
 * enters a room and is spotted by the motion sensor
 * By William Scott-Jackson
 */

#ifndef STROBEPATTERN_H_
#define STROBEPATTERN_H_

byte strobePattern[] = {
		0b10000000,
		0b01000000,
		0b00100000,
		0b00010000,
		0b00001000,
		0b00000100,
		0b00000010,
		0b00000001,
		0b00000010,
		0b00000100,
		0b00001000,
		0b00010000,
		0b00100000,
		0b01000000,
		0b10000000,

		0b10000000,
		0b01000000,
		0b00100000,
		0b00010000,
		0b00001000,
		0b00000100,
		0b00000010,
		0b00000001,
		0b00000010,
		0b00000100,
		0b00001000,
		0b00010000,
		0b00100000,
		0b01000000,
		0b10000000,

		0b11111111,
		0b00000000,

		0b11111111,
		0b00000000,

		0b10000001,
		0b01000010,
		0b00100100,
		0b00011000,
		0b00100100,
		0b01000010,
		0b10000001,

		0b10000001,
		0b01000010,
		0b00100100,
		0b00011000,
		0b00100100,
		0b01000010,
		0b10000001,

		0b10000001,
		0b11000011,
		0b11100111,
		0b11111111,
		0b01111110,
		0b00111100,
		0b00011000,
		0b00000000,

		0b10000001,
		0b11000011,
		0b11100111,
		0b11111111,
		0b01111110,
		0b00111100,
		0b00011000,
		0b00000000
};


#endif /* STROBEPATTERN_H_ */
