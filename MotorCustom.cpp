/*----------------------------------------------------------------------------*\
| MotorCustom.cpp                                                              |
|                                                                              |
|                                                                              |
| Febuary 18, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#include <iostream>
#include "GenericMotor.h"

// Class for use with a stepper motor as the physical GenericMotor
//  to move the physical InputDevice.
class MotorCustom : public GenericMotor {
public:
	// Returns the position of the motor.
	int getPosition() {
		// method stub
		std::cout << "MotorCustom Called" << std::endl;
	}

	// Sets the position of the motor to the requested position.
	void setPosition(int New) {
		// method stub
		std::cout << "MotorCustom Set" << std::endl;
		Position = New;
	}
};
