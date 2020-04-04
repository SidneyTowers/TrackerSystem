/*----------------------------------------------------------------------------*\
| Display.h                                                                    |
|                                                                              |
|                                                                              |
| March 14, 2020        Created document framework.                            |
\*----------------------------------------------------------------------------*/

#ifndef _DISPLAY_H_
#define _DISPLAY_H_


#include <vector>
#include <cstdint>
#include "Pixel.h"

// A logical representation of a 2-dimentional
// pixel array (or image) for use with the Camera.
class Display {
public:
	// Constructor for display that creates a matrix of pixels with multiple
	//     color channels (display resolution with B, BA, RGB, or RGBA)
	Display(const unsigned char * NewData, uint16_t Width, uint16_t Height, uint8_t Depth);

	// Constructor which copies the passed in display and duplicates it
	Display(const Display& DisplayToCopy);

	// Destructor for display (memory leak preventions)
	~Display();

	// Returns a copy of the wanted pixel's values on all four channels
	Pixel At(uint16_t X, uint16_t Y);

//private:
	// Basic information about the image including the starting pointer to its data
	int Rows = -1;
	int Columns = -1;
	int Channels = -1;
	unsigned char * Data = nullptr;
};

#endif // _DISPLAY_H_

