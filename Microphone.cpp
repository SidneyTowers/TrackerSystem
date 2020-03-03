/*----------------------------------------------------------------------------*\
| Microphone.cpp                                                               |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#include <iostream>
#include "InputDevice.cpp"

// Class for use with a physical microphone as an InputDevice.
class Microphone: public InputDevice {
  public:
	// Constructor for Microphone class.
	Microphone() {
		// method stub
		std::cout << "Microphone created" << std::endl;
	}
	
	// Returns the value polled from the Microphone.
	int getValue() {
		// method stub
	}
};
