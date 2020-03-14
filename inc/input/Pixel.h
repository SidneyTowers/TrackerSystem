/*----------------------------------------------------------------------------*\
| Pixel.h                                                                      |
|                                                                              |
|                                                                              |
| March 14, 2020        Created document framework.                            |
\*----------------------------------------------------------------------------*/

#ifndef _PIXEL_H_
#define _PIXEL_H_

// A logical representation of a 4-channel RGBA pixel for use
//  with the Camera.
class Pixel {
  public:
	// The red, green, blue and alpha channels of the pixel.
	unsigned char RedChannel;
	unsigned char GreenChannel;
	unsigned char BlueChannel;
	unsigned char AlphaChannel;
};

#endif // _PIXEL_H_
