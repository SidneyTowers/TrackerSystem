/*----------------------------------------------------------------------------*\
| MotorDC.cpp                                                                  |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#include <iostream>
#include "GenericMotor.h"

// Class for use with an DC motor as the physical GenericMotor
//  to move the physical InputDevice.
class MotorDC: public GenericMotor {
  public:
	// Returns the position of the motor.
	int getPosition() {
		// method stub
		std::cout << "MotorDC Called" << std::endl;
	}
	
	// Sets the position of the motor to the requested position.
	void setPosition(int New) {
		// method stub
		std::cout << "MotorDC Set" << std::endl;
		Position = New;
	}
};
