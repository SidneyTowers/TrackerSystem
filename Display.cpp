/*----------------------------------------------------------------------------*\
| Display.cpp                                                                  |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/


#include <vector>
#include "Pixel.cpp"

// A logical representation of a 2-dimentional
// pixel array (or image) for use with the Camera.
class Display {
public:
	// 
	Display(unsigned int width, unsigned int height) {
		ImageMatrix.resize(height);
		for (unsigned int HeightCounter; HeightCounter < height; ++HeightCounter) {
			ImageMatrix.at(HeightCounter).resize(width);
		}
	}

	// The image retrieved from a Camera input (to access = ImageMatrix.at(wanted_height/y).at(wanted_width/x)).
	std::vector<std::vector<Pixel>> ImageMatrix;
};
