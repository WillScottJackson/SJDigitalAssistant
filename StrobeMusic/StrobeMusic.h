/*
 * StrobeMusic.h
 *
 *  Created on: 24 May 2013
 *      Author: Will
 */

#ifndef STROBEMUSIC_H_
#define STROBEMUSIC_H_

#define lowVolume 0b00011000
#define midVolume 0b0010010000011000
#define highVolume 0b0110011000011000
#define veryHighVolume 0b1110011100011000

int strobeMusic[9] = {

		0b00000000,
		0b00011000,
		0b0010010000011000,
		0b0110011000011000,
		0b1110011100011000,
		0b0110011000011000,
		0b0010010000011000,
		0b00011000,
		0b00000000
};



#endif /* STROBEMUSIC_H_ */
