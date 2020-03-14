/*----------------------------------------------------------------------------*\
| Display.cpp                                                                  |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#include <vector>
#include "../inc/Display.h"

Display::Display(unsigned int width, unsigned int height) {
	ImageMatrix.resize(height);
	for (unsigned int HeightCounter; HeightCounter < height; ++HeightCounter) {
		ImageMatrix.at(HeightCounter).resize(width);
	}
}
