/*----------------------------------------------------------------------------*\
| Pixel.cpp                                                                    |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

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
