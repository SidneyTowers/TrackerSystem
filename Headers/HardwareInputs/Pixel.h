/*----------------------------------------------------------------------------*\
| Pixel.h                                                                      |
|                                                                              |
|                                                                              |
| March 14, 2020        Created document framework.                            |
\*----------------------------------------------------------------------------*/

#ifndef _PIXEL_H_
#define _PIXEL_H_


// A logical representation of a 4-channel RGBA pixel for use
//     with the Camera class
class Pixel {
protected:
	// The red, green, blue and alpha channels of the pixel
	unsigned char Channels[4] = {255, 255, 255, 255};

	// 
	unsigned char ChannelAmount = 0;

public:
	// 
	Pixel(unsigned char * DataPointer, unsigned long int DataCountStart, unsigned char ChannelCount);

	// 
	unsigned char GetRedChannel();

	// 
	unsigned char GetBlueChannel();

	// 
	unsigned char GetGreenChannel();

	// 
	unsigned char GetAlphaChannel();
};

#endif // _PIXEL_H_

