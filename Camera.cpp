/*----------------------------------------------------------------------------*\
| Camera.cpp                                                                   |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#include <iostream>
#include "InputDevice.cpp"

// Class for use with a physical camera as an InputDevice.
class Camera: public InputDevice {
  public:
	// Constructor for Camera class.
	Camera() {
		// method stub
		std::cout << "Camera created" << std::endl;
	}
	
	// Returns the value polled from the Camera.
	int getValue() {
		// method stub
	}
};
