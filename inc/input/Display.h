/*----------------------------------------------------------------------------*\
| Display.h                                                                    |
|                                                                              |
|                                                                              |
| March 14, 2020        Created document framework.                            |
\*----------------------------------------------------------------------------*/

#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <vector>
#include "Pixel.h"

// A logical representation of a 2-dimentional
// pixel array (or image) for use with the Camera.
class Display {
public:
	// 
	Display(unsigned int width, unsigned int height);

	// The image retrieved from a Camera input (to access = ImageMatrix.at(wanted_height/y).at(wanted_width/x)).
	std::vector<std::vector<Pixel>> ImageMatrix;
};

#endif // _DISPLAY_H_
